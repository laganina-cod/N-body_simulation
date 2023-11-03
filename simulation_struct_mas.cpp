#include "mas_component.h"
#include"simulatuon_struct_mas.h"
void simulation_struct_mas(Mas_Subbodies  masb, double t_0, double t_end, double BIG_G, double dt) {
    double t = t_0;
    while (t < t_end) {
        for (size_t i = 0; i < masb.n; i++) {
            Vector3 f(0, 0, 0);//не замедляется ли от приведения типов код?
            for (size_t j = 0; j < masb.n; j++) {
                if (j != i) {
                    Vector3 line(0, 0, 0);
                    line.cor[0] = masb.e_0[i] - masb.e_0[j];
                    line.cor[1] = masb.e_1[i] - masb.e_1[j];
                    line.cor[2] = masb.e_2[i] - masb.e_2[j];
                    double line_m = sqrt(line.cor[0] * line.cor[0] + line.cor[1] * line.cor[1] + line.cor[2] * line.cor[2]);//не теряется ли точность если извлечь корень так, а не из степени 3? можно ли избежать вызова функции?

                    double acceleration = -1.0 * BIG_G * masb.e_6[j] / (line.cor[0] * line.cor[0] + line.cor[1] * line.cor[1] + line.cor[2] * line.cor[2]);
                    line.cor[0] = (line.cor[0] / line_m) * acceleration;
                    line.cor[1] = (line.cor[1] / line_m) * acceleration;
                    line.cor[2] = (line.cor[2] / line_m) * acceleration;
                    f.cor[0] += line.cor[0];
                    f.cor[1] += line.cor[1];
                    f.cor[2] += line.cor[2];

                }
            }
            masb.e_3[i] += f.cor[0] * dt;
            masb.e_4[i] += f.cor[1] * dt;
            masb.e_5[i] += f.cor[2] * dt;

        }
        for (size_t i = 0; i < masb.n; i++)//зачем выносить этот цикл из первого?
        {
            masb.e_0[i] += masb.e_3[i] * dt;
            masb.e_1[i] += masb.e_4[i] * dt;
            masb.e_2[i] += masb.e_5[i] * dt;
        }
        t += dt;
        std::cout << "t:" << t << std::endl;
        for (size_t k = 0; k < masb.n; k++) {
            std::cout << "coordinates of body number" << k + 1 << ":" << std::endl;
            std::cout << "x:" << masb.e_0[k] << "  " << "y:" << masb.e_1[k] << "  " << "z:" << masb.e_2[k] << "  " << std::endl;
        }
    }
}