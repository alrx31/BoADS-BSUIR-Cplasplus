#include <iostream>
#include <cmath>

using namespace std;

// Функция, которая проверяет, является ли число простым
void checkCombine(int n);

int main() {
    int x;
    cout << "Enter a number" << endl;
    cin >> x;
    if (x <= 0) {
        cerr << "Invalid Number";
        return 0;
    }
    
    checkCombine(x);
    return 0;
}

void checkCombine(int n) {
    
    // Проверяем все числа от 1 до x-1 и выводим те, которые не являются простыми
    for (int i = 1; i < n; i++) {
        // Проверяем, делится ли n на какое-либо число, кроме 1 и n
        int p1 = 0;
        for (int j = 2; j <= ceil(sqrt(i)); j++) {
            bool p = false;
            if (j == i) {
                continue;
            }
            if (i % j == 0) {
                p = true;
            }
            if (p) {
                p1++;
            }
           
        }
        //вывод таких чисел
        if (p1 >0) {
            cout << i << endl;
        }
        
    }




}
