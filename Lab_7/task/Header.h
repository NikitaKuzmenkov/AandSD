#pragma once

#include <iostream>
#include <string>

#define ALLSYMB "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"

using namespace std;

int Atoi(string s, int p) {
	int i, a, digit[256] = { 0 };

	for (i = 0; ALLSYMB[i]; i++)
		digit[ALLSYMB[i]] = i;

	for (i = a = 0; s[i]; i++)
		a = a * p + digit[s[i]];

	return a;
}

class HashTable {
private:
	string* hashArray;
	int arraySize;

public:
	HashTable() {
		arraySize = 133;
		hashArray = new string[arraySize];
	}
	int getSize() {
		return arraySize;
	}
	int hashFunc(string key) {
		return Atoi(key, 36);
	}
	void print() {
		for (int i = 0; i < arraySize; i++)
			if (hashArray[i] != "") {
				cout << hashArray[i] << endl;
			}
	}
	void insert(string item) {
		int index = hashFunc(item);

		while (hashArray[index] != "") {
			index++;
			index %= arraySize;
		}

		hashArray[index] = item;
	}
	int find(string key) {
		int index = hashFunc(key);

		while (hashArray[index] != "") {
			if (hashArray[index] == (key))
				return index;

			index++;
			index %= arraySize;
		}

		return -1;
	}
};