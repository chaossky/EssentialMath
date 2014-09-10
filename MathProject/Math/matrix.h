
class rsMatrix33
{
public:
	rsMatrix33(){}
	rsMatrix33(const rsMatrix33& _matrix);
	~rsMatrix33(){}

	rsMatrix33& operator=(const rsMatrix33& _matrix);

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