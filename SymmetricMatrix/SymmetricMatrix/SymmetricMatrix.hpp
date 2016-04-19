#pragma once

#include<iostream>
using namespace std;

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(const T* a, size_t size, size_t n)//���캯����ѹ���洢����Ԫ��
	:_a(new T[n*(n + 1) / 2])//���ٿռ䣬������Ԫ��һ���У�n*(n + 1) / 2����
	, _size(n*(n + 1) / 2)//����һά�����С
	, _n(n)//�����С��ά����
	{
		int index = 0;
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)//����
			{
				if (i >= j)   //��Ϊ������Ԫ��
					_a[index++] = a[i*n + j];//�洢
				else;         //������������Ԫ��
					break      //ֱ������ѭ�����˲����Ż���������������Ԫ�أ������ʣ��Ԫ��һ��Ҳ����������Ԫ�أ�
			}
		}
	}
	~SymmetricMatrix()//��������
	{
		if (_a)
			delete[] _a;
	}
	T& Access(int i,int j)//����Ԫ��
	{
		if (i < j)
			swap(i, j);
		return _a[i*(i + 1) / 2 + j];//���ݶԳƾ����ѹ���洢�Ķ�Ӧ��ϵ����Ԫ��
	}
	void display()//��ԭ��ӡ����
	{
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)//��Ҫ��ӡ������Ԫ�أ���ֱ�Ӹ��ݶԳƾ����ѹ���洢�Ķ�Ӧ��ϵ����Ԫ�أ���ӡ
					cout << _a[i*(i + 1) / 2 + j] << " ";
				else      //����ӡ������Ԫ�أ��򽻻�Ԫ�����У����ݶԳƾ������ʣ����Ϳ��Կ�����Ԫ����������Ԫ�ز���ӡ
					cout << _a[j*(j + 1) / 2 + i] << " ";
			}
			cout << endl;
		}
	}
protected:
	T* _a;
	size_t _size;
	size_t _n;
};
