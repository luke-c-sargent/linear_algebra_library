#pragma once

#include <math.h>
#include <iostream>

namespace LAL
{

class Vector3
{
	double x = 0, y = 0, z = 0;
public:
	Vector3(){}
	Vector3(double _x, double _y, double _z): x(_x), y(_y), z(_z){}

	// getters
	double get_x() const {return x;}
	double get_y() const {return y;}
	double get_z() const {return z;}
	
	// setters
	void set_x(double _x){x=_x;}
	void set_y(double _y){y=_y;}
	void set_z(double _z){z=_z;}

	// mathematical operations
	double magnitude() const {
		return sqrt(x*x + y*y + z*z);
	}

	// convert the vector to its unit vector, return the magnitude
	double normalize(){
		double mag = this->magnitude();
		// if not zero vector and not already normalized
		if(mag != 0.0 && mag !=1.0){
			x = x/mag;
			y = y/mag;
			z = z/mag;
		}
		return mag;
	}

	Vector3 unit_vector() const {
		Vector3 copy(x,y,z);
		copy.normalize();
		return copy;
	}

	double dot_product(const Vector3& v3) const {
		return this->x * v3.get_x() + this->y * v3.get_y() + this->z * v3.get_z();
	}

	Vector3 cross_product(const Vector3& v3) const {
		exit(1);
		// TODO
	}

	// operators
	friend std::ostream& operator << (std::ostream& os, const Vector3& v3);
	
	friend Vector3 operator * (double scalar, const Vector3& v3);


	Vector3 operator +(const Vector3& v3) const {
		return Vector3(this->x + v3.get_x(), this->y + v3.get_y(), this->z + v3.get_z());
	}

	bool operator == (const Vector3& v3) const {
		return (this->x == v3.get_x()) && (this->y == v3.get_y()) && (this->z == v3.get_z());
	}

	bool operator != (const Vector3& v3) const {
		return !(*this == v3);
	}

	Vector3 operator * (double scalar) const {
		return scalar*(*this);
	}

	Vector3 operator - () const {
		return -1*(*this);
	}

	Vector3 operator -(const Vector3& v3) const {
		return (*this) + (-v3);
	}

};

std::ostream& operator << (std::ostream& os, const Vector3& v3);

Vector3 operator * (double scalar, const Vector3& v3);

} // end namespace LAL