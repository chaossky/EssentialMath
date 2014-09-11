#include "vector.h"
#include "matrix.h"

int main()
{
	enum EDATA_TYPE
	{
		eVector2 = 1,
		eVector3,
		eVector4,
		eMatrix33,
		eMatrix44,
		eMax
	};

	int UseType = 1;

	while(UseType != 0)
	{
		std::cout<<"\n테스트할 자료형을 선택하세요."<<std::endl;
		std::cout<<"1 -> 2차원벡터(Vector2)"<<std::endl;
		std::cout<<"2 -> 3차원벡터(Vector3)"<<std::endl;
		std::cout<<"3 -> 4차원벡터(Vector4)"<<std::endl;
		std::cout<<"4 -> 3X3 행렬(Matrix33)"<<std::endl;
		std::cout<<"5 -> 4X4 행렬(Matrix44)"<<std::endl;
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
				std::cout<<"\n1.2차원벡터(Vector2) 선택"<<std::endl;

				rsVector2 vector1;
				vector1.SetValue(10.0f, 20.0f);
				rsVector2 vector2(11.0f, 12.0f);

				std::cout<<"vector1=("<<vector1.x<<","<<vector1.y<<")입니다."<<std::endl;
				std::cout<<"vector2=("<<vector2.x<<","<<vector2.y<<")입니다."<<std::endl;
				std::cout<<"vector1의 길이는 "<< vector1.Length() <<std::endl;
				std::cout<<"vector2의 길이는 "<< vector2.Length() <<std::endl;
				std::cout<<"vector1 + vector2 ="<< vector1 + vector2 <<std::endl;
				std::cout<<"vector2 + vector1 ="<< vector2 + vector1 <<std::endl;
				std::cout<<"vector1 - vector2 ="<< vector1 - vector2 <<std::endl;
				std::cout<<"2(vector1) ="<< 2 * vector1 <<std::endl;
				std::cout<<"(vector1)2 ="<< vector1 * 2 <<std::endl;
				std::cout<<"(2+3)(vector1) ="<< (2+3) * vector1 <<std::endl;
				std::cout<<"2(vector1 + vector2) ="<< 2 * (vector1 + vector2) <<std::endl;
				std::cout<<"vector1*=vector2 ="<< (vector1*=7) <<std::endl;
				std::cout<<"vector1의 정규화는 Normalize(vector1)="<< vector1.Normalize() <<std::endl;
				std::cout<<"vector1의 길이는 "<< vector1.Length() <<std::endl;
				std::cout<<"vector1와 vector2의 내적은 "<< vector1.Dot(vector2) <<std::endl;
				std::cout<<"vector1와 vector2의 수직 내적은 "<< vector2.PrepDot(vector2) <<std::endl;
			}break;
		case eVector3:
			{
				std::cout<<"\n2.3차원벡터(Vector3) 선택"<<std::endl;

				rsVector3 vector1;
				vector1.SetValue(10.0f, 20.0f, 30.0f);
				rsVector3 vector2(11.0f, 12.0f, 13.0f);

				std::cout<<"vector1=("<<vector1.x<<","<<vector1.y<<","<<vector1.z<<")입니다."<<std::endl;
				std::cout<<"vector2=("<<vector2.x<<","<<vector2.y<<","<<vector1.z<<")입니다."<<std::endl;
				std::cout<<"vector1의 길이는 "<< vector1.Length() <<std::endl;
				std::cout<<"vector2의 길이는 "<< vector2.Length() <<std::endl;
				std::cout<<"vector1 + vector2 ="<< vector1 + vector2 <<std::endl;
				std::cout<<"vector2 + vector1 ="<< vector2 + vector1 <<std::endl;
				std::cout<<"vector1 - vector2 ="<< vector1 - vector2 <<std::endl;
				std::cout<<"2(vector1) ="<< 2 * vector1 <<std::endl;
				std::cout<<"(vector1)2 ="<< vector1 * 2 <<std::endl;
				std::cout<<"(2+3)(vector1) ="<< (2+3) * vector1 <<std::endl;
				std::cout<<"2(vector1 + vector2) ="<< 2 * (vector1 + vector2) <<std::endl;
				std::cout<<"vector1*=vector2 ="<< (vector1*=7) <<std::endl;
				std::cout<<"vector1의 정규화는 Normalize(vector1)="<< vector1.Normalize() <<std::endl;
				std::cout<<"vector1의 길이는 "<< vector1.Length() <<std::endl;
				std::cout<<"vector1와 vector2의 내적은 "<< vector1.Dot(vector2) <<std::endl;
			}break;
		case eVector4:
			{
				std::cout<<"\n3.4차원벡터(Vector4) 선택"<<std::endl;

				rsVector4 vector1;
				vector1.SetValue(10.0f, 20.0f, 30.0f, 40.0f);
				rsVector4 vector2(11.0f, 12.0f, 13.0f, 14.0f);

				std::cout<<"vector1=("<<vector1.x<<","<<vector1.y<<","<<vector1.z<<","<<vector1.w<<")입니다."<<std::endl;
				std::cout<<"vector2=("<<vector2.x<<","<<vector2.y<<","<<vector1.z<<","<<vector1.w<<")입니다."<<std::endl;
				std::cout<<"vector1의 길이는 "<< vector1.Length() <<std::endl;
				std::cout<<"vector2의 길이는 "<< vector2.Length() <<std::endl;
				std::cout<<"vector1 + vector2 ="<< vector1 + vector2 <<std::endl;
				std::cout<<"vector2 + vector1 ="<< vector2 + vector1 <<std::endl;
				std::cout<<"vector1 - vector2 ="<< vector1 - vector2 <<std::endl;
				std::cout<<"2(vector1) ="<< 2 * vector1 <<std::endl;
				std::cout<<"(vector1)2 ="<< vector1 * 2 <<std::endl;
				std::cout<<"(2+3)(vector1) ="<< (2+3) * vector1 <<std::endl;
				std::cout<<"2(vector1 + vector2) ="<< 2 * (vector1 + vector2) <<std::endl;
				std::cout<<"vector1*=vector2 ="<< (vector1*=7) <<std::endl;
				std::cout<<"vector1의 정규화는 Normalize(vector1)="<< vector1.Normalize() <<std::endl;
				std::cout<<"vector1의 길이는 "<< vector1.Length() <<std::endl;
				std::cout<<"vector1와 vector2의 내적은 "<< vector1.Dot(vector2) <<std::endl;
			}break;
		case eMatrix33:
			{
				std::cout<<"\n4.3X3 행렬(Matrix33) 선택"<<std::endl;

				rsMatrix33 matrix1;
				for(int i = 0; i < 9; i++)
				{
					matrix1.element[i] = 1.0f * i;
				}
				
				rsMatrix33 matrix2;
				matrix2 = matrix1;

				std::cout<<"matrix1="<<matrix1<<std::endl;
				std::cout<<"matrix2="<<matrix1<<std::endl;
				matrix1.SetElement(9.0f, 1, 2);
				std::cout<<"matrix1의 1행 2열 값을 9로 변경하면,"<<matrix1<<std::endl;
				std::cout<<"matrix1 - matrix2 = "<<matrix1 - matrix2<<std::endl;

				matrix1 -= matrix2;
				std::cout<<"matrix1 -= matrix2 한 후 matrix1 = "<<matrix1<<std::endl;
				std::cout<<"-(matrix1) = "<<-matrix1<<std::endl;
				std::cout<<"matrix1의 trace ="<<matrix1.trace()<<std::endl;

				matrix1.Identity();
				std::cout<<"matrix1를 단위행렬로 만들면 matrix1 ="<<matrix1<<std::endl;
				std::cout<<"5 * matrix1 = "<< 5 * matrix1 <<std::endl;
				std::cout<<"matrix1 * matrix2 = "<< matrix1 * matrix2 <<std::endl;

				rsVector3 vector1;
				vector1.SetValue(10.0f, 20.0f, 30.0f);
				std::cout<<"vector1 * matrix2 = "<< vector1 * matrix2 <<std::endl;

			}break;
		case eMatrix44:
			{
				std::cout<<"\n5.4X4 행렬(Matrix44) 선택"<<std::endl;
				std::cout<<"\n준비중..."<<std::endl;

			}break;
		default:
			{
				std::cout<<"\n잘못된 입력입니다.\n"<<std::endl;
			}break;
		}
	}
	return 1;
}