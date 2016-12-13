#pragma once

#include <math.h>
#include <iostream>

#include "Vector3_Test.h"
#include "../Vector3.h"
#include "../../test_utils.hpp"

using namespace LAL;

void test_vector3(){
	std::cout << "Vector3 Tests:" << std::endl;

	//default zero vector, getter functions
	Vector3 v3;
	isequal(v3.get_x(), 0.0);
	isequal(v3.get_y(), 0.0);
	isequal(v3.get_z(), 0.0);

	//basic constructor
	Vector3 v3_constr(-1,2,-3);
	isequal(v3_constr.get_x(), -1.0);
	isequal(v3_constr.get_y(), 2.0);
	isequal(v3_constr.get_z(), -3.0);
	
	//vector equality
	isequal(v3_constr == Vector3(-1,2,-3), true);

	//vector inequality
	isequal(v3_constr != Vector3(-1,2,-3), false);

	//setter functions
	Vector3 v3_set;
	v3_set.set_x(6);
	v3_set.set_y(6);
	v3_set.set_z(6);
	isequal(v3_set, Vector3(6,6,6));

	//addition operator
	isequal(Vector3(1,2,3)+Vector3(1,0,-1), Vector3(2,2,2));

	//stringify with output stream
	isequal(stringify(Vector3(7.0, 7.0, 7.0)), stringify("< 7, 7, 7 >"));

	// multiplication of scalar
	isequal(Vector3(1,2,3)*2.0, Vector3(2,4,6));
	// reverse multiplicand and multiplier
	isequal(3.0*Vector3(1,1,1), Vector3(3,3,3));

	//unary negation
	isequal(-Vector3(-10,10,-20), Vector3(10,-10,20));

	//subtraction
	isequal(Vector3(3,5,7)-Vector3(-2,0,2), Vector3(5,5,5));

	// magnitude
	isequal(Vector3().magnitude(), 0.0);
	isequal(Vector3(2,2,2).magnitude(), sqrt(12));

	// normalize vector
	Vector3 v3_norm(-3,5,56);
	double mag_from_fn = v3_norm.magnitude();
	double mag_from_norm = v3_norm.normalize();
	isequal(mag_from_norm, mag_from_fn);
	isequal(v3_norm.magnitude(), 1.0);

	// get unit vector
	Vector3 v3_unit(-5,0,10);
	Vector3 unit = v3_unit.unit_vector();
	isequal(unit.magnitude(), 1.0);
	isequal(unit*v3_unit.magnitude(), v3_unit);



	std::cout << "END Vector3 Tests-------------------------\n" << std::endl;
}