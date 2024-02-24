#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter three digits: ";
    cin >> number;
        
    // Убедитесь, что число трехзначное

    if (number >= 100 && number <= 999) { 

        // Первая цифра

        int digit1 = number / 100; 
        cout << digit1 << endl;
        
        // Вторая цифра
                
        int digit2 = (number / 10) % 10; 
        
        // Третья цифра
        
        int digit3 = number % 10; 
        
        // Сумма цифр
        
        int sum = digit1 + digit2 + digit3; 
        
        // Проверка на четность суммы

        if (sum % 2 == 0) { 
            cout << "The sum of the digits is an even number." << endl;
        }
        else {
            cout << "The sum of digits is not an even number." << endl;
        }
    }
    else {
        cout << "Invalid number." << endl;
    }

    return 0;
}
