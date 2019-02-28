#include <iostream>
using namespace std;

#define exp 2.71828
#define pi 3.14159
#define a (-2./3.)*3.14
#define b (3./4.)*3.14
#define N 50
double step = (b - a) / N;

double func(double x) {
	return 1/(pow(exp,(pow(x,2))));
}

// Quadrature Formulas Of Rectangles:

double quadratureLeftRectangles() {
	return (b - a)*func(a);
}
double quadratureRightRectangles() {
	return (b - a)*func(b);
}
double quadratureRectangles() {
	return (b - a)*func((b + a) / 2.);
}

// Quadrature Formulas Of Trapezium:

double quadratureTrapezium() {
	return ((b -a) / 2.)*(func(a) + func(b));
}

// Simpson's Formulas:

double quadratureSimpson() {
	return ((b - a) / 6.)*(func(a) + 4 * func((a + b) / 2.) + func(b));
}

// Compound Left Rectangles:

double compoundLeftRectangles() {
	double integralLeftRectangles = 0.;
for (int i = 1; i <= N; i++) {
		integralLeftRectangles = integralLeftRectangles + func(a + (i - 1)*step);
	}
	return integralLeftRectangles = step*integralLeftRectangles;
}

// Compound Right Rectangles:

double compoundRightRectangles() {
	double integralRightRectangles = 0.;
for (int i = 1; i <= N; i++) {
		integralRightRectangles = integralRightRectangles + func(a+step + (i - 1)*step);
	}
	return integralRightRectangles = step*integralRightRectangles;
}

// Compound Rectangles:

double compoundRectangles() {
	double integralRectangles = 0.;
	for (int i = 1; i <= N; i++) {
		integralRectangles = integralRectangles + func(a + (step/2.) + (i - 1)*step);
	}
	return integralRectangles = step*integralRectangles;
}

double compoundTrapezium() {
	double integralTrapezium = 0.;
//	double tmp = 0.;
	for (int i = 1; i <= N; i++) {
		integralTrapezium += ((func(a+i*step)+func(a+(1+i)*step))/2.)*step;
	}
	//integralTrapezium = ((b - abs(a)) / (2.*N))*(func(0.) + 2. * tmp + func(N));
	return integralTrapezium;
}

double compoundSimpson() {
	double integralSimpson = 0.;

	double tmp_0 = 0.;
	double tmp_1 = 0.;

	for (int i = 1; i < N; i+=2) {
		tmp_1 += func(a + i*step);
	}
	for (int i = 2; i < N-1; i+=2) {
		tmp_0 += func(a + i*step);
	}

	integralSimpson += (step / 3.)*(func(0)+2*tmp_0+4*tmp_1+func(N));
	return integralSimpson;
}
