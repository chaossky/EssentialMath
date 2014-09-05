#include <iostream>

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

	rsVector2 operator*= (float scalar);

public:
	float x,y;
};

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

rsVector2 rsVector2::operator*= (float scalar)
{
	x *= scalar;
	y *= scalar;

	return *this;
}


int main()
{
	enum EDATA_TYPE
	{
		eVector2 = 1,
		eMax
	};

	int UseType = 1;

	while(UseType != 0)
	{
		std::cout<<"\n테스트할 자료형을 선택하세요."<<std::endl;
		std::cout<<"1 -> 2차원벡터(Vector2D)"<<std::endl;
		std::cout<<"0 -> 종료"<<std::endl;
		std::cin>>UseType;

		if(UseType == 0)
		{
			return -1;
		}

		switch( static_cast<EDATA_TYPE>(UseType) )
		{
		case eVector2:
			{
				std::cout<<"\n1.2차원벡터(Vector2D) 선택"<<std::endl;

				rsVector2 vector1;
				vector1.SetValue(10.0f, 20.0f);
				rsVector2 vector2(11.0f, 12.0f);

				std::cout<<"vector1=("<<vector1.x<<","<<vector1.y<<")입니다."<<std::endl;
				std::cout<<"vector2=("<<vector2.x<<","<<vector2.y<<")입니다."<<std::endl;
				std::cout<<"vector1 + vector2 ="<< vector1 + vector2 <<std::endl;
				std::cout<<"vector2 + vector1 ="<< vector2 + vector1 <<std::endl;
				std::cout<<"vector1 - vector2 ="<< vector1 - vector2 <<std::endl;
				std::cout<<"2(vector1) ="<< 2 * vector1 <<std::endl;
				std::cout<<"(vector1)2 ="<< vector1 * 2 <<std::endl;
				std::cout<<"(2+3)(vector1) ="<< (2+3) * vector1 <<std::endl;
				std::cout<<"2(vector1 + vector2) ="<< 2 * (vector1 + vector2) <<std::endl;
				std::cout<<"vector1*=vector2 ="<< (vector1*=7) <<std::endl;
			}
			break;
		default:
			{
				std::cout<<"\n잘못된 입력입니다.\n"<<std::endl;
			}break;
		}
	}
	return 1;
}