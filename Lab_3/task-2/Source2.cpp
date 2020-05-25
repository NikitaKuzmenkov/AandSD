#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

class coord
{
public:
	int dx;
	int dy;
}
turns[8] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

void knight(int n, int x0, int y0, int& counter, int** a, int k)
{
	for (int i = 0; i < 8; i++)
	{
		int x = x0 + turns[i].dx;
		int y = y0 + turns[i].dy;
		if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 0)
		{
			counter++;
			k++;
			a[x][y] = counter;
			cout << "Ўаг: " << k << "\n\n";
			for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							cout << a[i][j] << "\t";
						}
						cout << "\n\n";
			}
			knight(n, x, y, counter, a, k);
		}
		else{
			continue;
		}
	}
}

int main(){
	setlocale(LC_ALL, "");

	int k = 0;
	int n;

	cout << "¬ведите размерность пол€: ";
	
	cin >> n;
	
	cout << "\n";

	int** a = new int* [n] {};
	for (int i = 0; i < n; i++){
		a[i] = new int[n] {};
	}
	
	int counter = 1;
	a[0][0] = 1;

	knight(n, 0, 0, counter, a, k);

	system("pause");
	return 0;
}
