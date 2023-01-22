#include "DataManager.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>


int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	DataManager<int,std::string> a;
	std::string info1;
	std::cout << "������� ����������\n";
	std::cin >> info1;
	a.addInfo(info1);
	std::cout << "������� ����������\n";
	std::cin >> info1;
	a.addInfo(info1);
	a.printMap();
	int ID;
	std::cout << "������� ����� ID ��� ��������\n";
	std::cin >> ID;
	a.eraseInfo(ID);
	a.printMap();
	std::cout << "������� ID ��� ������ ����������\n";
	std::cin >> ID;
	std::cout << "�������  ����� ����������\n";
	std::cin >> info1;
	a.changeInfo(ID, info1);
	a.printMap();
	std::cout << "������� ID ��� ������ ����������\n";
	std::cin >> ID;
	a.findInfo(ID);
	std::cout << "���������� ��������: \n";
	std::cout << a.mostSearchedKey();
	DataManager<int, double> b;
	double info2;
	std::cout << "������� ����������\n";
	std::cin >> info2;
	b.addInfo(info2);
	std::cout << "������� ����������\n";
	std::cin >> info2;
	b.addInfo(info2);
	b.printMap();
	int ID2;
	std::cout << "������� ����� ID ��� ��������\n";
	std::cin >> ID2;
	b.eraseInfo(ID2);
	b.printMap();
	std::cout << "������� ID ��� ������ ����������\n";
	std::cin >> ID2;
	std::cout << "�������  ����� ����������\n";
	std::cin >> info2;
	b.changeInfo(ID2, info2);
	b.printMap();
	std::cout << "������� ID ��� ������ ����������\n";
	std::cin >> ID2;
	b.findInfo(ID2);
	std::cout << "���������� ��������: \n";
	std::cout << b.mostSearchedKey();
}