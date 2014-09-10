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

	rsVector2 operator+ (const rsVector2& _vector2) const;
	rsVector2 operator- (const rsVector2& _vector2) const;
	friend std::ostream& operator <<(std::ostream& o, const rsVector2& _vector2);

	rsVector2 operator* (float scalar);
	friend rsVector2 operator* (float scalar, const rsVector2& _vector2); 

	rsVector2& operator*= (float scalar);

	float Length() const;
	rsVector2& Normalize();

	float Dot(const rsVector2& _vector2) const;

	rsVector2 PrepDot(const rsVector2& _vector2);

public:
	float x,y;
};