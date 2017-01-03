#pragma once

#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include <iostream>

#include "../Vectors/Vector3.h"

// REMOVE ME
#include "../test_utils.hpp"
// REMOVE ME

namespace LAL
{

class Matrix3x3
{
  int rows = 3, columns = 3;

  double x1 =0, y1=0, z1=0,
      x2 =0, y2=0, z2=0,
      x3 =0, y3=0, z3=0;
public:
  Matrix3x3(){}
  Matrix3x3(double _x1, double _y1, double _z1, 
        double _x2, double _y2, double _z2,
        double _x3, double _y3, double _z3):
        x1(_x1), y1(_y1), z1(_z1),
        x2(_x2), y2(_y2), z2(_z2),
        x3(_x3), y3(_y3), z3(_z3) {}
  Matrix3x3(Vector3 _row1, Vector3 _row2, Vector3 _row3){
    x1=_row1.get_x(); y1=_row1.get_y(); z1=_row1.get_z();
    x2=_row2.get_x(); y2=_row2.get_y(); z2=_row2.get_z();
    x3=_row3.get_x(); y3=_row3.get_y(); z3=_row3.get_z();
  }

  Vector3 get_row1() const { return Vector3(x1,y1,z1);}
  Vector3 get_row2() const { return Vector3(x2,y2,z2);}
  Vector3 get_row3() const { return Vector3(x3,y3,z3);}

  Vector3 get_row(int idx) const { 
    switch(idx){
      case 1:{
        return get_row1();
      }
      case 2:{
        return get_row2();
      }
      case 3:{
        return get_row3();
      }
      default:{
        std::cout << "ERROR: invalid get_row index " << idx << std::endl;
      }
    }
  }

  Vector3 get_col1() const { return Vector3(x1,x2,x3);}
  Vector3 get_col2() const { return Vector3(y1,y2,y3);}
  Vector3 get_col3() const { return Vector3(z1,z2,z3);}

  Vector3 get_col(int idx) const { 
    switch(idx){
      case 1:{
        return get_col1();
      }
      case 2:{
        return get_col2();
      }
      case 3:{
        return get_col3();
      }
      default:{
        std::cout << "ERROR: invalid get_col index " << idx << std::endl;
      }
    }
  }

  double get_x1() const { return x1; }
  double get_y1() const { return y1; }
  double get_z1() const { return z1; }

  double get_x2() const { return x2; }
  double get_y2() const { return y2; }
  double get_z2() const { return z2; }

  double get_x3() const { return x3; }
  double get_y3() const { return y3; }
  double get_z3() const { return z3; }

  void set_row1(Vector3 _r1) {
    x1 = _r1.get_x(); y1 = _r1.get_y(); z1 = _r1.get_z(); 
  }

  void set_row2(Vector3 _r2) {
    x2 = _r2.get_x(); y2 = _r2.get_y(); z2 = _r2.get_z(); 
  }

  void set_row3(Vector3 _r3) {
    x3 = _r3.get_x(); y3 = _r3.get_y(); z3 = _r3.get_z(); 
  }

  void set_row(int idx, Vector3 v){
    switch (idx){
      case 1:{
        set_row1(v);
        break;
      }
      case 2:{
        set_row2(v);
        break;
      }
      case 3:{
        set_row3(v);
        break;
      }
      default:{
        std::cout << "ERROR: Matrix3x3 set_row index invalid: " << idx << std::endl;
        exit(0);
      }
    }

  }

  void set_x1(double _x1){ x1=_x1;}
  void set_y1(double _y1){ y1=_y1;}
  void set_z1(double _z1){ z1=_z1;}

  void set_x2(double _x2){ x2=_x2;}
  void set_y2(double _y2){ y2=_y2;}
  void set_z2(double _z2){ z2=_z2;}

  void set_x3(double _x3){ x3=_x3;}
  void set_y3(double _y3){ y3=_y3;}
  void set_z3(double _z3){ z3=_z3;}

  // elementary row operations
  Matrix3x3 row_swap(int i, int j){
    Matrix3x3 result = *this;
    if (i < 0 || i > 3 || j < 0 || j > 3){
      std::cout << "ERROR: Matrix3x3 row_swap( " << i << ", " << j << " ) out of bounds (1-3)" << std::endl;
      exit(0);
    }
    if ( i != j){
      Vector3 temp = result.get_row(i);
      result.set_row(i, get_row(j));
      result.set_row(j, temp);
    }
    return result;

  }

  Matrix3x3 scalar_row_multiply(double scalar, int row){
    if(scalar == 0.0){
      std::cout << "Scalar multiplicand must be non-zero" << std::endl;
      exit(0);
    }
    switch(row){
      case(1):
        return Matrix3x3(scalar*get_row1(), get_row2(), get_row3());
      case(2):
        return Matrix3x3(get_row1(), scalar*get_row2(), get_row3());
      case(3):
        return Matrix3x3(get_row1(), get_row2(), scalar*get_row3());
    }
  }

  Matrix3x3 get_transpose() const {
    return Matrix3x3(x1,x2,x3,y1,y2,y3,z1,z2,z3);
  }

  // Algorithm 3.6 (p36) : Reduced linear system algorithm
  Vector3 solve_linear_system(Vector3 coeff){
    Matrix3x3 copy = *this;
    int i=1, j=1, k=1;
    int largest_idx=1;
    for (i; i <= rows; ++i){
      // find row with maximum column j value
      double max = 0;
      int max_row = -1;
      for (k=i; k <= rows; ++k){
        double current = abs(copy.get_row(k).get(j));
        if(current > max){
          max = current;
          max_row = k;
        }
      }
      // if there was no max > 0
      if(max == 0){
          --i; // repeat starting on row i
          ++j; // increment columns
          continue;
      }
      // if a swap is necessary
      if(max_row != i){
        copy = copy.row_swap(i,max_row);
        double temp = coeff.get(i);
        coeff.set(i, coeff.get(max_row));
        coeff.set(max_row, temp);
      }
      // scalar multiply to make M[i,j] = 1
      double reciprocal = 1.0 / copy.get_row(i).get(j);
      if (reciprocal != 1){
        copy.set_row(i,reciprocal*copy.get_row(i));
        coeff.set(i,reciprocal*coeff.get(i));
      }
      // zero non-ith row
      Vector3 ith = copy.get_row(i);
      for( int r = 1; r <= rows; ++r){
        if (r == i)
          continue;
        double neg_Mrj = -1*copy.get_row(r).get(j);
        copy.set_row(r, neg_Mrj*ith + copy.get_row(r));
        coeff.set(r, neg_Mrj*coeff.get(i) + coeff.get(r));
      }
      // move on to next column
      if (j < columns){
        ++j;
      } else {
        return coeff;
      }
    } // end for i

  }

  // operators
  friend Matrix3x3 operator * (double s, const Matrix3x3& m);


  Matrix3x3 operator * (const Matrix3x3& m) const {
    double _x1, _y1, _z1, _x2, _y2, _z2, _x3, _y3, _z3;
    _x1 = get_row1().dot_product(m.get_col1());
    _y1 = get_row1().dot_product(m.get_col2());
    _z1 = get_row1().dot_product(m.get_col3());
    _x2 = get_row2().dot_product(m.get_col1());
    _y2 = get_row2().dot_product(m.get_col2());
    _z2 = get_row2().dot_product(m.get_col3());
    _x3 = get_row3().dot_product(m.get_col1());
    _y3 = get_row3().dot_product(m.get_col2());
    _z3 = get_row3().dot_product(m.get_col3());

    return Matrix3x3(_x1, _y1, _z1,
             _x2, _y2, _z2,
             _x3, _y3, _z3);
  }

  Matrix3x3 operator +(const Matrix3x3& m) const {
    return Matrix3x3(x1+m.get_x1(),y1+m.get_y1(),z1+m.get_z1(),
             x2+m.get_x2(),y2+m.get_y2(),z2+m.get_z2(),
             x3+m.get_x3(),y3+m.get_y3(),z3+m.get_z3());
  }

  Matrix3x3 operator - () const {
    return -1*(*this);
  }

  Matrix3x3 operator -(const Matrix3x3& m) const {
    return Matrix3x3(x1-m.get_x1(),y1-m.get_y1(),z1-m.get_z1(),
             x2-m.get_x2(),y2-m.get_y2(),z2-m.get_z2(),
             x3-m.get_x3(),y3-m.get_y3(),z3-m.get_z3());
  }

  bool operator == (const Matrix3x3& m3x3) const {
    return (x1 == m3x3.get_x1()) &&
        (y1 == m3x3.get_y1()) &&
        (z1 == m3x3.get_z1()) &&
        (x2 == m3x3.get_x2()) &&
        (y2 == m3x3.get_y2()) &&
        (z2 == m3x3.get_z2()) &&
        (x3 == m3x3.get_x3()) &&
        (y3 == m3x3.get_y3()) &&
        (z3 == m3x3.get_z3());
  }

  bool operator != (const Matrix3x3& m3x3) const {
    return !(*this == m3x3);
  }

  Matrix3x3 operator * (double scalar) const {
    return scalar*(*this);
  }

};

std::ostream& operator << (std::ostream& os, const Matrix3x3& m);

} // end namespace LAL