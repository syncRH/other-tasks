#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

bool isInt(string s) {
    for (int i = 0; i < int(s.size()); i++) {
        if ((s[i] < '0' || s[i]>'9') && s[i] != '-')
            return false;
    }
    return true;
}

double RtoDouble(vector <int> vec) {
    double k = double(1) / 2, result = 0;
    for (int i = 0; i < int(vec.size()); i++) {
        if (vec[i] == 1) result += k;
        k /= 2;
    }
    return result;
}


bool stopDivision() {
    char c = 89;
    cout << "\nПродолжить деление?(Y/N) ";
    for (;;) {
        char c;
        cin >> c;
        if (toupper(c) == 89) return true;
        else if (toupper(c) == 78) return false;
        cout << "Неверно \nПродолжить деление?(Y/N) ";
    }
    cout << endl;
}
string print_vec(vector <int> vec) {
    string str;
    for (size_t i = 0; i < vec.size(); i++)
        str += to_string(vec[i]);
    return str;
}
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

void mdkBinary(vector <int>& vec) {
    int temp = 1;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[vec.size() - 1 - i] == 0 && temp != 0) { vec[vec.size() - 1 - i] = 1, temp = 0; }
        else if (vec[vec.size() - 1 - i] == 1 && temp != 0) vec[vec.size() - 1 - i] = 0;
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

void shiftLeftBinary(vector <int>& vec) {
    rotate(vec.begin(), vec.begin() + 1, vec.end());
    vec[vec.size() - 1] = 0;
}

void init_vec(vector <int>& vec, bool& negative, int s) {
    if (s < 0) negative = true;
    string temp = to_binary_string(abs(s));
    for (size_t i = 0; i < temp.length(); i++)
        vec.push_back(int(temp[i]) - 48);
}

void normalisationBinary(vector <int>& a, vector <int>& b) {
    int sizeA = int(a.size()), sizeB = int(b.size());
    if (sizeA > sizeB) {
        for (int i = 1; i <= sizeA - sizeB; i++) {
            reverse(b.begin(), b.end());
            b.push_back(0);
            reverse(b.begin(), b.end());
        }
    }
    if (sizeA < sizeB) {
        for (int i = 1; i <= sizeB - sizeA; i++) {
            reverse(a.begin(), a.end());
            a.push_back(0);
            reverse(a.begin(), a.end());
        }
    }
}

bool sumBinary(vector <int> a, vector <int> b, vector <int>& c) {
    bool(flag) = false;
    int count = 0;
    for (size_t i = 0; i < a.size(); i++) {

        int temp = b[a.size() - 1 - i];
        for (size_t j = 0; j < a.size() - i; j++) {
            if (a[a.size() - 1 - i - j] == 0 && temp != 0) { a[a.size() - 1 - i - j] = 1, temp = 0; break; }
            else if (a[a.size() - 1 - i - j] == 1 && temp != 0) a[a.size() - 1 - i - j] = 0;
            else if (temp == 0) break;
        }
        if (temp == 1) flag = true;
    }
    c = a;
    return flag;
}
bool checkBinary(vector <int> vec) {
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 1) return false;
    }
    return true;
}
vector<int> okBinary(vector <int>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
        if (vec[i] == 0) vec[i] = 1;
        else if (vec[i] == 1) vec[i] = 0;
    return vec;
}

string lessZero(vector <int>& a, vector <int> b, vector<int>& aMPK, vector<int> bMPK) {
    okBinary(b); mdkBinary(b);
    okBinary(bMPK);
    sumBinary(aMPK, bMPK, aMPK);
    if (sumBinary(a, b, a)) okBinary(aMPK);
    return print_vec(bMPK) + "." + print_vec(b) + " -МДК " "\n";
}

bool comparisonVec(vector<int> a, vector<int> b) {
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

string aboveZero(vector <int>& a, vector <int> b, vector<int>& aMPK, vector<int> bMPK) {
    if (sumBinary(a, b, a)) okBinary(aMPK);
    return print_vec(bMPK) + "." + print_vec(b) + " +МПК " + "\n";
}

void roundingVec(vector <int>& vec) {
    for (size_t i = vec.size() - 1; i >= 0; i--)
    {
        if (vec[i] == 0) {
            vec.erase(vec.begin() + i);
        }
        else break;
    }
}
int strToDec(string s) {
    {
        string sr;
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] != ' ') sr += s[i];
        }
        s = sr;
    }
    int result = 0;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            result = result * 10 + int(s[i]) - '0';
    }
    if (s[0] == '-') return -result;
    else return result;
}

string multiplicationLiteral(int n, char liter) {
    string buf;
    for (size_t i = 0; i < n; i++)
    {
        buf += liter;
    }
    return buf;
}
// 9,13
void mainBinary() {
    int aN, bN;
    while (true)
    {
        cout << "Введите два целых десятичных числа (A<B)\n";
        string geter = "";
        char ch;
        cin.get(ch);
        while (ch != '\n') {
            geter += ch;
            cin.get(ch);
        }
        int i = 0;
        if ((geter.find(',') > geter.size()) && isInt(geter.substr(0, geter.find(','))) && isInt(geter.substr(geter.find(',') + 1))) {
            cout << "Неправильный ввод данных\n";
            continue;
        }
        aN = strToDec(geter.substr(0, geter.find(',')));
        bN = strToDec(geter.substr(geter.find(',') + 1));
        if (abs(bN) <= abs(aN)) {
            cout << "Неправильный ввод данных\n";
            continue;
        }
        break;
    }
    int code;
    cout << "Выбирете метод деления:\n1 Без востановления остатка со сдвигом остатка\n2 С востановлением остатка со сдвигом остатка\n3 С востановлением остатка без сдвига делителя\n4 Без востановления остатка без сдвига делителя\n";
    cin >> code;
    while (code != 1) {
        if (code < 1 || code>4) cout << "Неправильный номер метода деления\n";
        else cout << "Данный метод не реализован\n";
        cout << "Выбирете метод деления:\n1 Без востановления остатка со сдвигом остатка\n2 С востановлением остатка со сдвигом остатка\n3 С востановлением остатка без сдвига делителя\n4 Без востановления остатка без сдвига делителя\n";
        cin >> code;
    }
    bool(aNeg) = false;
    bool(bNeg) = false;
    string buffer = "";
    int k = 0;
    vector <int> a, b, r, tempB;
    vector <int> aMPK(2, 0);
    vector <int> bMPK(2, 0);
    init_vec(a, aNeg, aN);
    init_vec(b, bNeg, bN);
    normalisationBinary(a, b);
    tempB = b;
    okBinary(tempB);
    mdkBinary(tempB);
    cout << "А в МПК " << print_vec(aMPK) + "." + print_vec(a) + "\n";
    cout << "В в МПК " << print_vec(bMPK) + "." + print_vec(b) + "\n";
    cout << "В в МПК " << "11" << "." << print_vec(tempB) + "\n";
    cout << int(aNeg) << "(+)" << int(bNeg) << " = " << int(aNeg + bNeg) << " -> ";
    if (aNeg * bNeg == 1) cout << "'-'";
    else cout << "'+'";
    cout << endl;
    string liters = multiplicationLiteral(a.size(), '-');
    string sign;
    do
    {
        k++;
        if (!comparisonVec(a, tempB) && r.size() <= a.size() + 1) {
            if (k == 1) {
                buffer += "\n" + print_vec(aMPK) + "." + print_vec(a) + "\n";
                buffer += lessZero(a, b, aMPK, bMPK);
            }
            else {
                shiftLeftBinary(a);
                buffer += "\n" + print_vec(aMPK) + "." + print_vec(a) + " <- " + "\n";
                if (aMPK[0] == 0) {
                    buffer += lessZero(a, b, aMPK, bMPK);
                }
                else buffer += aboveZero(a, b, aMPK, bMPK);
            }
            if (aMPK[0] == 0) {
                sign = " >0 ";
            }
            else sign = " <0 ";
            buffer += liters + "\n" + print_vec(aMPK) + "." + print_vec(a) + sign + "\n";
            cout << buffer;
            char ch;
            do {
                ch = _getch();
            } while (ch != 13);
            r.push_back((aMPK[0] == 0));
            cout << "\nR = " << (print_vec(r))[0] << "." << (print_vec(r)).substr(1, print_vec(r).length()) << endl;
        }
        else if (r.size() <= a.size() + 1) {
            vector <int> tempA(a.size(), 0);
            vector <int> tempMPK(2, 0);
            buffer += "\n" + print_vec(tempMPK) + "." + print_vec(a) + "\n";
            if (k == 1) buffer += lessZero(a, b, tempMPK, bMPK);
            else {
                shiftLeftBinary(tempA);
                if (aMPK[0] == 0) {
                    buffer += lessZero(tempA, b, tempMPK, bMPK);
                }
                else buffer += aboveZero(tempA, b, tempMPK, bMPK);
            }
            if (tempMPK[0] == 1) {
                sign = " >0 ";
            }
            else sign = " <0 ";
            buffer += liters + "\n" + print_vec(tempMPK) + "." + print_vec(tempA) + sign + "\n";
            cout << buffer;
            char ch;
            do {
                ch = _getch();
            } while (ch != 13);
            r.push_back((tempMPK[0] == 1));
            cout << "\n R = " << (print_vec(r))[0] << "." << (print_vec(r)).substr(1, print_vec(r).length()) << endl;
        }
        else break;
        if (r.size() > a.size() + 1 && k > 1) break;
        cin.get();
    } while (stopDivision());
    roundingVec(r);
    cout << "\n R = " << (print_vec(r))[0] << "." << (print_vec(r)).substr(1, print_vec(r).length()) << endl;
    r.erase(r.begin() + 0);
    cout << "Ответ: " << RtoDouble(r);
}

void print_binary(vector <int> vec, int n, bool negative) {
    int temp;
    if (negative) temp = 1;
    else temp = 0;
    switch (n)
    {
    case 1: {cout << "ПК - " << temp << "." << print_vec(vec); break; }
    }
    cout << "\n Для продолжения работы программы нажмите ENTER... \n";
    char ch;
    do {
        ch = _getch();
    } while (ch != 13);
}

bool exit() {
    char c = 89;
    cout << "\nЗавершить программу?(Y/N) ";
    for (;;) {
        char c;
        cin >> c;
        if (toupper(c) == 89)  return false;
        else if (toupper(c) == 78) return true;
        cout << "Неверно \nПродолжить деление?(Y/N) ";
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    do {
        mainBinary();
    } while (exit());

    return 0;
}