/* �10 ������ � ������ ��������� ��������� �������� ���� : ����� �����, ���� � ����� ������, 
����� ����������, ������� ���������, ���������� ���� ������, ��������� ��� ������.
����� �� ������ �����, ���� ������, ������ ����������, ���� ������.������� ������ ���� ������. */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include "HelpUtils.h"
#include "Operation.h"
#include "Flight.h"
using namespace std;


int Menu()
{
	cout << " --------------------����---------------------  " << endl;
	cout << "1 - �������� �������" << endl;
	cout << "2 - ������� �������" << endl;
	cout << "3 - �������� �������" << endl;
	cout << "4 - ����� �� �����" << endl;
	cout << "5 - ��������� � ���� " << endl;
	cout << "6 - �������� �����" << endl;
	cout << "7 - �������� �����" << endl;
	cout << "--------------------" << endl;
	cout << "8 - ������� ����������� �� �����" << endl;
	cout << "9 - ��������� ������������ � ����" << endl;
	cout << "0 - �����" << endl;
	int n = InputNumber(0, 9, "��� �����: ");
	cout << "\n";
	return n;
}

bool ChangeInputData()
{
	Task<Flight> task;
	bool change = true;
	cout << "�������� ���� �� ������� ����: " << endl;
	cout << "1 - ���������� ���������� � �������" << endl;
	cout << "2 - ���������� ���������� �� ����� " << endl;
	cout << "0 - �����" << endl;
	int changemenu = InputNumber(0, 2, "��� �����: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenFlight);
		break;

	case 2:
		change=task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
			{
				Flight elem;
				vector<Flight> subset;
				Flight search_elem;
				int numb;
				while (1)
				{
					int n = Menu();
					switch (n)
					{
					case 1:
						task.Add(InputScreenFlight());
						break;
		
					case 2:
						task.OutputScreen(task.vect, OutputScreenFlight);
						cout << "����� - " << task.size() << endl;
						task.Remove(InputNumber(0, task.size(), "\n������� ����� ���������� ��-�� (0 - ���� ���������� �������):"));
						break;
		
					case 3:
						task.OutputScreen(task.vect, OutputScreenFlight);
						cout << "����� - " << task.size() << endl;
						numb = InputNumber(0, task.size(), "\n������� ����� ����������� ��-�� (0 - ���� ���������� ��������): ");
						if (numb != 0)
						{ 
							task.vect[numb-1] = elem.ChangeFlight(task.vect[numb-1]);
							cout << "������ ��������!" << endl;
						}
						break;
		
					case 4:
						task.OutputScreen(task.vect,OutputScreenFlight);
						break;
		
					case 5:
						task.OutputFile(task.vect,ToString);
						break;

					case 6:
						numb = InputNumber(1, 4, "�������� ��� ������:\n 1 - �� ������ �����\n 2 - �� ������ ����������\n 3 - �� ���� ������\n 4 - �� ���� � ������� ������ \n��� �����: ");
						search_elem = InputChangeTypeSearch(numb);
						subset = task.LinearySearch(search_elem,SearchElement,numb);
						if (subset.size() != 0)
							task.OutputScreen(subset, OutputScreenFlight);
						else
							cout << "�������� �� �������" << endl;
						break;
		
					case 7:
						numb = InputNumber(1, 3, "�������� ��� ������:\n 1 - �� ������ �����\n 2 - �� ������ ����������\n 3 - �� ���� ������\n 4 - �� ���� � ������� ������ \n��� �����: ");
						search_elem = InputChangeTypeSearch(numb);
						subset = task.BinarySearch(numb,search_elem, Sorte,SearchElement);
						if (subset.size() != 0)
							task.OutputScreen(subset, OutputScreenFlight);
						else
							cout << "�������� �� �������" << endl;
						break;
		
					case 8:
						task.OutputScreen(subset,OutputScreenFlight);
						break;
		
					case 9:
						task.OutputFile(subset,ToString);
						break;

		
					default:
						cout << "����� " << endl; exit(0);
						break;
		
					}
				}
			}
			system("pause");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	ChangeInputData();
}