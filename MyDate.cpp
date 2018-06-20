#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"

//������ ����
// �������� �������� �� ��� ����������
bool MyDate::IsLeap(int year)
{
	if (year % 4)
		return false;
	if (year % 100)
		return true;
	return !(year % 400);
}

// �������� ���� �� ������������
bool MyDate::CorrectDate(int day, int month, int year, string &message) {

	// ���� ��� ���������                            ���� �� ����������
	if ((month == 2 && day > 29 && IsLeap(year)) || (month == 2 && day > 28 && !IsLeap(year)))
	{
		message = "�������� ���-�� ���� � �������!";
		return false;
	}
	//���-�� ���� � ������
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			message = "�������� ���-�� ���� � ������!";
			return false;
		}
	}
	return true;
}

// ����������� �� ���������
MyDate::MyDate()
{
	int day = 1;
	int month = 1;
	int year = 1970;
}

// ���� ���� � �������
void MyDate::InputDate()
{
	bool correct_date = true; // ��������� �� ��������� ����
	string message = "";  // ��������� � ������� ������
	do
	{
		if (!correct_date)
			cout << message << endl;
		day = InputNumber(1, 31, "���� ����:\n������� ���� (1-31): ");
		month = InputNumber(1, 12, "������� ����� ������ (1-12): ");
		year = InputNumber(1970, 2100, "������� ��� (1970-2100):");
		hours = InputNumber(0, 23, "���� �������:\n������� ���� (0-23):");
		minutes = InputNumber(0, 59, "������� ������ (0-59):");
		correct_date = CorrectDate(day, month, year, message);
	} while (!correct_date);  // ��������� ���� ���� �� ���������� ����
}

// ������� ���� � ������ (��� ����������� ������ � ����)
string MyDate::ToString()
{
	return (to_string(day) + ' ' + to_string(month) + ' ' +
		to_string(year) + ' ' + to_string(hours) + ':' + to_string(minutes));
}

// ������������� �������� ���������
bool MyDate::operator == (const MyDate &c)
{
	return ((day == c.day) && (month == c.month) && (year == c.year) && (hours = c.hours) && (minutes = c.minutes));
}

// ����������� �����������
MyDate& MyDate::operator = (MyDate c)
{
	day = c.day;
	month = c.month;
	year = c.year;
	hours = c.hours;
	minutes = c.minutes;

	return (*this);
}

// ������������� �������� ������
bool MyDate::operator > (const MyDate &c)
{
	return ((year > c.year) || ((year == c.year) && (month > c.month)) || ((year == c.year) && (month == c.month) && (day>c.day)));
}

// ������������� �������� ������
bool MyDate::operator < (const MyDate &c)
{
	return ((year < c.year) || ((year == c.year) && (month < c.month)) || ((year == c.year) && (month == c.month) && (day<c.day)));
}

//���������� ��������� "����" �� ������ 
// ������:
// ���� ����� ���
MyDate MyDate::FromString(string str)
{
	MyDate result;
	try
	{
		istringstream is(str);
		string s;
		if (getline(is, s, ' '))
			result.day = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.month = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.year = atoi(s.c_str());
		if (getline(is, s, ':'))
			result.hours = atoi(s.c_str());
		if (getline(is, s, ' '))
			result.minutes = atoi(s.c_str());
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}