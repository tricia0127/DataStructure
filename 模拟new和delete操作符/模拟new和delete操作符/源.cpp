#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
using namespace std;

class A
{
public:
	A(int a = 0,int b = 0)
		:_a(a)
		, _b(b)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
	int _b;
};

int main()
{
	/*A *pa = new A[10];
	delete[] pa;*/
	A *pa = (A*)operator new(10 * sizeof(A)+4);
	*((int *)pa) = 10;//����һ����ռ��4���ֽڣ��ռ丳ֵΪ��������ĸ���
	A *pStart = (A*)((int *)pa + 1);
	//new���������صĵ�ַ�ǿ��ٵ������ռ�������4���ֽ�֮��ĵ�ַ
	for (int i = 0; i < 10; i++)
	{
		new(pStart + i)A(1, 0);// new���ʽ��placeement new�� ��ʽ(place_address)type(initializer-list)
	}
	int count = *((int *)pStart - 1);
	//���㿪�ٵ������ڴ�ռ���ǰ���ռ��4���ֽڵĿռ���������ͷſռ�֮ǰ�������������Ĵ���
	for (int i = 0; i < count; i++)
	{
		pStart[i].~A();//delete���ͷ�ǰ�Զ�������������
	}
	operator delete[]((int *)pStart - 1);//����operator delete[](char *)�����ͷ��ڴ�ռ�
	system("pause");
	return 0;
}