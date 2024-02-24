#include <iostream>
#include <string>
using namespace std;

int main()
{
	//ввод строки
	cout << "enter a path:  " << endl;

	string a;


	getline(cin, a);

	// добавление путя по умолчанию
	if (a == "") {
		a = "D:\\BSUIR\\English\\Homework.docx";
	}

	int flag1 = -1; // позиция точки
	int flag2 = -1; // позиция последнего обратного слеша

	// Проходимся по входной строке в обратном порядке для поиска позиций точки и последнего обратного слеша
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] == '.') {
			flag1 = i;
		}
		if (a[i] == '\\') {
			flag2 = i;
			break;
		}
	}

	// Проверяем, не была ли найдена точка или обратный слеш, что указывает на недопустимый путь
	if (flag1 == -1 || flag2 == -1) {
		cout << "invalid path" << endl;
		return 0;
	}

	string res_name = "";   // имя файла
	string res_exe = "";   // расширение файла

	// Извлекаем символы между последним обратным слешем и точкой в качестве имени файла
	for (int j = flag2 + 1; j < flag1; j++) {
		res_name += a[j];
	}

	// Извлекаем символы после точки в качестве расширения файла
	for (int v = flag1 + 1; v < a.size(); v++) {
		res_exe += a[v];
	}

	// Выводим извлеченное имя файла и расширение файла
	cout << "The name : " << res_name << endl;
	cout << "The extition: " << res_exe << endl;

	return 0;
}
