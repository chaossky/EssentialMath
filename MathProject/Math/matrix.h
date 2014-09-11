#pragma once

#include <iostream>

class rsVector3;

class rsMatrix33
{
public:
	rsMatrix33(){}
	rsMatrix33(const rsMatrix33& _matrix);
	~rsMatrix33(){}

	bool SetElement(float value, int rows, int cols);
	rsMatrix33& operator=(const rsMatrix33& _matrix);

	friend std::ostream& operator <<(std::ostream& o, const rsMatrix33& _matrix);

    rsMatrix33 operator-( const rsMatrix33& _matrix ) const;
	rsMatrix33 operator+( const rsMatrix33& _matrix ) const;

    rsMatrix33& operator+=( const rsMatrix33& _matrix );
    rsMatrix33& operator-=( const rsMatrix33& _matrix );

    rsMatrix33 operator-() const;

	float trace() const;

    rsMatrix33 operator*( float _scalar ) const;
	rsMatrix33& operator*=( float _scalar );
    friend rsMatrix33 operator*( float _scalar, const rsMatrix33& _matrix );

    rsMatrix33 operator*( const rsMatrix33& _matrix ) const;
	rsMatrix33& operator*=( const rsMatrix33& _matrix );

    rsVector3 operator*( const rsVector3& _vector ) const;
    friend rsVector3 operator*( const rsVector3& _vector, const rsMatrix33& _matrix );

	rsMatrix33& Transpose();
	void Identity();


public:
	float element[9];
};


