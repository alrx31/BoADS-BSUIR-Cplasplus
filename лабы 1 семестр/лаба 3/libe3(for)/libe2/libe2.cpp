#include <iostream>
using namespace std;

int main() {
    cout << "All three-digit numbers whose sum equals 17" << endl;
    // начало цикла
    for (int i = 100; i <= 999;i++) {
        //вычисление суммы
        int number = i;
        int digit1 = number / 100; // Первая цифра
        int digit2 = (number / 10) % 10; // Вторая цифра
        int digit3 = number % 10; // Третья цифра
        int sum = digit1 + digit2 + digit3; // Сумма цифр
        // сравнение и вывод числа
        if (sum == 17){
            cout << i << endl;
        }
    }
    return 0;
}

