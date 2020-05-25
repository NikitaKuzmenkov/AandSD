#include <iostream>
#include <ctime>

using namespace std;

class fsearesult {
public:
	int r_num1;
	int r_num2;
	int r_num3;
};

fsearesult rstrct;

void maxsubprice(int* arr, int l, int m, int r)
{
	int l_sum = -100000, sum = 0, maxleft;
	for (int i = m; i >= l; i--)
	{
		sum += arr[i];
		if (sum > l_sum)
		{
			l_sum = sum;
			maxleft = i;
		}
	}
	int r_sum = -100000, maxright;
	sum = 0;
	for (int i = m + 1; i <= r; i++)
	{
		sum += arr[i];
		if (sum > r_sum)
		{
			r_sum = sum;
			maxright = i;
		}
	}
	rstrct.r_num1 = maxleft;
	rstrct.r_num2 = maxright;
	rstrct.r_num3 = l_sum + r_sum;
}

void findmaxprice(int* arr, int l, int r)
{
	if (r == l){
		rstrct.r_num1 = l;
		rstrct.r_num2 = r;
		rstrct.r_num3 = arr[l];
		return;
	}
	else{
		int m = (l + r) / 2;
		
		findmaxprice(arr, l, m);
		
		int leftlow = rstrct.r_num1;
		int lefthigh = rstrct.r_num2;
		int l_sum = rstrct.r_num3;
		
		findmaxprice(arr, m + 1, r);
		
		int rightlow = rstrct.r_num1;
		int righthigh = rstrct.r_num2;
		int r_sum = rstrct.r_num3;
		
		maxsubprice(arr, l, m, r);
		
		int crosslow = rstrct.r_num1;
		int crosshigh = rstrct.r_num2;
		int crosssum = rstrct.r_num3;

		if (l_sum >= r_sum && l_sum >= crosssum){
			rstrct.r_num1 = leftlow;
			rstrct.r_num2 = lefthigh;
			rstrct.r_num3 = l_sum;
			return;
		}
		else{
			if (r_sum >= l_sum && r_sum >= crosssum){
				rstrct.r_num1 = rightlow;
				rstrct.r_num2 = righthigh;
				rstrct.r_num3 = r_sum;
				return;
			}
			else{
				rstrct.r_num1 = crosslow;
				rstrct.r_num2 = crosshigh;
				rstrct.r_num3 = crosssum;
				return;
			}
		}
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	srand(time(0));
	
	int N;
	
	cout << "Количество дней: ";
	
	cin >> N;

	int* price = new int[N];
	cout << "\t";

	for (int i = 0; i < N; i++){
		cout << "День ";
		cout << i << "\t";
	}

	cout << "\nЦена:\t";

	for (int i = 0; i < N; i++){
		price[i] = rand() % 100;
		cout << price[i] << "$\t";
	}
	cout << "\nИзменение:\t";

	int* arr = new int[N - 1];

	for (int i = 0; i < N - 1; i++){
		arr[i] = price[i + 1] - price[i];
		cout << arr[i] << "\t";
	}

	cout << endl;

	int l = 0, r = N - 2, m = (l + r) / 2;

	findmaxprice(arr, l, r);

	cout << "\nПокупка: " << rstrct.r_num1 << "-й день\t\t" << "Продажа: " << rstrct.r_num2 + 1 << "-й день\t\t" << "Прибыль: " << rstrct.r_num3 << "$\n" << endl;

	system("pause");
	return 0;
}