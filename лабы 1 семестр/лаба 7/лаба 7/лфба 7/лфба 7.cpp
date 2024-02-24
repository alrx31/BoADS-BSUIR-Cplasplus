// Используем директиву препроцессора для отключения предупреждений о безопасности
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstring>
using namespace std;

// Структура для представления данных о самолете
struct Plane {
	int id;
	char type[20];
	char name[20];
	int numberOf;
	// Функция для вывода данных о самолете
	void print() {
		cout << id << " " 
			<< type << " "
			<< name << " "
			<< numberOf << " " 
			<< endl;
	}
};

int main() {
	// Имя файла для записи данных о самолетах
	char filename[] = "planes_structure.txt";
	int n = 11;
	// массив структур самолётов
	Plane Types[] = {
		{1,"integrator","TorpedoNOsec",2},
		{2,"integrator","Perehvatchic",2},
		{3,"Plane","Boing        ",500},
		{4,"Plane","Red Tulpan",200},
		{5,"integrator","Green S    ",2},
		{6,"integrator","Blue    ",2},
		{7,"Bombondir","buttocks",3},
		{8,"Bombondir","Bubs    ",3},
		{9,"Bombondir","elbow     ",3},
		{10,"Shturmovic","knee     ",1},
		{11,"Shturmovic","pinky    ",1}
	};

	// Открываем файл для записи данных
	ofstream outfile(filename);
	if (!outfile) {
		cerr << "ERROR" << endl;
		return 1;
	}

	// Переменная для хранения типа самолета, который пользователь ищет
	char a[20];
	cout << "Enter a type what you need: " << endl;
	cin >> a;

	// Поиск и вывод в файл информации о самолете, который пользователь ищет
	for (int j = 0; j < n; j++) {
		if (strcmp(Types[j].type,a) == 0) {
			Types[j].print();
			outfile << "#" 
				<< Types[j].id << "\t" 
				<< Types[j].type << "\t"
				<< Types[j].name << "\t"
				<< Types[j].numberOf << endl;
		}
	}

	// Закрываем файл
	outfile.close();

	return 0;
}
