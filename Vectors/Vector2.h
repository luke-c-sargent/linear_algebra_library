#pragma once

#include <iostream>
#include <math.h>

namespace LAL
{

class Vector2
{
	double x = 0 ,y = 0;
public:
	Vector2(){}
	Vector2(double _x, double _y): x(_x), y(_y){}
	double get_x() const {return x;}
	double get_y() const {return y;}
	void set_x(double _x){x=_x;}
	void set_y(double _y){y=_y;}

	Vector2 operator +(const Vector2& v2) const {
		return Vector2(this->x + v2.get_x(), this->y + v2.get_y());
	}

	double magnitude(){
		return sqrt(x*x + y*y);
	}

	double normalize(){
		double mag = this->magnitude();
		if(mag != 0.0){
			x = x/mag;
			y = y/mag;
		}

	}

	bool operator == (const Vector2& v2) const {
		return (this->x == v2.get_x()) && (this->y == v2.get_y());
	}

	bool operator != (const Vector2& v2) const {
		return !(*this == v2);
	}

	friend std::ostream& operator << (std::ostream& os, const Vector2& v2);
	friend Vector2 operator * (double scalar, const Vector2& v2);
	Vector2 operator * (double scalar) const {
		return scalar*(*this);
	}

	Vector2 operator - () const {
		return -1*(*this);
	}

	Vector2 operator -(const Vector2& v2) const {
		return (*this) + (-v2);
	}
};

std::ostream& operator << (std::ostream& os, const Vector2& v2){
		os << "< " << v2.x << ", " << v2.y << " >"; 
}

Vector2 operator * (double scalar, const Vector2& v2){
	return Vector2(scalar*v2.x, scalar*v2.y);

}

}//end LAL namespace