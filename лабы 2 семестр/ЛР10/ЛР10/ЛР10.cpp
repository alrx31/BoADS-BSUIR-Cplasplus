#include <iostream>
#include <vector>


using namespace std;


// функция сортировки вставками(включением)
void InsertionSort(int * arr, int size) {

	for (int i = 1; i < size; i++) {
		// объяевление опорного элемента
		int key = arr[i];
		int j = i - 1;
		// сдвиг всех элементов больше опорного на одну позицию вперед

		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}

		// вставка опорного элемента на свое отсортированное место
		arr[j + 1] = key;
	}
}


int main() {

	// ввод размера массива
	cout << "enter a size of array: " << endl;
	int size;
	cin >> size;

	// создание массива и заполнение его элементами
	int *arr = new int[size];
	int * arrNegative = new int[size];

	cout << "enter a array: " << endl;

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}


	// заполнение массива отрицательных чисел
	int m = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			arrNegative[m] = arr[i];
			m++;
		}
	}
	for (int i = m; i < size; i++) {
		arrNegative[i] = 0;
	}

	// сортировка массива отрицательных чисел
	InsertionSort(arrNegative,size);

	// замена отрицательных чисел в массиве на отсортированные
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {
			arr[i] = arrNegative[j];
			j++;
		}
	}
	// вывод массива
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}


	// освобождение памяти
	delete [] arr;
	delete [] arrNegative;

	return 0;
}