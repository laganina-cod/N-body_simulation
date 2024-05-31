#pragma once
#pragma once
#include<iostream>
#include"class_Subbody.h"
//#include<fstream>
#include<vector>
//#include <omp.h>
#include <cmath>
void simulation_mas_struct(Subbody* mas, size_t n, double t_0, double t_end, double BIG_G, double dt) {
    double t = t_0;
    std::vector<double> f0(n);
    std::vector<double> f1(n);
    std::vector<double> f2(n);
   // int size = (int)std::round(32768 / (sizeof(mas[1]) + sizeof(f0[1])));
    //size = size / 8;
    //int two_in_power = 2;
    //int power = 1;
    //while (two_in_power <= size) {
        //two_in_power *= 2;
           // power += 1;
    //}
    //power -= 1;
    //int block_size = pow(2,power);
int block_size =128;
    const int block_num = (n + block_size - 1) / block_size;

    while (t < t_end) {
        for (int z = 0; z < n; z++) {
            f0[z] = 0;
            f1[z] = 0;
            f2[z] = 0;
        }
        for (int bj = 0; bj < block_num; bj++) {
int block_size_1;
            if (bj==block_num -1){
            block_size_1=n-block_size*(block_num-1);
            }
            else{
            block_size_1=block_size;
            }

#pragma omp parallel for
            for (int bi = 0; bi < block_num; bi++) {
int block_size_1;

                if(bi==block_num -1){
               block_size_1=n-block_size*(block_num-1);
               }
               else{
            block_size_1=block_size;
            }


                for (int j = bj * block_size; j < bj * block_size + block_size_1; j++) {
#pragma ivdep
   
 #pragma vector always
                    for (int i = bi * block_size; i < bi * block_size + block_size_1; i++) {
   
                        if (i != j) {
                            double l0 = mas[i].x - mas[j].x;
                            double l1 = mas[i].y - mas[j].y;
                            double l2 = mas[i].z - mas[j].z;
                            double l = l0 * l0 + l1 * l1 + l2 * l2;
                            double line_m = sqrt(l);

                            double acceleration = (-1.0) * BIG_G * mas[j].m/ (l*line_m);
                            f0[i] += l0 * acceleration;
                            f1[i] += l1 * acceleration;
                            f2[i] += l2 * acceleration;

                        }
                    }

                }
            }
        }
        #pragma omp parallel for
        #pragma ivdep
        #pragma vector always

        for (int k = 0; k < n; k++) {
            mas[k].x += mas[k].vx * dt;
            mas[k].y += mas[k].vy * dt;
            mas[k].z += mas[k].vz * dt;

            mas[k].vx += f0[k] * dt;
            mas[k].vy += f1[k] * dt;
            mas[k].vz += f2[k] * dt;
        }
        t += dt;
    }
}