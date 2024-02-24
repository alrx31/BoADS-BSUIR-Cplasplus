#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(){
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
	//int** A = new int*[n];
	vector<vector<int>> A(n, vector<int>(m));
	// перебор массива
	for (int i = 0; i < n; i++) {
		// создание столбца
		//A[i] = new int[m];
		for (int j = 0; j < m; j++) {
			//ввод рандомного значения
			A[i][j] = min2 + rand() % (max - min2 + 1);
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	/*// пусть массив А мы задаем заранее рандомно
	int A[3][5] = {
		{1,2,3,6,-1},
		{1,4,0,-3,2},
		{3,4,5,-2,1}
	};
	*/

	// флаг
	bool IsHas = false;

	// перебор массива вначале по строкам потом по столбцам
	for (int i = 0; i < sizeof(A)/ sizeof(A[0]); i++) {
		for (int j = 0; j < sizeof(A[0])/ sizeof(A[0][0]); j++) {

			// проверка на отрицательное число и выход из цикла
			if (A[i][j] < 0) {
				IsHas = true;
				break;
			}

		}
	}
	//конечный вывод
	if (IsHas) {
		cout << "The array has minus element"<< endl;
	}
	else {
		cout << " the array hasnt minus element" << endl;
	}

	return 0;

}