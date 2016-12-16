//#include "LAL.h"
#include <iostream>
#include <string>
#include "test_utils.hpp"
#include "./Vectors/Tests/Vector2_Test.h"
#include "./Vectors/Tests/Vector3_Test.h"
#include "./Matrices/Tests/Matrix3x3_Test.h"
#include <cstdlib>

// TEST SUITE:
//		Tests class construction, their member functions, and supporting functions.
//		Output stored in 'test_output.txt' upon successful execution.

int main(){

	std::cout << "----=======[Linear Algebra Library Test Suite]=======----" << std::endl;
	std::cout << "|  prefix symbols:\t\t\t\t\t|\n|\t!! = test failure\t\t\t\t|\n" << 
				"|\tDR = double rounding: values differ by < 1e-15\t|" << std::endl <<
				"---------------------------------------------------------\n" << std::endl;
	// Vectors
	test_vector2();
	test_vector3();

	// Matrices
	test_matrix3x3();

	if(success)
		std::cout << "All [" << success_count << "] tests successful!" << std::endl;
	else
		std::cout << "ERROR: [" << fail_count << "] OUT OF [" << success_count + fail_count << "] TESTS FAILED" << std::endl;
	
	return EXIT_SUCCESS;
}
