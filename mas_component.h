#include<iostream>
using namespace::std;
struct Mas_Subbodies {
	size_t n;
	double* e_0;
	double* e_1;
	double* e_2;
	double* e_3;
	double* e_4;
	double* e_5;
	double* e_6;
};
struct Vector3 {
	double cor[3] = { 0 };
	Vector3() {};
	~Vector3() {};
	inline Vector3(double _x, double _y, double _z) {
		this->cor[0] = _x;
		this->cor[1] = _y;
		this->cor[2] = _z;
	}

};