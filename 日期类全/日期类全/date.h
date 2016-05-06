#ifndef __DATE_H__
#define __DATE_H__

#include<iostream>

using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);

    int DaysOfMonth();//һ���µ�����
	bool IsInvalid();//�жϷǷ�����
	bool IsLeapYear();//�ж�����
	void ToCorrectDate();//����Ϊ��ȷ������
	Date& operator+=(int days);
	Date& operator-=(int days);

    friend ostream& operator<<(ostream& output, const Date& d);//������������
	friend bool operator>(const Date& d1, const Date& d2);
	friend bool operator>=(const Date& d1, const Date& d2);
	friend bool operator<=(const Date& d1, const Date& d2);
	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator==(const Date& d1, const Date& d2);
	friend bool operator!=(const Date& d1, const Date& d2);
	
	friend Date operator+(const Date& d, int days);//����+����
	friend Date operator-(const Date& d, int days);//����-����
	friend int operator-(const Date& d1, const Date& d2);//����-����

private:
	int _year;
	int _month;
	int _day;

};

#endif