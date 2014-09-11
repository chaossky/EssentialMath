
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

	rsMatrix33& Transpose();
	void Identity();


public:
	float element[9];
};

rsMatrix33::rsMatrix33(const rsMatrix33& _matrix)
{
	element[0] = _matrix.element[0];
	element[1] = _matrix.element[1];
	element[2] = _matrix.element[2];
	element[3] = _matrix.element[3];
	element[4] = _matrix.element[4];
	element[5] = _matrix.element[5];
	element[6] = _matrix.element[6];
	element[7] = _matrix.element[7];
	element[8] = _matrix.element[8];
}

bool rsMatrix33::SetElement(float value, int rows, int cols)
{
	if( (rows > 3) || (cols > 3) )
		return false;

	int index = ((rows - 1) * 3 ) + (cols - 1); 
	element[index] = value;

	return true;
}


rsMatrix33& rsMatrix33::operator=(const rsMatrix33& _matrix)
{
	if(this == &_matrix)
		return *this;

	element[0] = _matrix.element[0];
	element[1] = _matrix.element[1];
	element[2] = _matrix.element[2];
	element[3] = _matrix.element[3];
	element[4] = _matrix.element[4];
	element[5] = _matrix.element[5];
	element[6] = _matrix.element[6];
	element[7] = _matrix.element[7];
	element[8] = _matrix.element[8];

	return *this;
}

std::ostream& operator <<(std::ostream& _ostream, const rsMatrix33& _matrix)
{
	return 	_ostream<<"\n|"<<_matrix.element[0]<<" "<<_matrix.element[1]<<" "<<_matrix.element[2]<<"|"<<"\n|"<<_matrix.element[3]<<" "<<_matrix.element[4]<<" "<<_matrix.element[5]<<"|"<<"\n|"<<_matrix.element[6]<<" "<<_matrix.element[7]<<" "<<_matrix.element[8]<<"|";
}

rsMatrix33 rsMatrix33::operator-( const rsMatrix33& _matrix ) const
{
	rsMatrix33 matrix;
	for(int i = 0; i < 9; i++)
	{
		matrix.element[i] = element[i] - _matrix.element[i];
	}

	return matrix;
}

rsMatrix33 rsMatrix33::operator+( const rsMatrix33& _matrix ) const
{
	rsMatrix33 matrix;
	for(int i = 0; i < 9; i++)
	{
		matrix.element[i] = element[i] + _matrix.element[i];
	}

	return matrix;
}

rsMatrix33& rsMatrix33::operator+=( const rsMatrix33& _matrix )
{
	for(int i = 0; i < 9; i++)
	{
		element[i] += _matrix.element[i];
	}

	return *this;
}

rsMatrix33& rsMatrix33::operator-=( const rsMatrix33& _matrix )
{
	for(int i = 0; i < 9; i++)
	{
		element[i] -= _matrix.element[i];
	}

	return *this;
}

rsMatrix33 rsMatrix33::operator-() const
{
	rsMatrix33 matrix;
	for(int i = 0; i < 9; i++)
	{
		if(element[i] == 0)
			matrix.element[i] = 0.0f;
		else
			matrix.element[i] = -element[i];
	}

	return matrix;
}

float rsMatrix33::trace() const
{
	float trace;
	trace = element[0] + element[4] + element[8];
	return trace;
}

rsMatrix33 rsMatrix33::operator*( float _scalar ) const
{
	rsMatrix33 matrix;
	for(int i=0; i < 9; i++)
	{
		matrix.element[i] = element[i] * _scalar; 
	}

	return matrix;
}

rsMatrix33& rsMatrix33::operator*=( float _scalar )
{
	for(int i=0; i < 9; i++)
	{
		element[i] *= _scalar;
	}

	return *this;
}

rsMatrix33 operator*( float _scalar, const rsMatrix33& _matrix )
{
	rsMatrix33 matrix;
	for(int i = 0; i < 9; i++)
	{
		matrix.element[i] = _matrix.element[i] * _scalar;
	}

	return matrix;
}

rsMatrix33 rsMatrix33::operator*( const rsMatrix33& _matrix ) const
{
	rsMatrix33 matrix;
	for(int i = 0; i < 9; i++)
	{
		int rows = (i / 3) * 3;
		int cols = (i % 3);
		matrix.element[i] = element[cols] * _matrix.element[rows] + 
							element[cols + 3] * _matrix.element[rows + 1] + 
							element[cols + 6] * _matrix.element[rows + 2];
	}

	return matrix;
}

rsMatrix33& rsMatrix33::operator*=( const rsMatrix33& _matrix )
{
	for(int i = 0; i < 9; i++)
	{
		int rows = (i / 3) * 3;
		int cols = (i % 3);
		element[i] = element[cols] * _matrix.element[rows] + 
					element[cols + 3] * _matrix.element[rows + 1] + 
					element[cols + 6] * _matrix.element[rows + 2];
	}

	return *this;
}

rsMatrix33& rsMatrix33::Transpose()
{
	float temp = element[1];
	element[1] = element[3];
	element[3] = temp;

	temp = element[2];
	element[2] = element[6];
	element[6] = temp;

	temp = element[5];
	element[5] = element[7];
	element[7] = temp;

	return *this;
}

void rsMatrix33::Identity()
{
	element[0] = 1.0f;
	element[1] = 0.0f;
	element[2] = 0.0f;
	element[3] = 0.0f;
	element[4] = 1.0f;
	element[5] = 0.0f;
	element[6] = 0.0f;
	element[7] = 0.0f;
	element[8] = 1.0f;
}

