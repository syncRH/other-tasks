#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

string to_binary_string(int n)
{
    if (n == numeric_limits<int>::min())
        return "-1" + string(numeric_limits<int>::digits, '0');
    string buffer;
    buffer.reserve(numeric_limits<int>::digits + 1); 
    bool negative = (n < 0);
    if (negative)
        n = -n;
    do
    {
        buffer += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);
    if (negative)
        buffer += '-';
    return string(buffer.crbegin(), buffer.crend());
}

void sum_binary(vector <int> &vec) {
    int temp = 1;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[vec.size()-1 - i] == 0 && temp != 0) { vec[vec.size()-1 - i] = 1, temp = 0; }
        else if (vec[vec.size()-1 - i] == 1 && temp != 0) vec[vec.size()-1 - i] = 0;
    }
}
int inputInt(int max = INT_MAX, int min = INT_MIN)
{
    int N;
    for (;;) {
        cout << "Ввод(целое от " << min << " до " << max << "): ";
        if ((cin >> N).good() && (min <= N) && (N <= max)) return N;
        if (cin.fail()) {
            cin.clear();
            cout << "Неверный ввод, повторите.\n";
        }
        else {
            cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
void init_vec(vector <int>& vec, bool& negative) {
    int s = inputInt(30, -30);
    if (s < 0) negative = true;
    string temp = to_binary_string(abs(s));
    for (size_t i = 0; i < temp.length(); i++)
        vec.push_back(int(temp[i]) - 48);
}
void invs_binary(vector <int>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
        if (vec[i] == 0) vec[i] = 1;
        else if (vec[i] == 1) vec[i] = 0;
}
string print_vec(vector <int>& vec) {
    string str;
    for (size_t i = 0; i < vec.size(); i++)
        str += to_string(vec[i]);
    return str;
}
void print_binary(vector <int> vec, int n, bool negative) {
    int temp;
    if (negative) temp = 1;
    else temp = 0;
    switch (n)
    {
    case 1: {cout << "ПК - " << temp << "." << print_vec(vec); break; }
    case 2: {invs_binary(vec); cout << "ОК - " << temp << "." << print_vec(vec); break; }
    case 3: {sum_binary(vec); cout << "ДК - " << temp << "." << print_vec(vec); break; }
    case 4: {cout << "МДК - " << temp * 11 << "." << print_vec(vec); break; }
    }
    cout << "\n Для продолжения работы программы нажмите ENTER... \n";
    char ch;
    do {
        ch = _getch();
    } while (ch != 13);
}
bool exit() {
    char c = 89;
    cout << "\nЗавершить программу? \n Для завершения нажмите [Y], для рестарта программы нажмите [N]";
    for(;;){
        char c;
        c = _getch();
        if (toupper(c) == 89)  return false;
        else if (toupper(c) == 78) return true;
    } 
}
int main()
{
    setlocale(LC_ALL, "RUS");
    bool(negative) = false;
    vector <int> vec;
    init_vec(vec, negative);
    do {
        int n;
        cout << "\nВыберите вид кода: \n 1. ПК \n 2. ОК \n 3. ДК \n 4. МДК \n"; 
        if(negative) n = inputInt(4, 2);
        else n = inputInt(4, 1);
        print_binary(vec, n, negative);
    } while (exit());
    
    return 0;
}
