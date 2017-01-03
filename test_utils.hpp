#pragma once
#include <sstream>
#include <iostream>

extern bool success;
extern int fail_count;
extern int success_count;

template<class T>
std::string stringify(const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename T>
bool are_equal(T first, T second){

	if(first != second){
		std::cout << "!!|FAILURE: " << stringify(first) << " != " << stringify(second) << std::endl;
		success = false;
		++fail_count;
	}
	else{
		std::cout << "   SUCCESS: " << stringify(first) << " == " << stringify(second) << std::endl;
		++success_count;
	}
}

void are_equal(double first, double second);