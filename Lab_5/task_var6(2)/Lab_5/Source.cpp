#include <windows.h>
#include<iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main(){
	setlocale(LC_ALL, "");

	srand(time(0));

	fstream f_0, f_1, f_2, f_3, f_4, f_5, f_6;

	f_0.open("f_0.txt", fstream::out | fstream::in | ios_base::trunc);

	const int N = 15;
	int buf_1;

	for (int i = 0; i < N; i++){
		buf_1 = 1 + rand() % 999;
		f_0 << " " << buf_1;
	}

	f_0.seekp(0);
	f_1.open("f_1.txt", fstream::out | fstream::in | ios_base::trunc);
	f_2.open("f_2.txt", fstream::out | fstream::in | ios_base::trunc);
	f_3.open("f_3.txt", fstream::out | fstream::in | ios_base::trunc);
	f_4.open("f_4.txt", fstream::out | fstream::in | ios_base::trunc);
	f_5.open("f_5.txt", fstream::out | fstream::in | ios_base::trunc);
	f_6.open("f_6.txt", fstream::out | fstream::in | ios_base::trunc);

	int buf_2;

	while (1){
		if (f_0.eof())
			break;
		f_0 >> buf_2;
		f_1 << " " << buf_2;
		if (f_0.eof())
			break;
		f_0 >> buf_2;
		f_2 << " " << buf_2;
		if (f_0.eof())
			break;
		f_0 >> buf_2;
		f_3 << " " << buf_2;
	}

	f_1.seekp(0);
	f_2.seekp(0);
	f_3.seekp(0);

	for (int n = 1;; n *= 3){
		bool emptyf_5 = true;
		int numfile = 4;
		char ch;
		int x_min;
		while (!(f_1.eof() && f_2.eof() && f_3.eof())){
			int x1, x2, x3;
			f_1 >> x1;
			f_2 >> x2;
			f_3 >> x3;
			int cr1 = 0, cr2 = 0, cr3 = 0;
			for (int i = 0; i < n * 3; i++){
				if (x1 > x2 && x1 > x3 && x1 != NULL){
					x_min = 1;
				}
				else{
					if (x2 > x3 && x2 != NULL){
						x_min = 2;
					}
					else{
						if (x3 != NULL){
							x_min = 3;
						}
						else{
							x_min = 0;
						}
					}
				}
				switch (numfile){
				case 4:
					switch (x_min){
					case 1:{
						f_4 << " " << x1;
						cr1++;
						if (cr1 >= n || f_1.eof())
							x1 = NULL;
						else{
							f_1 >> x1;
						}
					}
					break;
					case 2:{
						f_4 << " " << x2;
						cr2++;
						if (cr2 >= n || f_2.eof())
							x2 = NULL;
						else{
							f_2 >> x2;
						}
					}
					break;
					case 3:{
						f_4 << " " << x3;
						cr3++;
						if (cr3 >= n || f_3.eof())
							x3 = NULL;
						else{
							f_3 >> x3;
						}
					}
					break;
					}
					break;
				case 5:
					switch (x_min){
					case 1:
						f_5 << " " << x1;
						emptyf_5 = false;
						cr1++;
						if (cr1 >= n || f_1.eof())
							x1 = NULL;
						else{
							f_1 >> x1;
						}
						break;
					case 2:
						f_5 << " " << x2;
						emptyf_5 = false;
						cr2++;
						if (cr2 >= n || f_2.eof())
							x2 = NULL;
						else{
							f_2 >> x2;
						}
						break;
					case 3:
						f_5 << " " << x3;
						emptyf_5 = false;
						cr3++;
						if (cr3 >= n || f_3.eof())
							x3 = NULL;
						else{
							f_3 >> x3;
						}
						break;
					}
					break;
				case 6:
					switch (x_min){
					case 1:
						f_6 << " " << x1;
						cr1++;
						if (cr1 >= n || f_1.eof())
							x1 = NULL;
						else{
							f_1 >> x1;
						}
						break;
					case 2:
						f_6 << " " << x2;
						cr2++;
						if (cr2 >= n || f_2.eof())
							x2 = NULL;
						else{
							f_2 >> x2;
						}
						break;
					case 3:
						f_6 << " " << x3;
						cr3++;
						if (cr3 >= n || f_3.eof())
							x3 = NULL;
						else{
							f_3 >> x3;
						}
						break;
					}
					break;
				}
			}
			if (f_1.eof() && f_2.eof() && f_3.eof())
				break;
			numfile++;
			if (numfile == 7)
				numfile = 4;
		}
		f_1.close();
		f_2.close();
		f_3.close();
		f_1.open("f_1.txt", fstream::out | fstream::in | ios_base::trunc);
		f_2.open("f_2.txt", fstream::out | fstream::in | ios_base::trunc);
		f_3.open("f_3.txt", fstream::out | fstream::in | ios_base::trunc);
		f_4.seekp(0);
		f_5.seekp(0);
		f_6.seekp(0);
		if (emptyf_5)
			break;
		n *= 3;
		numfile = 1;
		while (!(f_4.eof() && f_5.eof() && f_6.eof())){
			int x1, x2, x3;
			f_4 >> x1;
			f_5 >> x2;
			f_6 >> x3;
			int cr1 = 0, cr2 = 0, cr3 = 0;
			for (int i = 0; i < n * 3; i++){
				if (x1 > x2 && x1 > x3 && x1 != NULL){
					x_min = 1;
				}
				else
				{
					if (x2 > x3 && x2 != NULL){
						x_min = 2;
					}
					else{
						if (x3 != NULL){
							x_min = 3;
						}
						else{
							x_min = 0;
						}
					}
				}
				switch (numfile){
				case 1:
					switch (x_min){
					case 1:{
						f_1 << " " << x1;
						cr1++;
						if (cr1 >= n || f_4.eof())
							x1 = NULL;
						else{
							f_4 >> x1;
						}
						break;
					}
					break;
					case 2:{
						f_1 << " " << x2;
						cr2++;
						if (cr2 >= n || f_5.eof())
							x2 = NULL;
						else{
							f_5 >> x2;
						}
						break;
					}
					break;
					case 3:{
						f_1 << " " << x3;
						cr3++;
						if (cr3 >= n || f_6.eof())
							x3 = NULL;
						else{
							f_6 >> x3;
						}
						break;
					}
					break;
					}
					break;
				case 2:
					switch (x_min){
					case 1:
						f_2 << " " << x1;
						cr1++;
						if (cr1 >= n || f_4.eof())
							x1 = NULL;
						else{
							f_4 >> x1;
						}
						break;
					case 2:
						f_2 << " " << x2;
						cr2++;
						if (cr2 >= n || f_5.eof())
							x2 = NULL;
						else{
							f_5 >> x2;
						}
						break;
					case 3:
						f_2 << " " << x3;
						cr3++;
						if (cr3 >= n || f_6.eof())
							x3 = NULL;
						else{
							f_6 >> x3;
						}
						break;
					}
					break;
				case 3:
					switch (x_min){
					case 1:
						f_3 << " " << x1;
						cr1++;
						if (cr1 >= n || f_4.eof())
							x1 = NULL;
						else{
							f_4 >> x1;
						}
						break;
					case 2:
						f_3 << " " << x2;
						cr2++;
						if (cr2 >= n || f_5.eof())
							x2 = NULL;
						else{
							f_5 >> x2;
						}
						break;
					case 3:
						f_3 << " " << x3;
						cr3++;
						if (cr3 >= n || f_6.eof())
							x3 = NULL;
						else{
							f_6 >> x3;
						}
						break;
					}
					break;
				}
			}
			if (f_1.eof() && f_2.eof() && f_3.eof())
				break;
			numfile++;
			if (numfile == 4)
				numfile = 1;
		}

		f_1.seekp(0);
		f_2.seekp(0);
		f_3.seekp(0);

		f_4.close();
		f_5.close();
		f_6.close();

		f_4.open("f_4.txt", fstream::out | fstream::in | ios_base::trunc);
		f_5.open("f_5.txt", fstream::out | fstream::in | ios_base::trunc);
		f_6.open("f_6.txt", fstream::out | fstream::in | ios_base::trunc);
	}

	system("pause");
	return 0;
}