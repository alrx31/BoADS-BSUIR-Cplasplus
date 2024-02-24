#include <iostream>
#include <vector>
#include <cmath>
using namespace std;






// Функция, которая удаляет каждый второй элемент из вектора
void DeleteFunc(vector<int>& a) {
    for (auto i = a.begin(); i != a.end();) {
        if (*i % 2 == 0) {
            i = a.erase(i);
        }
        else {
            i++;
        }
    }
}

// Функция, которая удаляет все слова на четных позициях в строке
void DeleteFunc(string& a) {
    vector<string> words;
    string word;
    for (auto i : a) {
        if (i == ' ') {
            words.push_back(word);
            word.clear();
        }
        else {
            word += i;
        }
    }
    words.push_back(word);
    word.clear();

    for (int i = 1; i < words.size(); i += 2) {
        word += words[i];
        if (i + 2 < words.size()) {
            word += ' ';
        }
    };
    a = word;
}


int main() {
    vector<int> arr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    DeleteFunc(arr);

    string str = "Hello I am a people who like javascript and for me realy hard to learn c++";
    DeleteFunc(str);
    // Удаляем каждый второй элемент из вектора arr
    for (auto x : arr) {
        cout << x << " ";
    }
    
    cout << endl << str;
    return 0;
}