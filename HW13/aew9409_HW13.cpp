// aew9409_HW13.cpp : 
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>


using namespace std;
class Ant;
class Organism;
class Grid;

class Organism {
public:

	virtual bool isAnAnt()const { return false; }

	virtual void move(Grid& name, int x, int y) = 0;
	virtual ~Organism() {}
	void setLastMoved(int timeStep) { lastMoved = timeStep; }
	int getLastMove()const{return lastMoved;}
	void ageMe() { age++; }
	int getAge() { return age; }
	virtual bool timeToDie() { return false; }
	virtual bool timeToBreed() = 0;
	virtual Organism* breed() = 0;
	
	
	
private:
	int lastMoved = -1;
	int age = 0;
	
};
// 
class Ant : public Organism {
public:
	Ant(){}
	virtual bool isAnAnt()const { return true; }
	virtual void move(Grid& name, int x, int y);
	virtual bool timeToBreed() { return (getAge() != 0 && (getAge() % 3) == 0); }
	virtual Organism* breed();
private:
	
};

class Bug : public Organism {
public:
	
	Bug() { lastAte = getAge(); }
	virtual void move(Grid& name, int x, int y);
	virtual bool timeToDie() { return (getAge() - lastAte >= 3); }
	virtual bool timeToBreed() { return (getAge() != 0 && (getAge() % 8) == 0); }
	virtual Organism* breed();
	
private:
	int lastAte;
};

Organism* Ant::breed() { return new Ant; }
Organism* Bug::breed() { return new Bug; }

class Grid {
public:

	Grid() {
		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {
				store[x][y] = NULL; // set to NULL for the empty spaces


			}
		}
		
		
		int antCount = 0;
		while (antCount < 100) {
			int n = rand() % 20;
			int m = rand() % 20;
			if (store[n][m] == NULL) {
				store[n][m] = new Ant(); // do i need to clean up this memory with a distructor?

				antCount++;
			}


		}
		int bugCount = 0;
		while (bugCount < 5) {
			int n = rand() % 20;
			int m = rand() % 20;
			if (store[n][m] == NULL) {
				store[n][m] = new Bug(); // 

				bugCount++;
			}

		}
	}

	void moveOrganism(bool moveAnt);
	void moveAnts() { moveOrganism(true); }
	void moveBugs() { moveOrganism(false); }
	void breedOrDie();// looks like moveOrg, not moving ant breeding, bug check if it needs to die(deleting setting cell to 0. or breed. loop that ages organisms. << if age is 3 for ant or 8 for bug and there is a space,. check age to find out if breeding.
	void moveToSpace(int x, int y);
	void move(int x, int y, int resultx, int resulty);
	bool movedThisStep(const Organism* org)const { return (org->getLastMove() == timeStep); }
	int getTimeStep()const { return timeStep; }
	void updateTimeStep(int& timeStep) { this->timeStep = timeStep + 1; }
	bool findASpace(int x, int y, int& resultX, int& resultY);
	bool eatAnAnt(int x, int y);
	bool findAnAnt(int x, int y, int& resultX, int& resultY);
	void ageOrganisms();
	void printGrid();
	
	
 private:
	int spaces = 295;
	int bugs = 5;
	int ants = 100;
	int squaresLeft = 400;
	int timeStep = 0;
	
	Organism *store[20][20];
};
void Grid::ageOrganisms() {
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			if (store[x][y] != NULL) {
				store[x][y]->ageMe();
			}
			
		}
	}
}
void Grid::breedOrDie() {
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			if (store[x][y] != NULL) {
				if (store[x][y]->timeToDie()) {
					delete store[x][y];
					store[x][y] = NULL;
				}
				else if (store[x][y]->timeToBreed()) {
					int resultx;
					int resulty;
					if (findASpace(x, y, resultx, resulty)) {
						store[resultx][resulty] = store[x][y]->breed(); 
					}
				}
			}

			


		}
	}
	//cout << "Breed or Die!!" << endl;
}

void Grid::moveToSpace( int x, int y) {
	int resultx, resulty;
	if (findASpace(x, y, resultx, resulty) == true) {
		move(x, y, resultx, resulty);

	}
	
}
bool Grid::eatAnAnt(int x, int y) {
	

	int resultx, resulty;
	if (findAnAnt(x, y, resultx, resulty) == true) {
		delete store[resultx][resulty];
		move(x, y, resultx, resulty);
		
		return true;

	}
	return false;

}
void Grid:: printGrid() {
	updateTimeStep(timeStep);
	cout << timeStep << endl;
	int antCount = 0;
	int XCount = 0;
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			const Organism* org = store[x][y];

			if (store[x][y] == NULL) {
				cout << '-';
			}
			else if (store[x][y]->isAnAnt()) {
				cout << 'o';
				antCount++;
			}
			else {
				cout << 'X';
				XCount++;
			}

			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
	cout << XCount << endl;
	cout << antCount << endl;


}
void Grid::move(int x, int y, int resultx, int resulty) {
	
	store[resultx][resulty] = store[x][y];
	store[x][y] = NULL;
	store[resultx][resulty]->setLastMoved(timeStep); //memberfunction of grid
	
	

}
bool Grid::findAnAnt(int x, int y, int& resultX, int& resultY) {
	
	
		if (x > 0 && store[x - 1][y] && store[x-1][y]->isAnAnt()) {
			resultX = x - 1;
			resultY = y;
			return true;
		}
		if (x < 19 && store[x + 1][y] && store[x + 1][y]->isAnAnt()) {
			resultX = x + 1;
			resultY = y;
			return true;
		}
		if (y < 19 && store[x][y + 1] && store[x][y + 1]->isAnAnt()) {
			resultX = x;
			resultY = y + 1;
			return true;
		}
		if (y > 0 && store[x][y - 1] && store[x][y - 1]->isAnAnt()) {
			resultX = x;
			resultY = y - 1;
			return true;
		}
		return false;
	
	
	
}

bool Grid::findASpace(int x, int y, int& resultX, int& resultY){
	int direction = rand() % 4;
	if (direction == 1) {
		x = x - 1;
		if (x >= 0 && store[x][y] == NULL ) {
			resultX = x;
			resultY = y;
			return true;
		}
		else {
			return false;
		}
	}
	else if (direction == 2) {
		x = x + 1;
		if (x < 20 && store[x][y] == NULL) {
			resultX = x;
			resultY = y;
			return true;
		}
		else {
			return false;
		}

	}
	else if (direction == 3) {
		y = y - 1;
		if (y >= 0 && store[x][y] == NULL ) {
			resultX = x;
			resultY = y;
			return true;
		}
		else {
			return false;
		}

	}
	else {
		y = y + 1;
		if (y < 20 && store[x][y] == NULL) {
			resultX = x;
			resultY = y;

			return true;
		}
		else {
			return false;
		}

	}
}
void Ant::move(Grid& grid, int x, int y) {
	grid.moveToSpace(x, y);
	

		//cout << "Ant on the move" << endl;
}
void Grid::moveOrganism(bool moveAnt) {
	
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			Organism* org = store[x][y];
		
			
			
			if (org != NULL && org->isAnAnt() == moveAnt && !movedThisStep(org)) {// this needs to be false and need to be if it is an ant.
				
				org->move(*this, x, y);
			}
			// if org not null, and if ant and if it has not already moved. then moveAnt . orge->move(*this, x,y)
			//if 
			//need member function for the last cycletime step to ask if it has already moved.
			// same for bug.
			//breed is at organism level.
		}
	}
}
void Bug::move(Grid& grid, int x, int y) {
	//needs function to eat an ant else move to space.
	if (grid.eatAnAnt(x, y)) {
		lastAte = getAge();
	}
	else {
		grid.moveToSpace(x, y);
	}

	


	//cout << "Bug on the move" << endl;
}
int main()
{
	srand(time(NULL));
	
	Grid grid;
	
	
	grid.printGrid();
	
	string enter;
	cout << "Press enter to simulate next time step." << endl;
	getline(cin, enter);
	while (true) {

		grid.ageOrganisms();
		grid.moveAnts();
		
		grid.moveBugs();
		grid.breedOrDie();
		grid.printGrid();
		
		cout << "Press enter to simulate next time step." << endl;
		getline(cin, enter);
	}
	
	

	cout << endl;



	return 0;
}

