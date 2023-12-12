#pragma once
#pragma once
#include <vector>
using namespace::std;

class Subbody
{
    std::vector<double>cord;
    std::vector<double>v;
    double m;
public:
    Subbody();
    Subbody(double e0, double e1, double e2, double e3, double e4, double e5, double e6);
   friend void simulation_mas_struct(Subbody* mas, size_t n, double t_0, double t_end, double BIG_G, double dt);
};
