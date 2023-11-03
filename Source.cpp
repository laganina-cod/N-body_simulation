#include<iostream>
#include"struct_component.h"
#include"simulation_mas_struct.h"
//#include"simulatuon_struct_mas.h"
using namespace::std;
int main() {
	double t_0 = 0;
	double BIG_G = 6.67e-11;
	double dt = 86400;
	double t_end = 86400*365*10;
	int N_ASTEROIDS = 0;
	Subbody* orbital_entities = new Subbody[sizeof(Subbody) * (9 + N_ASTEROIDS)];
	
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
}


