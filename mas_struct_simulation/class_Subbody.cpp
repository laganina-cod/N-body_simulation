#include"class_Subbody.h"
Subbody::Subbody() {
    m = 0.0;
    cord = std::vector<double>(3,0);
    v = std::vector<double>(3,0);
    

};
Subbody::Subbody(double e0, double e1, double e2, double e3, double e4, double e5, double e6){
    cord.resize(3);
    v.resize(3);
    cord[0] = e0;
    cord[1] = e1;
    cord[2] = e2;
    v[0] = e3;
    v[1] = e4;
    v[2] = e5;
    m = e6;
}