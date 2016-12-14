#pragma once
#include <sstream>
#include <iostream>

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
		std::cout << "!!\tFAILURE: " << stringify(first) << " != " << stringify(second) << std::endl;
	else
		std::cout << "\tSUCCESS: " << stringify(first) << " == " << stringify(second) << std::endl;
}

void isequal(double first, double second);