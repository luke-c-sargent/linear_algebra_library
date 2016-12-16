#include <math.h>
#include <iostream>

#include "Matrix3x3_Test.h"
#include "../Matrix3x3.h"
#include "../../Vectors/Vector3.h"
#include "../../test_utils.hpp"

using namespace LAL;

void test_matrix3x3(){
	std::cout << "Matrix3x3 Tests:" << std::endl;

	// default zero matrix, getters
	Matrix3x3 m;
	isequal(m.get_x1(), 0); isequal(m.get_y1(), 0); isequal(m.get_z1(), 0);
	isequal(m.get_x2(), 0); isequal(m.get_y2(), 0); isequal(m.get_z2(), 0);
	isequal(m.get_x3(), 0); isequal(m.get_y3(), 0); isequal(m.get_z3(), 0);

	// row getter
	Matrix3x3 rg;
	isequal(rg.get_row1(), Vector3());
	isequal(rg.get_row2(), Vector3());
	isequal(rg.get_row3(), Vector3());

	// row setters
	Matrix3x3 rs;
	rs.set_row1(Vector3(-1,-2,-3));
	rs.set_row2(Vector3(-4,-5,-6));
	rs.set_row3(Vector3(-7,-8,-9));
	isequal(rs.get_row1(), Vector3(-1,-2,-3));
	isequal(rs.get_row2(), Vector3(-4,-5,-6));
	isequal(rs.get_row3(), Vector3(-7,-8,-9));

	// double constructor
	Matrix3x3 dc(1,2,3,
				 4,5,6,
				 7,8,9);
	isequal(dc.get_row1(), Vector3(1,2,3));
	isequal(dc.get_row2(), Vector3(4,5,6));
	isequal(dc.get_row3(), Vector3(7,8,9));

	//stringify with output stream
	Matrix3x3 os(0,1,2,
				 3,4,5,
				 6,7,8);
	isequal(stringify(os), stringify("[[0, 1, 2],[3, 4, 5],[6, 7, 8]]"));

	//equality and inequality
	Matrix3x3 eq1(10,20,30,
				  40,50,60,
				  70,80,90);
	Matrix3x3 eq2(10,20,30,
				  40,50,60,
				  70,80,90);
	Matrix3x3 neq(3,1,4,
				  1,5,9,
				  2,6,5);
	isequal(eq1 == eq2, true);
	isequal(eq1 != eq2, false);
	isequal(eq1 != neq, true);

	// double setters
	Matrix3x3 ds;
	ds.set_x1(6);	ds.set_y1(6);	ds.set_z1(6);
	ds.set_x2(6);	ds.set_y2(6);	ds.set_z2(6);
	ds.set_x3(6);	ds.set_y3(6);	ds.set_z3(6);
	isequal(ds, Matrix3x3(6,6,6,
						  6,6,6,
						  6,6,6));

	// addition
	Matrix3x3 add1(-5,-5,-5,
				   -5,-5,-5,
				   -5,-5,-5);
	Matrix3x3 add2(1,2,3,
				   4,5,6,
				   7,8,9);
	isequal(add1+add2, Matrix3x3(-4,-3,-2,
								 -1, 0, 1,
								  2, 3, 4));

	// square matrix product
	Matrix3x3 mp1(1,2,3,
				  4,5,6,
				  7,8,9);
	Matrix3x3 mp2(3,2,1,
				  6,5,4,
				  9,8,7);
	// solution values from wolframalpha
	isequal(mp1*mp2, Matrix3x3(42,36,30,
							   96,81,66,
							   150,126,102));
	isequal(mp2*mp1, Matrix3x3(18,24,30,
							   54,69,84,
							   90,114,138));

	//unary negation
	Matrix3x3 uneg(0,1,1,
				   2,3,5,
				   8,13,21);
	isequal(-uneg, Matrix3x3(0,-1,-1,
							 -2,-3,-5,
							 -8,-13,-21));

	// scalar multiplication
	Matrix3x3 mult(1,2,3,
			  	   4,5,6,
			  	   7,8,9);
	Matrix3x3 twice_mult(2,4,6,
						 8,10,12,
						 14,16,18);
	isequal(mult*2, twice_mult);
	isequal(2*mult, twice_mult);

	// transpose
	Matrix3x3 pre_tp(1,2,3,
					 4,5,6,
					 7,8,9);
	Matrix3x3 tp(1,4,7,
				 2,5,8,
				 3,6,9);
	isequal(pre_tp.get_transpose(),tp);

	std::cout << "[END Matrix3x3 Tests-----------------------------------]\n" << std::endl;
}