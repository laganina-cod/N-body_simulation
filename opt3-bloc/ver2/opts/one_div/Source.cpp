#include<iostream>
#include<random>
#include <string>
#include <cmath>
#include<fstream>
#include <omp.h>
#include "mas_struct.h"
#include "class_Subbody.h"
//#include "simulatuon_struct_mas.h"
//#include "mas_component.h"
using namespace::std;
int main(int argc, char* argv[]) {
	double t_end = std::stod(argv[3]);
	int n = std::stoi(argv[2]);
	double dt = std::stod(argv[4]);
	int mode = std::stoi(argv[1]);
	double t_0 = 0;
	double BIG_G = 6.67e-11;

	if (mode == 1) {

		Subbody* orbital_entities = new Subbody[9];
		
		orbital_entities[0] = { 0.0,0.0,0.0,        0.0,0.0,0.0,      1.989e30 };   // a star similar to the sun
		orbital_entities[1] = { 57.909e9,0.0,0.0,   0.0,47.36e3,0.0,  0.33011e24 }; // a planet similar to mercury
		orbital_entities[2] = { 108.209e9,0.0,0.0,  0.0,35.02e3,0.0,  4.8675e24 };  // a planet similar to venus
		orbital_entities[3] = { 149.596e9,0.0,0.0,  0.0,29.78e3,0.0,  5.9724e24 };  // a planet similar to earth
		orbital_entities[4] = { 227.923e9,0.0,0.0,  0.0,24.07e3,0.0,  0.64171e24 }; // a planet similar to mars
		orbital_entities[5] = { 778.570e9,0.0,0.0,  0.0,13e3,0.0,     1898.19e24 }; // a planet similar to jupiter
		orbital_entities[6] = { 1433.529e9,0.0,0.0, 0.0,9.68e3,0.0,   568.34e24 };  // a planet similar to saturn
		orbital_entities[7] = { 2872.463e9,0.0,0.0, 0.0,6.80e3,0.0,   86.813e24 };  // a planet similar to uranus
		orbital_entities[8] = { 4495.060e9,0.0,0.0, 0.0,5.43e3,0.0,   102.413e24 }; // a planet similar to neptune
		simulation_mas_struct(orbital_entities, 9, t_0, t_end, BIG_G, dt);
		std::cout << "x:" << orbital_entities[1].x << "  " << "y:" << orbital_entities[1].y << "  " << "z:" << orbital_entities[1].z << "  " << std::endl;

		delete[] orbital_entities;
		orbital_entities = nullptr;
	}
else if(mode==3){
	    Subbody* orbital_entities = new Subbody[5];
		//t_end=0.0000785;
                //dt = 0.0785;
	   orbital_entities[0] = { 0.0,0.0,0.0, 0.0,0.0,0.0, 100000 };
	   orbital_entities[1] = { 0.001,0.0,0.0,  0.0,0.08,0.0,  1.0 };
           orbital_entities[2]=  {0.0,0.001,0.0,  -0.08,0.0,0.0,  1.0 };
           orbital_entities[3]=  {0.0,-0.001,0.0,  0.08,0.0,0.0,  1.0 };
           orbital_entities[4] = { -0.001,0.0,0.0,  0.0,-0.08,0.0,  1.0 };
	   simulation_mas_struct(orbital_entities, 5, t_0, t_end, BIG_G, dt);
		std::cout << "x:" << orbital_entities[1].x << "  " << "y:" << orbital_entities[1].y << "  " << "z:" << orbital_entities[1].z << "  " << std::endl;

		delete[] orbital_entities;
		orbital_entities = nullptr;
}

	else {
		Subbody* orbital_entities = new Subbody[n];
		std::ofstream file1;
		file1.open("result_time.csv", ios::app);
		//file1 << "n" << ";" << "y" << ";" << std::endl;
		for (int i = 0; i < n; i++) {
			orbital_entities[i] = Subbody((double)rand(), (double)rand(), (double)rand(), (double)rand(), (double)rand(), (double)rand(), (double)rand());
		}
		double t1 = omp_get_wtime();
		simulation_mas_struct(orbital_entities, n, t_0, t_end, BIG_G, dt);
		double t2 = omp_get_wtime();
		t2 -= t1;
		file1 << n << ";" << t2 << ";" << std::endl;
		delete[] orbital_entities;
		orbital_entities = nullptr;

	}
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

}