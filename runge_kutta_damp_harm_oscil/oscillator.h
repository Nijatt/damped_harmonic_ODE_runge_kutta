#pragma once

// Header file for Damped Harmonic Oscillator

#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;


/** Damped harmonic oscillator
	M*d^2 y(t)/dt^2 + C*dy(t)/dt + K*y(t) = 0

	lets prepare function for the numerical solution.

	dy(t)/dt = u(t)

	du(t)/dt = -K/M * y(t) - C/M * u(t)    =>    d^2 y(t)/dt^2 = du(t)/dt



*/



double dydt(double u);
double dudt(double y, double u, double K, double M, double C);

double dydt(double u) {
	return u;
}

double dudt(double u, double y, double K, double M, double C) {
	return(-C / M)*u + (-K / M)*y;
}




