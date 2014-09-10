#include "vector.h"

rsVector2 rsVector2::operator+ (const rsVector2& _vector2) const
{
	return rsVector2(x + _vector2.x, y + _vector2.y);
}

rsVector2 rsVector2::operator- (const rsVector2& _vector2) const
{
	return rsVector2(x - _vector2.x, y - _vector2.y);
}

std::ostream& operator <<(std::ostream& _ostream, const rsVector2& _vector2)
{
	return _ostream<<"("<<_vector2.x<<","<<_vector2.y<<")";
}

rsVector2 rsVector2::operator* (float scalar)
{
	return rsVector2(scalar * x, scalar * y);
}

rsVector2 operator* (float scalar, const rsVector2& _vector2)
{
	return rsVector2(scalar * _vector2.x, scalar * _vector2.y);
}

rsVector2& rsVector2::operator*= (float scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}

float rsVector2::Length() const
{
	return sqrtf(x * x + y * y);
}

rsVector2& rsVector2::Normalize()
{
	float lengthSqrt = x * x + y * y;
	assert(!(lengthSqrt == 0.0f));
	if(lengthSqrt == 0.0f)
	{
		x = 0;
		y = 0;
		return *this;
	}

	x *= (1.0f/sqrtf(lengthSqrt));
	y *= (1.0f/sqrtf(lengthSqrt));

	return *this;
}

float rsVector2::Dot(const rsVector2& _vector2) const
{
	return x * _vector2.x + y * _vector2.y;
}

rsVector2 rsVector2::PrepDot(const rsVector2& _vector2)
{
	return rsVector2(y * _vector2.x, x * _vector2.y);
}
