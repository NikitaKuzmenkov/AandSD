#include <iostream>
#include "Header.h"
#include "windows.h"

using namespace std;

void printMenu() {
	cout << "1 - Ввести элемент;" << endl;
	cout << "2 - Вывод таблицы;" << endl;
	cout << "3 - Поиск элемента;" << endl;
	cout << "0 - Завершение программы;" << endl;
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

			cout << "Введите элемент: ";
			(*table).insert(enterstr());

			cout << ("\n\tЭлемент добавлен...") << endl;
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

			cout << ("Введите элемент: ") << endl;
			cout << "\n" << (*table).find(enterstr());

			Sleep(2000);
			system("cls");
			break;

		case ('0'):
			system("cls");

			cout << ("\tПрограмма закончена\n") << endl;

			Sleep(2000);
			system("cls");

			exit(0);
			break;

		default:
			system("cls");

			cout << ("\tОшибка!!!") << endl;

			Sleep(2000);
			system("cls");
			break;
		}
	}
}