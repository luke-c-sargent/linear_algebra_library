#pragma once

#include <iostream>

#include "../Vectors/Vector3.h"

namespace LAL
{

class Matrix3x3
{
	double x1 =0, y1=0, z1=0,
			x2 =0, y2=0, z2=0,
			x3 =0, y3=0, z3=0;
public:
	Matrix3x3(){}
	Matrix3x3(double _x1, double _y1, double _z1, 
				double _x2, double _y2, double _z2,
				double _x3, double _y3, double _z3):
				x1(_x1), y1(_y1), z1(_z1),
				x2(_x2), y2(_y2), z2(_z2),
				x3(_x3), y3(_y3), z3(_z3) {}
	Matrix3x3(Vector3 _row1, Vector3 _row2, Vector3 _row3){
		x1=_row1.get_x();	y1=_row1.get_y();	z1=_row1.get_z();
		x2=_row2.get_x();	y2=_row2.get_y();	z2=_row2.get_z();
		x3=_row3.get_x();	y3=_row3.get_y();	z3=_row3.get_z();
	}

	Vector3 get_row1() const { return Vector3(x1,y1,z1);}
	Vector3 get_row2() const { return Vector3(x2,y2,z2);}
	Vector3 get_row3() const { return Vector3(x3,y3,z3);}

	double get_x1() const { return x1; }
	double get_y1() const { return y1; }
	double get_z1() const { return z1; }

	double get_x2() const { return x2; }
	double get_y2() const { return y2; }
	double get_z2() const { return z2; }

	double get_x3() const { return x3; }
	double get_y3() const { return y3; }
	double get_z3() const { return z3; }

	void set_row1(Vector3 _r1) {
		x1 = _r1.get_x();	y1 = _r1.get_y();	z1 = _r1.get_z();	
	}

	void set_row2(Vector3 _r2) {
		x2 = _r2.get_x();	y2 = _r2.get_y();	z2 = _r2.get_z();	
	}

	void set_row3(Vector3 _r3) {
		x3 = _r3.get_x();	y3 = _r3.get_y();	z3 = _r3.get_z();	
	}

	void set_x1(double _x1){ x1=_x1;}
	void set_y1(double _y1){ y1=_y1;}
	void set_z1(double _z1){ z1=_z1;}

	void set_x2(double _x2){ x2=_x2;}
	void set_y2(double _y2){ y2=_y2;}
	void set_z2(double _z2){ z2=_z2;}

	void set_x3(double _x3){ x3=_x3;}
	void set_y3(double _y3){ y3=_y3;}
	void set_z3(double _z3){ z3=_z3;}


	// operators
	bool operator == (const Matrix3x3& m3x3) const {
		return (x1 == m3x3.get_x1()) &&
				(y1 == m3x3.get_y1()) &&
				(z1 == m3x3.get_z1()) &&
				(x2 == m3x3.get_x2()) &&
				(y2 == m3x3.get_y2()) &&
				(z2 == m3x3.get_z2()) &&
				(x3 == m3x3.get_x3()) &&
				(y3 == m3x3.get_y3()) &&
				(z3 == m3x3.get_z3());
	}

	bool operator != (const Matrix3x3& m3x3) const {
		return !(*this == m3x3);
	}
};

std::ostream& operator << (std::ostream& os, const Matrix3x3& m);

} // end namespace LAL