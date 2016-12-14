#include "Vector3.h"

namespace LAL{

std::ostream& operator << (std::ostream& os, const Vector3& v3){
		os << "< " << v3.x << ", " << v3.y << ", " << v3.z <<" >"; 
}

Vector3 operator * (double scalar, const Vector3& v3){
	return Vector3(scalar*v3.get_x(), scalar*v3.get_y(), scalar*v3.get_z());
}

// get the planar angle of the two vectors (vectors from origin to point defined by v2s)
double planar_angle(const Vector3& v3_a, const Vector3& v3_b){
	double dot_p = v3_a.dot_product(v3_b);
	double cos_a_eq = dot_p / (v3_a.magnitude() * v3_b.magnitude());
	return acos(cos_a_eq);
}

bool are_orthogonal(const Vector3& v3_a, const Vector3& v3_b){
	return (v3_a.dot_product(v3_b) == 0.0);
}

}// END LAL namespace