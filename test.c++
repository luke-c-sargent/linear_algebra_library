//#include "LAL.h"
#include <iostream>
#include <string>
#include "test_utils.hpp"
#include "./Vectors/Tests/Vector2_Test.h"
#include "./Vectors/Tests/Vector3_Test.h"

// TEST SUITE:
//		Tests class construction, their member functions, and supporting functions.
//		Output stored in 'test_output.txt' upon successful execution.


int main(){

	std::cout << "----=======[Linear Algebra Library Test Suite]=======----" << std::endl;
	std::cout << "|  prefix symbols:\t\t\t\t\t|\n|\t!! = test failure\t\t\t\t|\n" << 
				"|\tDR = double rounding: values differ by < 1e-15\t|" << std::endl <<
				"---------------------------------------------------------\n" << std::endl;
	test_vector2();
	test_vector3();
}
