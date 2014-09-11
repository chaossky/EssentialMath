#pragma once

#include <iostream>
#include <math.h>
#include <assert.h>

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

	rsMatrix33& Transpose();	//전치행렬
	void Identity();			//단위행렬

	rsMatrix33 Adjoint() const;	//수반행렬(여인자로 구성)
    float Determinant() const;	//행렬식

	rsMatrix33& Inverse();
    friend rsMatrix33 Inverse( const rsMatrix33& _matrix );

public:
	float element[9]; 
};


