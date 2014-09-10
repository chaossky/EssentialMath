#include "vector.h"
#include "matrix.h"

int main()
{
	enum EDATA_TYPE
	{
		eVector2 = 1,
		eMatrix33,
		eMax
	};

	int UseType = 1;

	while(UseType != 0)
	{
		std::cout<<"\n�׽�Ʈ�� �ڷ����� �����ϼ���."<<std::endl;
		std::cout<<"1 -> 2��������(Vector2D)"<<std::endl;
		std::cout<<"2 -> 3X3 ���(Matrix33)"<<std::endl;
		std::cout<<"0 -> ����"<<std::endl;
		std::cin>>UseType;

		if(UseType == 0)
		{
			return -1;
		}

		switch( static_cast<EDATA_TYPE>(UseType) )
		{
		case eVector2:
			{
				std::cout<<"\n1.2��������(Vector2D) ����"<<std::endl;

				rsVector2 vector1;
				vector1.SetValue(10.0f, 20.0f);
				rsVector2 vector2(11.0f, 12.0f);

				std::cout<<"vector1=("<<vector1.x<<","<<vector1.y<<")�Դϴ�."<<std::endl;
				std::cout<<"vector2=("<<vector2.x<<","<<vector2.y<<")�Դϴ�."<<std::endl;
				std::cout<<"vector1�� ���̴� "<< vector1.Length() <<std::endl;
				std::cout<<"vector2�� ���̴� "<< vector2.Length() <<std::endl;
				std::cout<<"vector1 + vector2 ="<< vector1 + vector2 <<std::endl;
				std::cout<<"vector2 + vector1 ="<< vector2 + vector1 <<std::endl;
				std::cout<<"vector1 - vector2 ="<< vector1 - vector2 <<std::endl;
				std::cout<<"2(vector1) ="<< 2 * vector1 <<std::endl;
				std::cout<<"(vector1)2 ="<< vector1 * 2 <<std::endl;
				std::cout<<"(2+3)(vector1) ="<< (2+3) * vector1 <<std::endl;
				std::cout<<"2(vector1 + vector2) ="<< 2 * (vector1 + vector2) <<std::endl;
				std::cout<<"vector1*=vector2 ="<< (vector1*=7) <<std::endl;
				std::cout<<"vector1�� ����ȭ�� Normalize(vector1)="<< vector1.Normalize() <<std::endl;
				std::cout<<"vector1�� ���̴� "<< vector1.Length() <<std::endl;
				std::cout<<"vector1�� vector2�� ������ "<< vector1.Dot(vector2) <<std::endl;
				std::cout<<"vector1�� vector2�� ���� ������ "<< vector2.PrepDot(vector2) <<std::endl;
			}break;
		case eMatrix33:
			{
				std::cout<<"\n2.3X3 ���(Matrix33) ����"<<std::endl;

				rsMatrix33 matrix1;
				rsMatrix33 matrix2(matrix1);
			}break;

		default:
			{
				std::cout<<"\n�߸��� �Է��Դϴ�.\n"<<std::endl;
			}break;
		}
	}
	return 1;
}