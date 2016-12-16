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
	Matrix3x3 dc(1,2,3,4,5,6,7,8,9);
	isequal(dc.get_row1(), Vector3(1,2,3));
	isequal(dc.get_row2(), Vector3(4,5,6));
	isequal(dc.get_row3(), Vector3(7,8,9));

	//stringify with output stream
	Matrix3x3 os(0,1,2,3,4,5,6,7,8);
	isequal(stringify(os), stringify("[[0, 1, 2],[3, 4, 5],[6, 7, 8]]"));

	//equality and inequality
	Matrix3x3 eq1(10,20,30,40,50,60,70,80,90);
	Matrix3x3 eq2(10,20,30,40,50,60,70,80,90);
	Matrix3x3 neq(3,1,4,1,5,9,2,6,5);
	isequal(eq1 == eq2, true);
	isequal(eq1 != eq2, false);
	isequal(eq1 != neq, true);

	// double setters
	Matrix3x3 ds;
	ds.set_x1(6);	ds.set_y1(6);	ds.set_z1(6);
	ds.set_x2(6);	ds.set_y2(6);	ds.set_z2(6);
	ds.set_x3(6);	ds.set_y3(6);	ds.set_z3(6);
	isequal(ds, Matrix3x3(6,6,6,6,6,6,6,6,6));

	std::cout << "[END Matrix3x3 Tests-----------------------------------]\n" << std::endl;
}