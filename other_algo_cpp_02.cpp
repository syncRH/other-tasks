#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <stdio.h>

using namespace std;

/*

проверка на более двух операндов
один элемент в стеке должен быть

*/
string readStr() {
    string val;

    getline(cin, val);

    return val;
}

int main() {
    setlocale(LC_ALL, "RUS");
    stack<double> stackPolish;

    cout << "Введите выражение в обратной польской записи: ";
    auto v = readStr();
    auto s = istringstream(v);

    string exp;
    while (getline(s, exp, ' ')) {
        float num = 0;
        if (sscanf_s(exp.data(), "%f", &num) >= 1) {
            stackPolish.push(num);
            continue;
        }

        if (stackPolish.size() > 1) {
            auto y = stackPolish.top();
            stackPolish.pop();
            auto x = stackPolish.top();
            stackPolish.pop();

            switch (exp[0]) {
            case '+':
                stackPolish.push(x + y);
                break;
            case '-':
                stackPolish.push(x - y);
                break;
            case '*':
                stackPolish.push(x * y);
                break;
            case '/':
                stackPolish.push(x / y);
                break;
            case '^':
                stackPolish.push(pow(x, y));
                break;
            }
        }
        else {
            cout << "Ошибка! Неверный ввод";
            return 0;
        }
    }
    double buf;
    int k = 0;
    while (stackPolish.size() != 0) {
        buf = stackPolish.top();
        stackPolish.pop();
        k++;

    }
    if (k == 1) {
        cout << "Результат: = " << buf;
    }
    else cout << "Ошибка! Неверный ввод.";
    //    cout << buf;
    return 0;
}