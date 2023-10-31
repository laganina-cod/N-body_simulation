#pragma once
struct Vector3 {
    double cor[3] = { 0 };
    Vector3() {};
    ~Vector3() {};
    inline Vector3(double _x, double _y, double _z) {
        this->cor[0] = _x;
        this->cor[1] = _y;
        this->cor[2] = _z;
    }

};//зачем делать структуру и не быстрее ли работать с массивом из трех коорд ?
struct Subbody
{
    double e[7] = { 0 };

    Subbody() {}
    ~Subbody() {}

    inline Subbody(double e0, double e1, double e2, double e3, double e4, double e5, double e6)
    {
        this->e[0] = e0;
        this->e[1] = e1;
        this->e[2] = e2;
        this->e[3] = e3;
        this->e[4] = e4;
        this->e[5] = e5;
        this->e[6] = e6;
    }
};