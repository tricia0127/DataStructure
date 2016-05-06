#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include<iostream>

using namespace std;

class Complex
{
public:
	
	Complex(float real = 1, float imag = 1):_real(real), _imag(imag){}//���캯��
	Complex(const Complex& complex);//�������캯��
	~Complex(){};//��������
	Complex& operator=(const Complex& complex);//��ֵ����������
	
	bool operator==(const Complex& complex);
	bool operator!=(const Complex& complex);

	Complex operator+(const Complex& complex);
    Complex& operator++();//ǰ��++
	Complex operator++(int);//����++
	Complex& operator+=(const Complex& complex);

    Complex operator-(const Complex& complex);
	Complex& operator-=(const Complex& complex);
	Complex& operator--();//ǰ��--
	Complex operator--(int);//����--

	Complex operator*(const Complex& complex);
	Complex& operator*=(const Complex& complex);

	Complex operator/(const Complex& complex);
	Complex& operator/=(const Complex& complex);

	friend ostream& operator<<(ostream& output, const Complex& complex);//�������������
    bool operator>(const Complex& complex);
	bool operator>=(const Complex& complex);
	bool operator<(const Complex& complex);
	bool operator<=(const Complex& complex);

private:
	float _real;
	float _imag;
};



#endif//__COMPLEX_H__