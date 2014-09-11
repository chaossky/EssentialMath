#pragma once

#include <iostream>
#include <math.h>
#include <assert.h>

class rsVector2
{
public:
	rsVector2():x(0.0f),y(0.0f){}
	rsVector2(float _x, float _y):x(_x),y(_y){}
	~rsVector2(){}

	void SetValue(float _x, float _y){x=_x; y=_y;}

	rsVector2 operator+ (const rsVector2& _vector) const;
	rsVector2 operator- (const rsVector2& _vector) const;
	friend std::ostream& operator <<(std::ostream& _ostream, const rsVector2& _vector);

	rsVector2 operator* (float _scalar);
	friend rsVector2 operator* (float _scalar, const rsVector2& _vector); 

	rsVector2& operator*= (float _scalar);

	float Length() const;
	rsVector2& Normalize();

	float Dot(const rsVector2& _vector) const;

	rsVector2 PrepDot(const rsVector2& _vector);

public:
	float x,y;
};

class rsVector3
{
public:
	rsVector3():x(0.0f),y(0.0f),z(0.0f){}
	rsVector3(float _x, float _y, float _z):x(_x),y(_y),z(_z){}
	~rsVector3(){}

	void SetValue(float _x, float _y, float _z){x=_x; y=_y; z=_z;}

	rsVector3 operator+ (const rsVector3& _vector) const;
	rsVector3 operator- (const rsVector3& _vector) const;
	friend std::ostream& operator <<(std::ostream& _ostream, const rsVector3& _vector);

	rsVector3 operator* (float _scalar);
	friend rsVector3 operator* (float _scalar, const rsVector3& _vector); 

	rsVector3& operator*= (float _scalar);

	float Length() const;
	rsVector3& Normalize();

	float Dot(const rsVector3& _vector) const;

public:
	float x,y,z;
};

class rsVector4
{
public:
	rsVector4():x(0.0f),y(0.0f),z(0.0f),w(0.0f){}
	rsVector4(float _x, float _y, float _z, float _w):x(_x),y(_y),z(_z),w(_w){}
	~rsVector4(){}

	void SetValue(float _x, float _y, float _z, float _w){x=_x; y=_y; z=_z; w=_w;}

	rsVector4 operator+ (const rsVector4& _vector) const;
	rsVector4 operator- (const rsVector4& _vector) const;
	friend std::ostream& operator <<(std::ostream& _ostream, const rsVector4& _vector);

	rsVector4 operator* (float _scalar);
	friend rsVector4 operator* (float _scalar, const rsVector4& _vector); 

	rsVector4& operator*= (float _scalar);

	float Length() const;
	rsVector4& Normalize();

	float Dot(const rsVector4& _vector) const;

public:
	float x,y,z,w;
};