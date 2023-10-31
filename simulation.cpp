#pragma once
#include"struct_component.h"
#include<iostream>

void simulation(Subbody* mas, size_t n,double t_0,double t_end,double BIG_G,double dt) {
    double t = t_0;
    while (t < t_end) {
        for (size_t i = 0; i < n; i++) {
            Vector3 f(0, 0, 0);//не замедляется ли от приведения типов код?
            for (size_t j = 0; j < n; j++) {
                if (j != i) {
                    Vector3 line(0, 0, 0);
                    line.cor[0] = mas[i].e[0] - mas[j].e[0];
                    line.cor[1] = mas[i].e[1] - mas[j].e[1];
                    line.cor[2] = mas[i].e[2] - mas[j].e[2];
                    double line_m = sqrt(line.cor[0] * line.cor[0] + line.cor[1] * line.cor[1] + line.cor[2] * line.cor[2]);//не теряется ли точность если извлечь корень так, а не из степени 3? можно ли избежать вызова функции?

                    double acceleration = -1.0 * BIG_G * mas[j].e[6] / (line.cor[0] * line.cor[0] + line.cor[1] * line.cor[1] + line.cor[2] * line.cor[2]);
                    line.cor[0] = (line.cor[0] / line_m) * acceleration;
                    line.cor[1] = (line.cor[1] / line_m) * acceleration;
                    line.cor[2] = (line.cor[2] / line_m) * acceleration;
                    f.cor[0] += line.cor[0];
                    f.cor[1] += line.cor[1];
                    f.cor[2] += line.cor[2];

                }
            }
            mas[i].e[3] += f.cor[0] * dt;
            mas[i].e[4] += f.cor[1] * dt;
            mas[i].e[5] += f.cor[2] * dt;

        }
        for (size_t i = 0; i < n; i++)//зачем выносить этот цикл из первого?
        {
            mas[i].e[0] += mas[i].e[3] * dt;
            mas[i].e[1] += mas[i].e[4] * dt;
            mas[i].e[2] += mas[i].e[5] * dt;
        }
        t += dt;
    }
}