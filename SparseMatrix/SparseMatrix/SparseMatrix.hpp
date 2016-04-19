#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Triple//��Ԫ��ṹ
{
	Triple(const T& value=T(), size_t row=0, size_t col=0)//��Ԫ��Ĭ�Ϲ��캯��
	:_value(value)
	, _row(row)
	, _col(col)
	{}
	T _value;
	size_t _row;
	size_t _col;
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix(size_t m, size_t n, const T& invaild)//����ϡ������캯��
		:_RowSize(n)
		, _ColSize(m)
		, _invaild(invaild)
	{}
	SparseMatrix(const T* a, size_t m, size_t n, const T& invaild)//ϡ������캯����ѹ���洢
	:_RowSize(m)
	, _ColSize(n)
	, _invaild(invaild)
	{
		int index = 0;
		for (size_t i = 0; i < m; i++)//�����ȴ洢
		{
			for (size_t j = 0; j < n; j++)//��������
			{
				if (a[i*n + j] != _invaild)//���þ���Ԫ������Чֵ
				{
					_a.push_back(Triple<T>(a[i*n + j],i,j));//�洢Ԫ��
				}
			}
		}
	}
	void display()//��ӡ����
	{
		int index = 0;//vetcorԪ���±�
		for (size_t i = 0; i < _RowSize; i++)
		{
			for (size_t j = 0; j < _ColSize; j++)
			{
				if (index != _a.size() && _a[index]._row == i && _a[index]._col == j)
					//����Ԫ�����и�λ��Ԫ�أ�Ԫ�����ж���ȣ���λ��Ԫ������Чֵ��
				{
					cout << _a[index++]._value << " ";//��ӡ��Ԫ��
				}
				else
					cout << _invaild << " ";//����λ��Ԫ�ز�����Чֵ�����ӡ����Чֵ
			}
			cout << endl;
		}
	}
	SparseMatrix<T> Transport()//����ת��
	{
		int index = 0;
		SparseMatrix<T> tmp(_RowSize, _ColSize, _invaild);//����һ��ת�ú�ľ���Ĵ�С
		for (size_t j = 0; j < _RowSize; j++) //
		{
			for (size_t i = 0; i < _a.size(); i++)//����vector
			{
				if (_a[i]._col == j)//��
				{
					tmp._a.push_back(Triple<T>(_a[i]._value, _a[i]._col, _a[i]._row));
					index++;
				}
			}

		}
		return tmp;
	}
	SparseMatrix<T> FastTransport()
	{
		int index = 0;
		SparseMatrix<T> tmp(_RowSize, _ColSize, _invaild);
		int *RowCount=new int[tmp._RowSize];//ÿ����ЧԪ�صĸ���
		int *RowStart=new int[tmp._RowSize];//ÿ����ЧԪ����tmp._a�е���ʼλ��
		memset(RowCount, 0, sizeof(int)*tmp._RowSize);//��ʼ��
		memset(RowStart, 0, sizeof(int)*tmp._RowSize);

		while (index != _a.size())//��������RowCount������
		{
			RowCount[_a[index]._col]++;
			index++;
		}

		index = 1;
		RowStart[0] = 0;//��һ����Ч������ʼλ��Ϊ0
		while (index < tmp._RowSize)//��������RowSize������
		{
			RowStart[index] = RowStart[index - 1] + RowCount[index - 1];
			//ÿ����ЧԪ�صĸ�������һ����ЧԪ�ص���ʼλ��+��һ����ЧԪ�صĸ���
			index++;
		}
		
		//ѹ���洢ת�ú�ľ���
		index = 0;
		tmp._a.resize(_a.size());//��tmp._a�Ĵ�С��Ϊ��������ЧԪ�صĸ���
		while (index < _a.size())
		{
			Triple<T> t(_a[index]._value, _a[index]._col, _a[index]._row);
			//������ʱ��Ԫ�飬����Ԫ�������ԭ��������У�����ԭ��������У�ֵ����


			tmp._a[RowStart[_a[index]._col]++] = t;
			index++;
            
			//(1) _a[index]._col ȡ��_a�е�Ԫ�ص���
			//(2)RowStart[_a[index]._col] ��Ԫ�ص�����ΪRowStart���±꣨_a��Ԫ�ص�����tmp._a��Ԫ�ص��У�
			//�õ���ֵ�Ǹ�Ԫ����tmp._a�еĴ洢λ��
			//RowStart[_a[index]._col]++  ��ʾ��һ���ж��Ԫ�أ���ô���δ洢�ڸ�����ЧԪ�ص�λ�õĺ���
			
		}
		return tmp;
	}
protected:
	vector<Triple<T> > _a;//�������洢��Ԫ��Ԫ��
	size_t _RowSize;//��������
	size_t _ColSize;//��������
    T _invaild;//����Чֵ
};