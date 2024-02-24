#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	// Инициализация рандомайзера через реальное время
	srand(std::time(nullptr));
	// минимальные и максимальные значения
	int min = 1;
	int min2 = -10;
	int max = 10;

	// генерирование количества строк и столбцов
	int n = min + rand() % (max - min + 1);
	int m = min + rand() % (max - min + 1);
	// инициализация динамического массива строк с указателями на строки и столбцы  
	int** A = new int*[n];
	// перебор массива
	for (int i = 0; i < n; i++) {
		// создание столбца
		A[i] = new int[m];
		for (int j = 0; j < m; j++) {
			//ввод рандомного значения
			A[i][j] = min2 + rand() % (max - min2 + 1);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}


	// флаг
	bool IsHas = false;

	// перебор массива вначале по строкам потом по столбцам
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
		for (int j = 0; j < sizeof(A[0]) / sizeof(A[0][0]); j++) {

			// проверка на отрицательное число и выход из цикла
			if (A[i][j] < 0) {
				IsHas = true;
				break;
			}

		}
	}
	//конечный вывод
	if (IsHas == true) {
		cout << "The array has minus element" << endl;
	}
	else {
		cout << " the array hasnt minus element" << endl;
	}

	return 0;

}