
#pragma once

class Subbody
{
public:
    double x, y, z, vx, vy, vz, m;
    Subbody();
    Subbody(double _x, double _y, double _z, double _vx, double _vy, double _vz, double _m);
};
inline Subbody::Subbody() {
    m = 0.0;
    x = 0.0;
    y = 0.0;
    z = 0.0;
    vx = 0.0;
    vy = 0.0;
    vz = 0.0;
}
inline Subbody::Subbody(double _x, double _y, double _z, double _vx, double _vy, double _vz, double _m) {
    x = _x;
    y = _y;
    z = _z;
    vx = _vx;
    vy = _vy;
    vz = _vz;
    m = _m;
}