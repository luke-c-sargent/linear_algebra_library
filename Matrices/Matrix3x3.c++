#include "Matrix3x3.h"

using namespace LAL;

namespace LAL
{

std::ostream& operator << (std::ostream& os, const Matrix3x3& m){
	os << "[[" << m.get_x1() << ", " << m.get_y1() << ", " << m.get_z1() << "],[" <<
		m.get_x2() << ", " << m.get_y2() << ", " << m.get_z2() << "],[" <<
		m.get_x3() << ", " << m.get_y3() << ", " << m.get_z3() << "]]";
}

}