#include "LAL.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> error_msgs;

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
		error_msgs.push_back("\t"+stringify(first)+" != " + stringify(second));
}

void test_vector2(){
	error_msgs.push_back("Vector2 Test Failures:");
	int msg_sz = error_msgs.size();
	//vector
	Vector2 v2_a;
	isequal(v2_a.get_x(), 0.f);
	isequal(v2_a.get_y(), 0.f);

	Vector2 v2_b(1,2);
	isequal(v2_b.get_x(),1.0f);
	isequal(v2_b.get_y(),2.f);

	Vector2 v2_c;
	v2_c.set_x(3);
	v2_c.set_y(4);
	isequal(v2_c.get_x(), 3.f);
	isequal(v2_c.get_y(), 4.f);

	isequal(Vector2(1,2)+Vector2(1,-1), Vector2(2,1));
	isequal(stringify(Vector2(1,2)), stringify("< 1, 2 >"));

	isequal(Vector2(3,5)*.5, Vector2(1.5,2.5));
	isequal(-Vector2(-10,10), Vector2(10,-10));

	isequal(Vector2(0,0), Vector2(100,100) - Vector2(100,100));

	if(msg_sz==error_msgs.size())
		error_msgs.push_back("\tnone!");
}

void test_vector3(){

}

int main(){

	test_vector2();
	test_vector3();

	for( std::string str : error_msgs){
		std::cout << str << std::endl;
	}
}
