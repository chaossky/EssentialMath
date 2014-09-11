#pragma once

#include <iostream>
#include <math.h>
#include <assert.h>

#define kEpsilon    1.0e-6f

inline bool IsZero( float a ) {return ( fabsf(a) < kEpsilon );}
inline bool rsEqual( float a, float b ) {return ( ::IsZero(a-b) );}

class rsVector2
{
public:
	rsVector2():x(0.0f),y(0.0f){}
	rsVector2(float _x, float _y):x(_x),y(_y){}
    rsVector2(const rsVector2& _vector):x(_vector.x),y(_vector.y){}
	~rsVector2(){}

    rsVector2& operator=(const rsVector2& _vector);

	void SetValue(float _x, float _y){x=_x; y=_y;}

	bool operator==( const rsVector2& _vector ) const;
    bool operator!=( const rsVector2& _vector ) const;
    bool IsZero() const;

	rsVector2 operator+ (const rsVector2& _vector) const;
	rsVector2 operator- (const rsVector2& _vector) const;
	friend std::ostream& operator <<(std::ostream& _ostream, const rsVector2& _vector);

	rsVector2 operator* (float _scalar);
	friend rsVector2 operator* (float _scalar, const rsVector2& _vector); 

	rsVector2& operator*= (float _scalar);

	float Length() const;
	rsVector2& Normalize();

	float Dot(const rsVector2& _vector) const;

	float PrepDot(const rsVector2& _vector);
	float PrepDot(const rsVector2& _vector1, const rsVector2& _vector2);

	rsVector2 Perpendicular() const { return rsVector2(-y, x); } 

public:
	float x,y;
};

class rsVector3
{
public:
	rsVector3():x(0.0f),y(0.0f),z(0.0f){}
	rsVector3(float _x, float _y, float _z):x(_x),y(_y),z(_z){}
    rsVector3(const rsVector3& _vector):x(_vector.x),y(_vector.y),z(_vector.z){}
	~rsVector3(){}

	rsVector3& operator=(const rsVector3& _vector);

	void SetValue(float _x, float _y, float _z){x=_x; y=_y; z=_z;}

	rsVector3 operator+ (const rsVector3& _vector) const;
	rsVector3 operator- (const rsVector3& _vector) const;
	friend std::ostream& operator <<(std::ostream& _ostream, const rsVector3& _vector);

	rsVector3 operator* (float _scalar);
	friend rsVector3 operator* (float _scalar, const rsVector3& _vector); 

	rsVector3& operator*= (float _scalar);

	friend float Distance( const rsVector3& _vector1, const rsVector3& _vector2 );
    friend float DistanceSquared( const rsVector3& _vector1, const rsVector3& _vector2 );

	float Length() const;
	rsVector3& Normalize();

	float Dot(const rsVector3& _vector) const;
	rsVector3 Cross( const rsVector3& _vector ) const;

	friend float Dot( const rsVector3& _vector1, const rsVector3& _vector2 );
    friend rsVector3 Cross( const rsVector3& _vector1, const rsVector3& _vector2 );

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

	friend float Distance( const rsVector4& _vector1, const rsVector4& _vector2 );
    friend float DistanceSquared( const rsVector4& _vector1, const rsVector4& _vector2 );

	float Length() const;
	rsVector4& Normalize();

	float Dot(const rsVector4& _vector) const;

public:
	float x,y,z,w;
};