#include <iostream>
#include <cmath>
using namespace std;




int main() {
    double sum = 0; // сумма
    double sum1 = 1;  // сумма первого элемент (n = 0)
    double sum2 = 0; // временная сумма
    double a = 0.01;// точность суммы

    double n = 1;  // счетчик

    while (abs(sum1 - sum) > a) {

        sum = sum1;   // замена
        sum1 = pow(-1, n) * (1) / (1 + pow(n, 3));
        n++;
    }

    cout << "The sum is : " << sum << endl;
    return 0;
}

