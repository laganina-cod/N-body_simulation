#include<iostream>
#include"mas_struct.h"
#include"class_Subbody.h"
#include<fstream>

void simulation_mas_struct(Subbody* mas, size_t n, double t_0, double t_end, double BIG_G, double dt) {
    std::ofstream file;
    file.open("result_file.csv");
    file << "x" << ";" << "y" << ";" << "z" << ";" << endl;
    if (file.is_open()) {
        std::cout << "was open";
    }
    double t = t_0;
    while (t < t_end) {
        for (size_t i = 0; i < n; i++) {
            std::vector<double> f(3,0);
            for (size_t j = 0; j < n; j++) {
                if (j != i) {
                    std::vector<double> line(3, 0);
                    line[0] = mas[i].cord[0] - mas[j].cord[0];
                    line[1] = mas[i].cord[1] - mas[j].cord[1];
                    line[2] = mas[i].cord[2] - mas[j].cord[2];
                    double line_m = sqrt(line[0] * line[0] + line[1] * line[1] + line[2] * line[2]);

                    double acceleration = ( - 1.0 )*BIG_G * mas[j].m * mas[i].m / (line[0] * line[0] + line[1] * line[1] + line[2] * line[2]);
                    f[0] += line[0]/line_m * acceleration;
                    f[1] += line[1]/line_m * acceleration;
                    f[2] += line[2]/line_m * acceleration;

                }
            }
           
           

            mas[i].cord[0] += mas[i].v[0] * dt;
            mas[i].cord[1] += mas[i].v[1] * dt;
            mas[i].cord[2] += mas[i].v[2] * dt;

            mas[i].v[0] += f[0] / mas[i].m * dt;
            mas[i].v[1] += f[1] / mas[i].m * dt;
            mas[i].v[2] += f[2] / mas[i].m * dt;
            //std::cout << "coordinates of body number" << k  << ":" << std::endl;
            //std::cout << "x:" << orbital_entities[k].cord.cor[0] << "  " << "y:" << orbital_entities[k].cord.cor[1] << "  " << "z:" << orbital_entities[k].cord.cor[2] << "  " << std::endl;




            

        }
        int s = static_cast<int>((t - t_0) / dt);

        
        if (s%100000==0) {
            file << mas[1].cord[0] << ";" << mas[1].cord[1] << ";" << mas[1].cord[2] << ";" << endl;
        }
        t += dt;
    }
    file.close();
}