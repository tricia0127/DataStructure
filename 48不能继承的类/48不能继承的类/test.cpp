#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


//�����캯����Ϊ˽�к���
class SealedClass1
{
public:
	static SealedClass1* GetInstance()
	{
		return new SealedClass1();
	}
	static void DeleteInstance(SealedClass1* pInstance)
	{
		delete pInstance;
	}
private:
	SealedClass1()
	{}
	~SealedClass1()
	{}
};


//��������̳�

template<class T>
class MakeClass
{
	friend T;
private:
	MakeClass(){}
	~MakeClass(){}
};

class SealedClass2 :virtual public MakeClass<SealedClass2>
{
public:
	SealedClass2()
	{}
	~SealedClass2()
	{}
};
class B :public SealedClass2
{

};


int main()
{
	SealedClass1* a=SealedClass1::GetInstance();
	B b;
	getchar();
	return 0;
}