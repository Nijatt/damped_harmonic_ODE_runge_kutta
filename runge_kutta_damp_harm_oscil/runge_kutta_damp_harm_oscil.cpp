
#include "oscillator.h"
#include <iostream>

using namespace std;

int main()
{
	double t_initial;
	double delta_t;
	double t_final;


	double u;
	double y;

	double k1, k2, k3, k4;
	double l1, l2, l3, l4;

	// Equation Constants
	double K = 1;
	double M = 1;
	double C = 1;

	//initial state
	u = 3;
	y = 5;

	// time variables
	delta_t = 0.01;
	t_initial = 0.0;
	t_final = 300;



	//writing into the cvs file.
	ofstream fout("OUTCAR_Damped_harm.cvs");
	if (!fout) {
		cout << "\n Error" << endl;
	}

	// scientific precision
	fout << scientific;
	fout.precision(8);

	fout << "# Time: " << " , " << " dy/dt " << " , " << " y " << " , " << "\n";



	while (t_initial <= t_final) {


		// Runge-Kutta Computation
	
		k1 = dudt(u, y,K,M,C);
		l1 = dydt(u);

		k2 = dudt(u,y+delta_t/2*l1,K,M,C);
		l2 = dydt(u+delta_t/2*k1);

		k3 = dudt(u, y + delta_t / 2 * l2,K, M, C);
		l3 = dydt(u + delta_t / 2 * k2);

		k4 = dudt(u, y + delta_t * l3, K, M, C);
		l4 = dydt(u + delta_t * k3);

		//update domains
		u = u + (delta_t / 6)*(k1 + 2*k2 + 3*k3 + k4);
		y = y + (delta_t / 6)*(l1 + 2 * l2 + 3 * l3 + l4);


		// write into the csv file.
		fout << t_initial << " , " << u << " , " << y << " , " << "\n";

		// update current time
		t_initial += delta_t;


	}


	cout << "Program has completed successfully. Please, check output files." << endl;

	cout << "Final time: " << t_initial << endl;

	system("pause");
}
