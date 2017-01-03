#include "Matrix3x3.h"

using namespace LAL;

namespace LAL
{

std::ostream& operator << (std::ostream& os, const Matrix3x3& m){
  os << "[[" << m.get_x1() << ", " << m.get_y1() << ", " << m.get_z1() << "],[" <<
    m.get_x2() << ", " << m.get_y2() << ", " << m.get_z2() << "],[" <<
    m.get_x3() << ", " << m.get_y3() << ", " << m.get_z3() << "]]";
}

Matrix3x3 operator * (double s, const Matrix3x3& m){
  return Matrix3x3(s*m.x1,s*m.y1,s*m.z1,
           s*m.x2,s*m.y2,s*m.z2,
           s*m.x3,s*m.y3,s*m.z3);
}

}