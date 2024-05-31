#include<iostream>
#include"class_Subbody.h"
#include<fstream>
#include<vector>
#include <cmath>



void simulation_mas_struct(Subbody* mas, size_t n, double t_0, double t_end, double BIG_G, double dt) {
    double t = t_0;
    while (t < t_end) {
        for (size_t i = 0; i < n; i++) {

		double f[3];

            for (size_t p = 0; p < 3; p++) {
                f[p] = 0;
            }
            for (size_t j = 0; j < n; j++) {
                if (j != i) {
			double line[3];
                    line[0] = mas[i].x - mas[j].x;
                    line[1] = mas[i].y - mas[j].y;
                    line[2] = mas[i].z - mas[j].z;
                    double line_m = sqrt(line[0] * line[0] + line[1] * line[1] + line[2] * line[2]);

                    double acceleration = (-1.0) * BIG_G * mas[j].m  / ((line[0] * line[0] + line[1] * line[1] + line[2] * line[2])*line_m);
                    f[0] += line[0] * acceleration;
                    f[1] += line[1] * acceleration;
                    f[2] += line[2] * acceleration;

                }
            }



            mas[i].x += mas[i].vx * dt;
            mas[i].y += mas[i].vy * dt;
            mas[i].z += mas[i].vz * dt;

            mas[i].vx += f[0] * dt;
            mas[i].vy += f[1] * dt;
            mas[i].vz += f[2] * dt;
            //std::cout << "coordinates of body number" << k  << ":" << std::endl;
            //std::cout << "x:" << orbital_entities[k].cord.cor[0] << "  " << "y:" << orbital_entities[k].cord.cor[1] << "  " << "z:" << orbital_entities[k].cord.cor[2] << "  " << std::endl;






        }
		t+=dt;
      }
   }