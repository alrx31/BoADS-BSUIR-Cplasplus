#include <iostream>
// библиотека math
#include <cmath>

using namespace std;

int main() {

    // Ввод углов в градусах

    double angle1;
    // угол 1
    cout << "Enter the value in Angle: ";
    cin >> angle1;

    // Значение числа π
    const double PI = 3.14159265358979323846;

    // Перевод угла из градусов в радианы
    double radians1 = angle1 * PI / 180.0;

    // Вычисление по формуле 1
    double result1 = sqrt(1-sin(radians1)*sin(radians1)) / sin(radians1);

    // Вычисление по формуле 2
    double result2 = cos(radians1)/sqrt(1-cos(radians1)*cos(radians1));

    // округление до 0.000001

    double res1 = round(result1 * 1000000.0) / 1000000.0;
    double res2 = round(result2 * 1000000.0) / 1000000.0;
    

    // Вывод результатов
    if (res1 == res2 or res1 == -1 * res2) {
        cout << "Result by formule 1: " << res1 << endl;
        cout << "Result by formule 2: " << res2 << endl;
        cout << "All Right!!";
    }
    else {
        cout << "Result by formule 1: " << res1 << endl;
        cout << "Result by formule 2: " << res2 << endl;
        cout << "Somethink Error.";
    }

    return 0;
}