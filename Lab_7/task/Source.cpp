#include <iostream>
#include "Header.h"
#include "windows.h"

using namespace std;

void printMenu() {
	cout << "1 - ������ �������;" << endl;
	cout << "2 - ����� �������;" << endl;
	cout << "3 - ����� ��������;" << endl;
	cout << "0 - ���������� ���������;" << endl;
	cout << endl;
}
string enterstr() {
	string temp;
	cin >> temp;

	return temp;
}

int main(){
	setlocale(LC_ALL, "");

	HashTable* table = new HashTable();
	char controlButton;

	cout << "\n" << (*table).getSize();

	while (true) {
		system("cls");
		printMenu();

		cout << (": ");

		cin >> controlButton;

		switch (controlButton) {

		case  ('1'):
			system("cls");

			cout << "������� �������: ";
			(*table).insert(enterstr());

			cout << ("\n\t������� ��������...") << endl;
			Sleep(2000);
			system("cls");
			break;

		case ('2'):
			system("cls");

			(*table).print();

			Sleep(2000);
			system("cls");
			break;

		case ('3'):
			system("cls");

			cout << ("������� �������: ") << endl;
			cout << "\n" << (*table).find(enterstr());

			Sleep(2000);
			system("cls");
			break;

		case ('0'):
			system("cls");

			cout << ("\t��������� ���������\n") << endl;

			Sleep(2000);
			system("cls");

			exit(0);
			break;

		default:
			system("cls");

			cout << ("\t������!!!") << endl;

			Sleep(2000);
			system("cls");
			break;
		}
	}
}