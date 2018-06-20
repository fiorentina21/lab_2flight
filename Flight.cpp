//����� ���� � flight
#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "MyDate.h"
#include "Flight.h"
using namespace std;

Flight::Flight()
	{
		string location = "";
		string person = "";
		int flynum = 0;
		int bagplace = 0;
		MyDate execdate;
		int bagweight = 0;
	}

Flight Flight::ChangeFlight(Flight &result)
{
	int n;
	cout << "�������� ���� �� ������� ��� ���������: " << endl;
	cout << "1 - �������� ����� ����������" << endl;
	cout << "2 - �������� ������� ��������� " << endl;
	cout << "3 - �������� ����� �����" << endl;
	cout << "4 - �������� ���������� ���� ������" << endl;
	cout << "5 - �������� ���� ������" << endl;
	cout << "6 - �������� ��� ������" << endl;
	n = InputNumber(0, 6, "��� �����:");
	switch (n)
	{
	case 1: 
		result.location = InputInformation("������� ����� ����� ����������: ");
		break;
	case 2:
		result.person = InputInformation("������� ������� ���������: ");
		break;
	case 3:
		result.flynum = InputNumber(0, 100, "������� ����� ����� (0 - 100): ");
		break;
	case 4:
		result.bagplace = InputNumber(0, 80, "������� ���������� ���� ������ (0-80): ");
		break;
	case 5:
		result.execdate.InputDate();
		break;
	case 6:
		result.bagweight = InputNumber(0, 40, "������� ��� ������ (0 - 40): ");
		break;
	default:
		break;

	}
		return result;
}

	// ������������� �������� ���������
Flight& Flight::operator = (Flight c)
{
		location = c.location;
		person = c.person;
		flynum = c.flynum;
		bagplace = c.bagplace;
		execdate = c.execdate;
		bagweight = c.bagweight;
		return (*this);
}

// ������� ����� ��������� � �������
Flight InputScreenFlight()
{
	Flight c;
	c.location = InputInformation("������� ����� ����������: ");
	c.person = InputInformation("������� ������� ���������: ");
	c.flynum = InputNumber(0, 100, "������� ����� �����: ");
	c.bagplace = InputNumber(0, 80, "������� ���������� ���� ������: ");
	c.execdate.InputDate();
	c.bagweight = InputNumber(0, 40, "������� ��� ������: ");
	return c;
}

// ������� ������ ��������� �� �������
void OutputScreenFlight(Flight c)
{
	cout << "����� ����������: " << c.location << endl;
	cout << "������� ���������: " << c.person << endl;
	cout << "����� �����: " << c.flynum << endl;
	cout << "���������� ���� ������: " << c.bagplace << endl;
	cout << "����: " << c.execdate.ToString() << endl;
	cout << "��� ������: " << c.bagweight << endl;
}



string ToString(Flight c, int i)
{
	string result = "������ � " + to_string(i) + "\n" + "����� ����������: " + c.location + "\n" + "������� ���������: " + c.person + "\n" + "����� �����: " + to_string(c.flynum) + "\n" + "���������� ���� ������: " + to_string(c.bagplace) + "\n" + "���� � ����� ������: " + c.execdate.ToString() + "\n" + "��� ������: " + to_string(c.bagweight) + "\n";
	return result;
}

////���������� ��������� �� ������
Flight ReadFromString(ifstream& input)
{
	Flight result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����������: ";
			result.location = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ���������: ";
			result.person = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �����: ";
			result.flynum = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� ���� ������: ";
			result.bagplace = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���� � ����� ������: ";
			result.execdate = result.execdate.FromString(s.substr(wrd.length(), s.length()));


		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ������: ";
			result.bagweight = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}


// ����� ������� �������� �� ���������� ��������
// typesearch - ��� ������
//1 - �� ������ �����
//2 - �� �����
//3 - �� ����
bool SearchElement(Flight m, Flight n, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		return (m.flynum == n.flynum);
	case 2:
		return (m.location == n.location);
	case 3:
		return (m.bagweight == n.bagweight);
	case 4:
		return (m.execdate == n.execdate);
	default:
		return false;
	}
}

// ���� �������� ������ � ����������� �� ���������� ���� 

Flight InputChangeTypeSearch(int typesearch)
{
	Flight result;
	switch (typesearch)
	{
	case 1:
		result.flynum = InputNumber(0, 100, "������� ����� �����: ");
		return result;
	case 2:
		result.location = InputInformation("������� ����� ����������: ");
		return result;
	case 3:
		result.bagweight = InputNumber(0, 100, "������� ��� ������: ");
		return result;
	case 4:
		result.execdate.InputDate();
		return result;
	default:
		return result;
	}
}

// ��������� �������� � ����������� �� ���������� ���� ��� ����������

int Sorte(Flight n, Flight m, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		if (n.flynum > m.flynum) return 1;
		else if (n.flynum < m.flynum) return -1;
		else return 0;
	case 2:
		if (n.location > m.location) return 1;
		else if (n.location < m.location) return -1;
		else return 0;
	case 3:
		if (n.bagweight > m.bagweight) return 1;
		else if (n.bagweight < m.bagweight) return -1;
		else return 0;
	case 4:
		if (n.execdate > m.execdate) return 1;
		else if (n.execdate < m.execdate) return -1;
		else return 0;
	default:
		return -2;
	}
}




