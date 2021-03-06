#include "test_utils.hpp"
#include <cmath>

bool success = true;
int fail_count = 0;
int success_count = 0;

bool double_approx_equals(double first, double second){
	double epsilon = 0.000000000000001;
	if( (first != second)){
		if( (std::abs(first - second) < epsilon) ){
			std::cout << "DR|SUCCESS: " << first << " == " << second << std::endl;
			++success_count;
		}
		else{
			std::cout << "!!|FAILURE: " << first << " != " << second << std::endl;
			success = false;
			++fail_count;
		}
	}
	else{
		std::cout << "   SUCCESS: " << first << " == " << second << std::endl;
		++success_count;
	}
}

void are_equal(double first, double second)
{
	double_approx_equals(first, second);
}