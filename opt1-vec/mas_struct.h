#include<iostream>
#include"class_Subbody.h"
#include<fstream>
#include<vector>
#include <cmath>
void simulation_mas_struct(Subbody* mas, size_t n, double t_0, double t_end, double BIG_G, double dt) {
    double t = t_0;
    std::vector<double> f0(n);
    std::vector<double> f1(n);
    std::vector<double> f2(n);
    while (t < t_end) {
for(int z=0;z<n;z++){
f0[z]=0;
f1[z]=0;
f2[z]=0;
}
        for (int j = 0; j < n; j++) {
#pragma ivdep
#pragma vector always
            for (int i = 0; i < n; i++) {
                if (i != j) {
                    double l0 = mas[i].x - mas[j].x;
                    double l1 = mas[i].y - mas[j].y;
                    double l2 = mas[i].z - mas[j].z;
                    double l = l0 * l0 + l1 * l1 + l2 * l2;
                    double line_m = sqrt(l);

                    double acceleration = (-1.0) * BIG_G * mas[j].m * mas[i].m / l;
                    f0[i] += l0 / line_m * acceleration;
                    f1[i] += l1 / line_m * acceleration;
                    f2[i] += l2 / line_m * acceleration;

                }
            }

        }

#pragma ivdep
#pragma vector always

        for (int k = 0; k < n; k++) {
            mas[k].x += mas[k].vx * dt;
            mas[k].y += mas[k].vy * dt;
            mas[k].z += mas[k].vz * dt;

            mas[k].vx += f0[k] / mas[k].m * dt;
            mas[k].vy += f1[k] / mas[k].m * dt;
            mas[k].vz += f2[k] / mas[k].m * dt;
        }
                t += dt;
    }
   }