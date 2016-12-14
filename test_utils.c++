#include "test_utils.hpp"
#include <cmath>

bool double_approx_equals(double first, double second){
	double epsilon = 0.000000000000001;
	if( (first != second))
		if( (std::abs(first - second) < epsilon) )
			std::cout << "[DR]\tSUCCESS: " << first << " == " << second << std::endl;
		else
			std::cout << "[!!]\tFAILURE: " << first << " != " << second << std::endl;
	else
		std::cout << "\tSUCCESS: " << first << " == " << second << std::endl;
}

void isequal(double first, double second)
{
	double_approx_equals(first, second);
}