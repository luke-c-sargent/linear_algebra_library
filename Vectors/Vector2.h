#pragma once

#include <iostream>
#include <math.h>

namespace LAL
{

class Vector2
{
	double x = 0 ,y = 0;
public:
	// constructors
	Vector2(){}
	Vector2(double _x, double _y): x(_x), y(_y){}
	// getters
	double get_x() const {return x;}
	double get_y() const {return y;}
	// setters
	void set_x(double _x){x=_x;}
	void set_y(double _y){y=_y;}

	// mathematical operations
	double magnitude() const {
		return sqrt(x*x + y*y);
	}

	// convert the vector to its unit vector, return the magnitude
	double normalize(){
		double mag = this->magnitude();
		if(mag != 0.0){
			x = x/mag;
			y = y/mag;
		}
		return mag;
	}

	Vector2 unit_vector() const {
		Vector2 copy(x,y);
		copy.normalize();
		return copy;
	}

	double dot_product(const Vector2& v2) const {
		return this->x * v2.get_x() + this->y * v2.get_y();
	}

	// operators
	Vector2 operator +(const Vector2& v2) const {
		return Vector2(this->x + v2.get_x(), this->y + v2.get_y());
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

// get the planar angle of the two vectors (vectors from origin to point defined by v2s)
double planar_angle(const Vector2 v2_a, const Vector2 v2_b) {
	double dot_p = v2_a.dot_product(v2_b);
	double cos_a_eq = dot_p / (v2_a.magnitude() * v2_b.magnitude());
	return acos(cos_a_eq);
}

}//end LAL namespace