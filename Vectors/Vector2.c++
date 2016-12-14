#include "Vector2.h"

using namespace LAL;
namespace LAL{

std::ostream& operator << (std::ostream& os, const Vector2& v2){
		os << "< " << v2.get_x() << ", " << v2.get_y() << " >"; 
}

Vector2 operator * (double scalar, const Vector2& v2){
	return Vector2(scalar*v2.get_x(), scalar*v2.get_y());
}

// get the planar angle of the two vectors (vectors from origin to point defined by v2s)
double planar_angle(const Vector2& v2_a, const Vector2& v2_b){
	double dot_p = v2_a.dot_product(v2_b);
	double cos_a_eq = dot_p / (v2_a.magnitude() * v2_b.magnitude());
	return acos(cos_a_eq);
}

bool are_orthogonal(const Vector2& v2_a, const Vector2& v2_b){
	return (v2_a.dot_product(v2_b) == 0.0);
}

}// END LAL namespace