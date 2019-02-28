#include <iostream>
#include "f.h"
#include <iomanip>


using namespace std;

#define exp 2.71828182846
#define pi 3.14159265359
#define a (-2./3.)*3.14
#define b (3./4.)*3.14

#define analyticIntegralValue 1.76898


int main() {

	cout << "Analytic Integral Value: "<< analyticIntegralValue<<'\n' << setw(36) << right << "Left Rectangles Formula: "<< quadratureLeftRectangles()<<'\n';
	cout << setw(36) << right << "Right Rectangles Formula: " << quadratureRightRectangles() << '\n' << setw(36) << right << "Standart Rectangles Formula: " << quadratureRectangles() << '\n';
	cout << setw(36) << right << "Trapezium Formula: " << quadratureTrapezium() << '\n' << setw(36) << right << "Simpson's Formula: " << quadratureSimpson() << '\n';

	
	cout << endl << endl;

	cout <<setw(36)<<right<< "Compound Left Rectangles Formulas: "<< compoundLeftRectangles()<<'\n';

	cout << setw(36) << right << "Compound Right Rectangles Formulas: " << compoundRightRectangles() << '\n';

	cout << setw(36) << right << "Compound Rectangles Formulas: " << compoundRectangles() << '\n';

	cout << setw(36) << right << "Compound Trapezium Formula: " << compoundTrapezium() << '\n';

	cout << setw(36) << right << "Compound Simpson Formula: " << compoundSimpson() << '\n';

	system("pause");
	return 0;
}