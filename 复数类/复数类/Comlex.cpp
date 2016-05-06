#include"Complex.h"

Complex::Complex(const Complex& complex)//�������캯��
{
	_real = complex._real;
	_imag = complex._imag;
}

Complex& Complex::operator=(const Complex& complex)//��ֵ����������
{
	cout << "��ֵ����������" << endl;
	if (this != &complex)
	{
		_real = complex._real;
		_imag = complex._imag;
	}
	return *this;
}

ostream& operator<<(ostream& output, const Complex& complex)//�������������
{
	
	 output << "(" << complex._real;
	if (complex._imag >= 0)
	{
		output << "+";
	}
	output << complex._imag << "i)";

	 return output;
}
//�������ܱȽϴ�С������Ƚ�ģ�Ĵ�С
bool Complex::operator>(const Complex& complex)
{
	return (_real*_real + _imag*_imag) > (complex._real*complex._real*complex._imag*complex._imag);

}
bool Complex::operator>=(const Complex& complex)
{
	return (_real*_real + _imag*_imag) >= (complex._real*complex._real*complex._imag*complex._imag);

}
bool Complex::operator<(const Complex& complex)
{
	return (_real*_real + _imag*_imag) < (complex._real*complex._real*complex._imag*complex._imag);
}
bool Complex::operator<=(const Complex& complex)
{
	return (_real*_real + _imag*_imag) <= (complex._real*complex._real*complex._imag*complex._imag);
}

bool Complex::operator==(const Complex& complex)
{
	return (_real == complex._real) && (_imag == complex._imag);
}
bool Complex::operator!=(const Complex& complex)
{
	return !(*this==complex);
}

Complex Complex::operator+(const Complex& complex)
{
	Complex c(*this);
	c._real +=complex._real;
	c._imag +=complex._imag;
	return c;
}

Complex& Complex::operator++()
{
	++_real;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex c;
	c._real=_real++;
	return c;	
}

Complex& Complex::operator+=(const Complex& complex)
{
	_real += complex._real;
	_imag += complex._imag;
	return *this;
}

Complex Complex::operator-(const Complex& complex)
{
	return Complex(_real - complex._real, _imag - complex._imag);
}

Complex& Complex::operator-=(const Complex& complex)
{
	_real -= complex._real;
	_imag -= complex._imag;
	return *this;
}

Complex& Complex::operator--()
{
	--_real;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex c;
	c._real=_real--;
	return c;
}

Complex Complex::operator*(const Complex& complex)
{
	Complex c;
	c._real = _real*complex._real - _imag*complex._imag;
	c._imag = _real*complex._imag + _imag*complex._real;
	return c;
}

Complex& Complex::operator*=(const Complex& complex)
{
	float real = _real;
	_real = _real*complex._real - _imag*complex._imag;
	_imag = _imag*complex._real + real*complex._imag;
	return *this;
}

Complex Complex::operator/(const Complex& complex)
{
	return Complex((_real*complex._real + _imag*complex._imag) / 
	                  (complex._real*complex._real + complex._imag*complex._imag),
					  (_imag*complex._real - _real*complex._imag)/
					  (complex._real*complex._real + complex._imag*complex._imag));
	/*Complex c;
	c._real = (_real*complex._real + _imag*complex._imag)*1.0 /
		(complex._real*complex._real + complex._imag*complex._imag);
	c._imag = (_imag*complex._real - _real*complex._imag)*1.0 /
		(complex._real*complex._real + complex._imag*complex._imag);
	return c;*/

}

Complex& Complex::operator/=(const Complex& complex)
{
	float real = _real;
	_real = (_real*complex._real + _imag*complex._imag)/
	(complex._real*complex._real + complex._imag*complex._imag);
	_imag = (_imag*complex._real - real*complex._imag) /
	(complex._real*complex._real + complex._imag*complex._imag);
	return *this;

}



