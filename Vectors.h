#include <iostream>

namespace LAL
{

class Vector2
{
	float x = 0 ,y = 0;
public:
	Vector2(){}
	Vector2(float _x, float _y): x(_x), y(_y){}
	float get_x() const {return x;}
	float get_y() const {return y;}
	void set_x(float _x){x=_x;}
	void set_y(float _y){y=_y;}

	Vector2 operator +(const Vector2& v2){
		return Vector2(this->x + v2.get_x(), this->y + v2.get_y());
	}

	bool operator == (const Vector2& v2){
		return (this->x == v2.get_x()) && (this->y == v2.get_y());
	}

	bool operator != (const Vector2& v2){
		return !(*this == v2);
	}

	friend std::ostream& operator << (std::ostream& os, const Vector2& v2);
};

std::ostream& operator << (std::ostream& os, const Vector2& v2){
		os << "< " << v2.x << ", " << v2.y << " >"; 
}

class Vector3
{
	float x = 0, y = 0, z = 0;
public:
	Vector3(){}
	Vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z){}
/*	float x(){return x;}
	float y(){return y;}
	float z(){return z;}*/
};

class Vector4
{
	float x = 0, y = 0, z = 0, w = 0;
public:
	Vector4(){}
	Vector4(float _x, float _y, float _z, float _w): x(_x), y(_y), z(_z), w(_w){}
/*	float x(){return x;}
	float y(){return y;}
	float z(){return z;}
	float w(){return w;}*/
};

} // end LAL namespace