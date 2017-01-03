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
	are_equal(v3.get_x(), 0.0);
	are_equal(v3.get_y(), 0.0);
	are_equal(v3.get_z(), 0.0);

	//basic constructor
	Vector3 v3_constr(-1,2,-3);
	are_equal(v3_constr.get_x(), -1.0);
	are_equal(v3_constr.get_y(), 2.0);
	are_equal(v3_constr.get_z(), -3.0);
	
	//vector equality
	are_equal(v3_constr == Vector3(-1,2,-3), true);

	//vector inequality
	are_equal(v3_constr != Vector3(-1,2,-3), false);

	//setter functions
	Vector3 v3_set;
	v3_set.set_x(6);
	v3_set.set_y(6);
	v3_set.set_z(6);
	are_equal(v3_set, Vector3(6,6,6));

	//addition operator
	are_equal(Vector3(1,2,3)+Vector3(1,0,-1), Vector3(2,2,2));

	//stringify with output stream
	are_equal(stringify(Vector3(7.0, 7.0, 7.0)), stringify("< 7, 7, 7 >"));

	// multiplication of scalar
	are_equal(Vector3(1,2,3)*2.0, Vector3(2,4,6));
	// reverse multiplicand and multiplier
	are_equal(3.0*Vector3(1,1,1), Vector3(3,3,3));

	//unary negation
	are_equal(-Vector3(-10,10,-20), Vector3(10,-10,20));

	//subtraction
	are_equal(Vector3(3,5,7)-Vector3(-2,0,2), Vector3(5,5,5));

	// magnitude
	are_equal(Vector3().magnitude(), 0.0);
	are_equal(Vector3(2,2,2).magnitude(), sqrt(12));

	// normalize vector
	Vector3 v3_norm(-3,5,56);
	double mag_from_fn = v3_norm.magnitude();
	double mag_from_norm = v3_norm.normalize();
	are_equal(mag_from_norm, mag_from_fn);
	are_equal(v3_norm.magnitude(), 1.0);

	// get unit vector
	Vector3 v3_unit(-5,0,10);
	Vector3 unit = v3_unit.unit_vector();
	are_equal(unit.magnitude(), 1.0);
	are_equal(unit*v3_unit.magnitude(), v3_unit);

	// dot product
	Vector3 dp1(1,2,3);
	Vector3 dp2(3,2,1);
	are_equal(dp1.dot_product(dp2), 3*1 + 2*2 + 1*3);
	//commutativity
	are_equal(dp1.dot_product(dp2), dp2.dot_product(dp1));

	//planar angle in radians
	are_equal(planar_angle(Vector3(1,-1,2),Vector3(1,1,1)), 
		1.07991364850558525065041281038291199);// value from wolframalpha

	// vector orthogonality
	Vector3 ortho1(1,0,0);
	Vector3 ortho2(0,1,0);
	Vector3 ortho3(0,0,1);
	Vector3 not_ortho(1,1,1);
	are_equal(are_orthogonal(ortho1, ortho3) && are_orthogonal(ortho1, ortho3) && 
		are_orthogonal(ortho2,ortho3), true);
	are_equal(are_orthogonal(ortho1, not_ortho) || are_orthogonal(ortho2, not_ortho) || 
		are_orthogonal(ortho3, not_ortho), false );

	// cross product
	Vector3 cross1(1,2,3);
	Vector3 cross2(2,2,2);
	Vector3 c1_cross_c2(-2,4,-2);
	Vector3 c2_cross_c1(2,-4,2);
	are_equal(cross1.cross_product(cross2), c1_cross_c2);
	are_equal(cross2.cross_product(cross1), c2_cross_c1);
	//non-commutativity
	are_equal(cross1.cross_product(cross2) == cross2.cross_product(cross1),
		false);
	// orthogonality of cross products
	are_equal(
		are_orthogonal(cross1.cross_product(cross2), cross1) &&
		are_orthogonal(cross1.cross_product(cross2), cross2) &&
		are_orthogonal(cross2.cross_product(cross1), cross1) &&
		are_orthogonal(cross2.cross_product(cross1), cross2),
		true);

	std::cout << "[END Vector3 Tests-------------------------------------]\n" << std::endl;
}