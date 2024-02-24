#include <iostream>

using namespace std;

// рекурсивная функция для нахождения суммы цифр числа
int recursion_summ(int n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + recursion_summ(n / 10);
}
// Рекурсивная функция для нахождения разности цифр числа
int FindDifference(int n) {
    if (n < 10) {
        return 0;
    }
    return n % 10 - recursion_summ(n / 10);
}



int main() {
    // Ввод натурального числа от пользователя
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Вызываем функцию для нахождения разности цифр и выводим результат
    cout << "Difference = " << FindDifference(n) << endl;
    return 0;
}
