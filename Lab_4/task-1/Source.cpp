#include <iostream>
#include <ctime>

using namespace std;

// Сортировка выбором
void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n){
	int i, j, min_idx;


	for (i = 0; i < n - 1; i++){
		min_idx = i;

		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Сортировка вставками
void insertionSort(int arr[], int n){
	int i, key, j;
	for (i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Сортировка обменом (Пузырёк)  
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Быстрая сортировка
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++){ 
		if (arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}



void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Пирамидальная сортировка

void heapify(int arr[], int n, int i)
{
	int largest = i;  
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	
	if (l < n && arr[l] > arr[largest])
		largest = l;

	
	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){ 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main(){
	setlocale(LC_ALL, "");
	int chc;
	cout << "Выберите количество элементов для сортировки (1. - 10, 2. - 100, 3. - 1000, 4. - 10000): ";
	cin >> chc;

	if (chc == 1) {
		int arr10_v1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		int n10_v1 = sizeof(arr10_v1) / sizeof(arr10_v1[0]);
		cout << "\n(Упорядоченный массив): ";
		printArray(arr10_v1, n10_v1);
		cout << "\n";
		selectionSort(arr10_v1, n10_v1);
		cout << "Сортировка выбором: \n";
		printArray(arr10_v1, n10_v1);
		cout << "\n";

		insertionSort(arr10_v1, n10_v1);
		cout << "Сортировка вставками: \n";
		printArray(arr10_v1, n10_v1);
		cout << "\n";

		bubbleSort(arr10_v1, n10_v1);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr10_v1, n10_v1);
		cout << "\n";

		quickSort(arr10_v1, n10_v1, n10_v1);
		cout << "Быстрая сортировка: \n";
		printArray(arr10_v1, n10_v1);
		cout << "\n";

		heapSort(arr10_v1, n10_v1);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr10_v1, n10_v1);
		cout << "\n\n\n";

		int arr10_v2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

		int n10_v2 = sizeof(arr10_v2) / sizeof(arr10_v2[0]);
		cout << "(Реверс): ";
		printArray(arr10_v2, n10_v2);
		cout << "\n";
		selectionSort(arr10_v2, n10_v2);
		cout << "Сортировка выбором: \n";
		printArray(arr10_v2, n10_v2);
		cout << "\n";

		insertionSort(arr10_v2, n10_v2);
		cout << "Сортировка вставками: \n";
		printArray(arr10_v2, n10_v2);
		cout << "\n";

		bubbleSort(arr10_v2, n10_v2);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr10_v2, n10_v2);
		cout << "\n";

		quickSort(arr10_v2, n10_v2, n10_v2);
		cout << "Быстрая сортировка: \n";
		printArray(arr10_v2, n10_v2);
		cout << "\n";

		heapSort(arr10_v2, n10_v2);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr10_v2, n10_v2);

		cout << "\n\n\n";

		int arr10_v3[] = { 4, 8, 2, 9, 1, 7, 3, 6, 10, 5 };

		int n10_v3 = sizeof(arr10_v3) / sizeof(arr10_v3[0]);
		cout << "(Разнобой): ";
		printArray(arr10_v3, n10_v3);
		cout << "\n";
		selectionSort(arr10_v3, n10_v3);
		cout << "Сортировка выбором: \n";
		printArray(arr10_v3, n10_v3);
		cout << "\n";

		insertionSort(arr10_v3, n10_v3);
		cout << "Сортировка вставками: \n";
		printArray(arr10_v3, n10_v3);
		cout << "\n";

		bubbleSort(arr10_v3, n10_v3);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr10_v3, n10_v3);
		cout << "\n";

		quickSort(arr10_v3, n10_v3, n10_v3);
		cout << "Быстрая сортировка: \n";
		printArray(arr10_v3, n10_v3);
		cout << "\n";

		heapSort(arr10_v3, n10_v3);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr10_v3, n10_v3);

		cout << "\n\n\n";
		system("pause");
		return 0;
	}
	if(chc == 2){
		int arr100_v1[100];

		for (int i = 0; i < 100; i++) {
			arr100_v1[i] = i;
		}

		int n100_v1 = sizeof(arr100_v1) / sizeof(arr100_v1[0]);
		cout << "\n(Упорядоченный массив): ";
		printArray(arr100_v1, n100_v1);
		cout << "\n";
		selectionSort(arr100_v1, n100_v1);
		cout << "Сортировка выбором: \n";
		printArray(arr100_v1, n100_v1);
		cout << "\n";

		insertionSort(arr100_v1, n100_v1);
		cout << "Сортировка вставками: \n";
		printArray(arr100_v1, n100_v1);
		cout << "\n";

		bubbleSort(arr100_v1, n100_v1);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr100_v1, n100_v1);
		cout << "\n";

		quickSort(arr100_v1, n100_v1, n100_v1);
		cout << "Быстрая сортировка: \n";
		printArray(arr100_v1, n100_v1);
		cout << "\n";

		heapSort(arr100_v1, n100_v1);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr100_v1, n100_v1);
		cout << "\n\n\n";

		int arr100_v2[100];

		for (int i = 100; i > 0; i--) {
			arr100_v2[i] = i;
		}

		int n100_v2 = sizeof(arr100_v2) / sizeof(arr100_v2[0]);
		cout << "(Реверс): ";
		printArray(arr100_v2, n100_v2);
		cout << "\n";
		selectionSort(arr100_v2, n100_v2);
		cout << "Сортировка выбором: \n";
		printArray(arr100_v2, n100_v2);
		cout << "\n";

		insertionSort(arr100_v2, n100_v2);
		cout << "Сортировка вставками: \n";
		printArray(arr100_v2, n100_v2);
		cout << "\n";

		bubbleSort(arr100_v2, n100_v2);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr100_v2, n100_v2);
		cout << "\n";

		quickSort(arr100_v2, n100_v2, n100_v2);
		cout << "Быстрая сортировка: \n";
		printArray(arr100_v2, n100_v2);
		cout << "\n";

		heapSort(arr100_v2, n100_v2);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr100_v2, n100_v2);

		cout << "\n\n\n";

		int arr100_v3[100];

		for (int i = 0; i < 100; i++) {
			arr100_v3[i] = 1 + rand() % 100;
		}

		int n100_v3 = sizeof(arr100_v3) / sizeof(arr100_v3[0]);
		cout << "(Разнобой): ";
		printArray(arr100_v3, n100_v3);
		cout << "\n";
		selectionSort(arr100_v3, n100_v3);
		cout << "Сортировка выбором: \n";
		printArray(arr100_v3, n100_v3);
		cout << "\n";

		insertionSort(arr100_v3, n100_v3);
		cout << "Сортировка вставками: \n";
		printArray(arr100_v3, n100_v3);
		cout << "\n";

		bubbleSort(arr100_v3, n100_v3);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr100_v3, n100_v3);
		cout << "\n";

		quickSort(arr100_v3, n100_v3, n100_v3);
		cout << "Быстрая сортировка: \n";
		printArray(arr100_v3, n100_v3);
		cout << "\n";

		heapSort(arr100_v3, n100_v3);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr100_v3, n100_v3);

		cout << "\n\n\n";
		system("pause");
		return 0;
	}
	if (chc == 3) {
		int arr1000_v1[1000];

		for (int i = 0; i < 1000; i++) {
			arr1000_v1[i] = i;
		}

		int n1000_v1 = sizeof(arr1000_v1) / sizeof(arr1000_v1[0]);
		cout << "\n(Упорядоченный массив): ";
		printArray(arr1000_v1, n1000_v1);
		cout << "\n";
		selectionSort(arr1000_v1, n1000_v1);
		cout << "Сортировка выбором: \n";
		printArray(arr1000_v1, n1000_v1);
		cout << "\n";

		insertionSort(arr1000_v1, n1000_v1);
		cout << "Сортировка вставками: \n";
		printArray(arr1000_v1, n1000_v1);
		cout << "\n";

		bubbleSort(arr1000_v1, n1000_v1);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr1000_v1, n1000_v1);
		cout << "\n";

		quickSort(arr1000_v1, n1000_v1, n1000_v1);
		cout << "Быстрая сортировка: \n";
		printArray(arr1000_v1, n1000_v1);
		cout << "\n";

		heapSort(arr1000_v1, n1000_v1);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr1000_v1, n1000_v1);
		cout << "\n\n\n";

		int arr1000_v2[1000];

		for (int i = 1000; i > 0; i--) {
			arr1000_v2[i] = i;
		}

		int n1000_v2 = sizeof(arr1000_v2) / sizeof(arr1000_v2[0]);
		cout << "(Реверс): ";
		printArray(arr1000_v2, n1000_v2);
		cout << "\n";
		selectionSort(arr1000_v2, n1000_v2);
		cout << "Сортировка выбором: \n";
		printArray(arr1000_v2, n1000_v2);
		cout << "\n";

		insertionSort(arr1000_v2, n1000_v2);
		cout << "Сортировка вставками: \n";
		printArray(arr1000_v2, n1000_v2);
		cout << "\n";

		bubbleSort(arr1000_v2, n1000_v2);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr1000_v2, n1000_v2);
		cout << "\n";

		quickSort(arr1000_v2, n1000_v2, n1000_v2);
		cout << "Быстрая сортировка: \n";
		printArray(arr1000_v2, n1000_v2);
		cout << "\n";

		heapSort(arr1000_v2, n1000_v2);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr1000_v2, n1000_v2);

		cout << "\n\n\n";

		int arr1000_v3[1000];

		for (int i = 0; i < 1000; i++) {
			arr1000_v3[i] = 1 + rand() % 1000;
		}

		int n1000_v3 = sizeof(arr1000_v3) / sizeof(arr1000_v3[0]);
		cout << "(Разнобой): ";
		printArray(arr1000_v3, n1000_v3);
		cout << "\n";
		selectionSort(arr1000_v3, n1000_v3);
		cout << "Сортировка выбором: \n";
		printArray(arr1000_v3, n1000_v3);
		cout << "\n";

		insertionSort(arr1000_v3, n1000_v3);
		cout << "Сортировка вставками: \n";
		printArray(arr1000_v3, n1000_v3);
		cout << "\n";

		bubbleSort(arr1000_v3, n1000_v3);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr1000_v3, n1000_v3);
		cout << "\n";

		quickSort(arr1000_v3, n1000_v3, n1000_v3);
		cout << "Быстрая сортировка: \n";
		printArray(arr1000_v3, n1000_v3);
		cout << "\n";

		heapSort(arr1000_v3, n1000_v3);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr1000_v3, n1000_v3);

		cout << "\n\n\n";
		system("pause");
		return 0;
	}
	if (chc == 4) {
		int arr10000_v1[10000];

		for (int i = 0; i < 10000; i++) {
			arr10000_v1[i] = i;
		}

		int n10000_v1 = sizeof(arr10000_v1) / sizeof(arr10000_v1[0]);
		cout << "\n(Упорядоченный массив): ";
		printArray(arr10000_v1, n10000_v1);
		cout << "\n";
		selectionSort(arr10000_v1, n10000_v1);
		cout << "Сортировка выбором: \n";
		printArray(arr10000_v1, n10000_v1);
		cout << "\n";

		insertionSort(arr10000_v1, n10000_v1);
		cout << "Сортировка вставками: \n";
		printArray(arr10000_v1, n10000_v1);
		cout << "\n";

		bubbleSort(arr10000_v1, n10000_v1);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr10000_v1, n10000_v1);
		cout << "\n";

		quickSort(arr10000_v1, n10000_v1, n10000_v1);
		cout << "Быстрая сортировка: \n";
		printArray(arr10000_v1, n10000_v1);
		cout << "\n";

		heapSort(arr10000_v1, n10000_v1);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr10000_v1, n10000_v1);
		cout << "\n\n\n";

		int arr10000_v2[10000];

		for (int i = 10000; i > 0; i--) {
			arr10000_v2[i] = i;
		}

		int n10000_v2 = sizeof(arr10000_v2) / sizeof(arr10000_v2[0]);
		cout << "(Реверс): ";
		printArray(arr10000_v2, n10000_v2);
		cout << "\n";
		selectionSort(arr10000_v2, n10000_v2);
		cout << "Сортировка выбором: \n";
		printArray(arr10000_v2, n10000_v2);
		cout << "\n";

		insertionSort(arr10000_v2, n10000_v2);
		cout << "Сортировка вставками: \n";
		printArray(arr10000_v2, n10000_v2);
		cout << "\n";

		bubbleSort(arr10000_v2, n10000_v2);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr10000_v2, n10000_v2);
		cout << "\n";

		quickSort(arr10000_v2, n10000_v2, n10000_v2);
		cout << "Быстрая сортировка: \n";
		printArray(arr10000_v2, n10000_v2);
		cout << "\n";

		heapSort(arr10000_v2, n10000_v2);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr10000_v2, n10000_v2);

		cout << "\n\n\n";

		int arr10000_v3[10000];

		for (int i = 0; i < 10000; i++) {
			arr10000_v3[i] = 1 + rand() % 10000;
		}

		int n10000_v3 = sizeof(arr10000_v3) / sizeof(arr10000_v3[0]);
		cout << "(Разнобой): ";
		printArray(arr10000_v3, n10000_v3);
		cout << "\n";
		selectionSort(arr10000_v3, n10000_v3);
		cout << "Сортировка выбором: \n";
		printArray(arr10000_v3, n10000_v3);
		cout << "\n";

		insertionSort(arr10000_v3, n10000_v3);
		cout << "Сортировка вставками: \n";
		printArray(arr10000_v3, n10000_v3);
		cout << "\n";

		bubbleSort(arr10000_v3, n10000_v3);
		cout << "Сортировка обменом (Пузырёк): \n";
		printArray(arr10000_v3, n10000_v3);
		cout << "\n";

		quickSort(arr10000_v3, n10000_v3, n10000_v3);
		cout << "Быстрая сортировка: \n";
		printArray(arr10000_v3, n10000_v3);
		cout << "\n";

		heapSort(arr10000_v3, n10000_v3);
		cout << "Пирамидальная сортировка: \n";
		printArray(arr10000_v3, n10000_v3);

		cout << "\n\n\n";
		system("pause");
		return 0;
	}

	
	system("pause");
	return 0;
}
