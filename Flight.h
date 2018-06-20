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
using namespace std;

class Flight {
public:
	// ����� ����������
	string location;
	// ������� ���������
	string person;
	// ����� �����
	int flynum;
	// ����� � ������
	int bagplace;
	// ���� � �����
	MyDate execdate;
	// ��� ������
	int bagweight;

	// ����������� �� ���������
	Flight();


	// ��������� ���������
	Flight ChangeFlight(Flight &result);

	// ������������� �������� ���������
	Flight& operator = (Flight c);
};

// ������� ����� ��������� � �������
Flight InputScreenFlight();

// ������� ������ ��������� �� �������
void OutputScreenFlight(Flight c);




//������� ��������� � ������
string ToString(Flight c, int i);

////���������� ��������� �� ������
Flight ReadFromString(ifstream& input);

// ����� ������� �������� �� ���������� ��������
// typesearch - ��� ������
//1 - �� ������ �����
//2 - �� �����
//3 - �� ����
bool SearchElement(Flight m, Flight n, int typesearch);

// ���� �������� ������ � ����������� �� ���������� ���� 

Flight InputChangeTypeSearch(int typesearch);

// ��������� �������� � ����������� �� ���������� ���� ��� ����������

int Sorte(Flight n, Flight m, int typesearch);



