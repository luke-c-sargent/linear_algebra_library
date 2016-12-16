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
bool isequal(T first, T second){

	if(first != second){
		std::cout << "!!\tFAILURE: " << stringify(first) << " != " << stringify(second) << std::endl;
		success = false;
		++fail_count;
	}
	else{
		std::cout << "\tSUCCESS: " << stringify(first) << " == " << stringify(second) << std::endl;
		++success_count;
	}
}

void isequal(double first, double second);