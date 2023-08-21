// aew9409_HW3_Q3.cpp : This program takes entry of three varables from a user and calculates
//  the slutions of a quadratic equation. 
//

#include <iostream>
#include <cmath>

using namespace std;

int main()

{
	double a, b, c;

	cout << "Please enter value of a: ";
	cin >> a;
	cout << "Please enter value of b: ";
	cin >> b;
	cout << "Please enter value of c: ";
	cin >> c;

	cout << a << endl;
	if (a == 0) { // Not a quadratic equation.
		cout << "in zero case" << endl;
		if (b == 0) {
			if (c == 0) {
				cout << "This equation has infinite number of solutions." << endl;
			}
			else {
				cout << "The equation has no solution." << endl;
			}
		}
		else { 
			double linear_solution = -b / c;
			cout << "The equation has a single real solution x= " << linear_solution;	
		}

	}

	else {
		cout << a << endl;
		double solution_check = b * b - 4 * a * c;
		double one_solution = -b / (2 * a);

		if (solution_check < 0) {
			cout << "The equation has no real solution." << endl;
		}
		else if (solution_check > 0) {
			double solution_one = (-b + sqrt(solution_check)) / (2 * a);
			double solution_two = (-b - sqrt(solution_check)) / (2 * a);
			cout << "This equation has two real solutions x1= " << solution_one << " and x2= " << solution_two << endl;
		}	/* I added a "1" and "2" to the output of x for both the solutions so the user could
			asily read that both outputs where different solutions. */

		else if (solution_check == 0) {
			double one_solution = -b / (2 * a);
			cout << "This equation has a single solution x=" << one_solution << endl;
		}
	}
	return 0;
}

