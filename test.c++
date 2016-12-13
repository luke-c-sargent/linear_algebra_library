#include "LAL.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace LAL;

template<class T>
std::string stringify(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename T>
void isequal(T first, T second){
	if(first != second)
		std::cout << "\tFAILURE: " << stringify(first) << " != " << stringify(second) << std::endl;
	else
		std::cout << "\tSUCCESS: " << stringify(first) << " == " << stringify(second) << std::endl;
}

void test_vector2(){
	std::cout << "Vector2 Tests:" << std::endl;

	//default zero vector
	Vector2 v2_a;
	isequal(v2_a.get_x(), 0.0);
	isequal(v2_a.get_y(), 0.0);

	//basic constructor, getter functions
	Vector2 v2_b(1,2);
	isequal(v2_b.get_x(),1.0);
	isequal(v2_b.get_y(),2.0);

	//setter functions
	Vector2 v2_c;
	v2_c.set_x(3);
	v2_c.set_y(4);
	isequal(v2_c.get_x(), 3.0);
	isequal(v2_c.get_y(), 4.0);

	//addition operator
	isequal(Vector2(1,2)+Vector2(1,-1), Vector2(2,1));

	//stringify with output stream
	isequal(stringify(Vector2(1,2)), stringify("< 1, 2 >"));

	// multiplication of scalar
	isequal(Vector2(3,5)*.5, Vector2(1.5,2.5));

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
}

void test_vector3(){

}

int main(){

	std::cout << "----[Linear Algebra Library Test Suite]---" << std::endl;

	test_vector2();
	//test_vector3();
}
