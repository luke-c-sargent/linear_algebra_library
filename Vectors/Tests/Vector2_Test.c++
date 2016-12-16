#include <math.h>
#include <iostream>

#include "Vector2_Test.h"
#include "../Vector2.h"
#include "../../test_utils.hpp"

using namespace LAL;

void test_vector2(){
	std::cout << "Vector2 Tests:" << std::endl;

	//default zero vector, getter functions
	Vector2 v2_a;
	isequal(v2_a.get_x(), 0.0);
	isequal(v2_a.get_y(), 0.0);

	//basic constructor
	Vector2 v2_b(1,2);
	isequal(v2_b.get_x(),1.0);
	isequal(v2_b.get_y(),2.0);

	//vector equality
	isequal(v2_a == Vector2(0,0), true);

	//vector inequality
	isequal(v2_a != Vector2(0,0), false);

	//setter functions
	Vector2 v2_c;
	v2_c.set_x(3);
	v2_c.set_y(4);
	isequal(v2_c, Vector2(3,4));

	//addition operator
	isequal(Vector2(1,2)+Vector2(1,-1), Vector2(2,1));

	//stringify with output stream
	isequal(stringify(Vector2(1,2)), stringify("< 1, 2 >"));

	// multiplication of scalar
	isequal(Vector2(3,5)*.5, Vector2(1.5,2.5));
	// multiplication with multiplicand and multiplier reversed
	isequal(0.1*Vector2(20,40), Vector2(2,4));

	//unary negation
	isequal(-Vector2(-10,10), Vector2(10,-10));

	// subtraction
	isequal(Vector2(0,0), Vector2(100,100) - Vector2(100,100));

	// magnitude of vector
	isequal(Vector2().magnitude(), 0.0);
	isequal(Vector2(4,5).magnitude(), sqrt(4*4 + 5*5));

	//normalize vector
	Vector2 v2_d(100,-3);
	double mag_from_fn = v2_d.magnitude();
	double mag_from_nrm = v2_d.normalize();
	isequal(mag_from_fn, mag_from_nrm);
	isequal(v2_d.magnitude(),1.0);

	//get unit vector
	Vector2 v2_e(-666,777);
	Vector2 unit = v2_e.unit_vector();
	isequal(unit.magnitude(), 1.0);
	isequal(unit*v2_e.magnitude(),v2_e);

	//dot product
	Vector2 dp1(2,3);
	Vector2 dp2(4,5);
	isequal(dp1.dot_product(dp2), 2.0*4.0 + 3.0*5.0);
	//		commutativity
	isequal(dp1.dot_product(dp2), dp2.dot_product(dp1));

	//planar angle, in radians
	Vector2 pa1(1,2);
	Vector2 pa2(2,2);
	isequal(planar_angle(pa1,pa2),0.3217505543966423); // value from wolframalpha

	//vector orthogonality
	Vector2 ortho1(1,2);
	Vector2 ortho2(2,-1);
	Vector2 not_ortho(1,1);
	isequal(are_orthogonal(ortho1, ortho2), true);
	isequal(are_orthogonal(ortho1, not_ortho), false);

	std::cout << "[END Vector2 Tests-------------------------------------]\n" << std::endl;
}