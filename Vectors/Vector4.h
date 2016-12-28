#pragma once

#include <math.h>
#include <iostream>

namespace LAL
{
class Vector4
{
	double x = 0, y = 0, z = 0, w = 0;
public:
	Vector4(){}
	Vector4(double _x, double _y, double _z, double _w): x(_x), y(_y), z(_z), w(_w){}
/*	double x(){return x;}
	double y(){return y;}
	double z(){return z;}
	double w(){return w;}*/
};
}