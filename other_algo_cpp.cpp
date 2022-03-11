#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool isLetter(char s) {
    return (((int(toupper(s)) >= 65 && int(toupper(s)) <= 90) || int(toupper(s)) >= 192 && int(toupper(s)) <= 255) ? true : false);
}

bool letterMoreTwo(string str) {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ') {
            cnt++;
        }
        if (cnt > 1) return true;
    }
    return false;
}

void operationsForInput(string str, map<string, string>& word) {
    string buf;
    for (long long i = 0; i < str.size() + 1; i++)
    {
        if (isLetter(str[i]) && i < str.size()) buf += str[i];
        else if (buf.size() >= 2) {
            string temp = buf;
            sort(buf.begin(), buf.end());
            if (word[buf].find(temp) == string::npos) {
                word[buf] += " " + temp;
            }
            buf = "";
        }
        else buf = "";
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ifstream cin("input.txt");
    map <string, string> word;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, buff = "", resBuff = "";
    long long resCnt = 0;
    string str;

    while (!cin.eof())
    {
        getline(cin, str);
        operationsForInput(str, word);
    }

    cout << "Все найденные анаграммы: " << "\n";
    for (auto& i : word)
    {
        if (letterMoreTwo(i.second)) {
            cout << i.second << "\n";
        }

    }

    return 0;
}