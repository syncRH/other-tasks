#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/*
я не знаю - удаляет все числа по одному разу
я знаю - удаляет больше двух раз.
*/
/*void printMapMathStr(vector <string> vec, int maxLength) {
	for (size_t i = 0; i < vec.size(); i++){
		printf("%s\n", vec[i]);
	}
}
void printMapMath(map <int, map<int, int>>& mathMas, int n) {
	cout << endl;
	int maxLength = 0;
	vector <string> vec;
	string buffer;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mathMas[i][j] != 0 && j >= i) {
				cout << i + j << "/" << i * j << " ";
				buffer += to_string(i + j) + "/" + to_string(i * j) + " ";
			}
			else { cout << " -- "; buffer += " -- "; }
		}
		if (buffer.length() > maxLength) maxLength = buffer.length();
		vec.push_back(buffer);
		cout << endl;
	}
}*/

void printMapMath(map <int, map<int, int>>& mathMas, int n) {
	cout << endl;
	int maxLength = 0;
	vector <string> vec;
	string buffer;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mathMas[i][j] != 0 && j >= i) {
				cout << i + j << "/" << i * j << " ";
				buffer += to_string(i + j) + "/" + to_string(i * j) + " ";
			}
			else { cout << " -- "; buffer += " -- "; }
		}
		if (buffer.length() > maxLength) maxLength = buffer.length();
		vec.push_back(buffer);
		cout << endl;
	}
}

int outsideMath() {
	int n;
	cout << endl << "Ваш ответ. " << "\n 1. Я не знаю эти числа \n 2. Я знаю эти числа. \n Ввод: "; cin >> n;
	return n;
}
void initMap(map <int, map<int, int>>& mathMas, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= i) {
				mathMas[i][j] = 1;
			}
			else mathMas[i][j] = 0;
		}
	}
}
void actionMath(map <int, map<int, int>>& mathMas, int n, int actionMath) {
	int temp = 0;
	bool(more) = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mathMas[i][j] != 0) {
				for (int ik = 1; ik <= n; ik++) {
					for (int jki = 1; jki <= n; jki++)
					{
						if (jki >= ik && (i != ik) && (j != jki) && (mathMas[ik][jki] != 0)) {
							if (actionMath == 1) {
								if ((i + j) == (ik + jki)) mathMas[ik][jki] = 0, more = true;
							}
							else if (actionMath == 2) {
								if ((i * j) == (ik * jki)) mathMas[ik][jki] = 0, more = true;
							}
							else if (actionMath == 3) {
								if ((i + j) == (ik + jki)) more = true;
							}
							else if (actionMath == 4) {
								if ((i * j) == (ik * jki)) more = true;

							}
						}
					}
				}
				if (more && (actionMath <= 2)) mathMas[i][j] = 0;
				else if ((actionMath >= 3) && (!more)) mathMas[i][j] = 0;
				more = false;
			}
		}
	}
}


void moveMathP(map <int, map<int, int>>& mathMas, int n) {
	cout << "Ход математика P";
	printMapMath(mathMas, n);
	int nn = outsideMath();
	if (nn == 1) {
		printMapMath(mathMas, n);
		actionMath(mathMas, n, 4);
	}
	else if (nn == 2) {
		printMapMath(mathMas, n);
		actionMath(mathMas, n, 2);
	}
}

void moveMathS(map <int, map<int, int>>& mathMas, int n) {
	cout << "Ход математика S";
	printMapMath(mathMas, n);
	int nn = outsideMath();
	if (nn == 1) {
		printMapMath(mathMas, n);
		actionMath(mathMas, n, 3);
	}
	else if (nn == 2) {
		printMapMath(mathMas, n);
		actionMath(mathMas, n, 1);
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, a, b, moveMath;
	bool(game) = true;
	map <int, map<int, int>> mathMas;
	cout << "Введите N: "; cin >> n;
	initMap(mathMas, n);
	cout << "За кем первый ход? \n 1. Математик S. \n 2. Математик P. \n Ввод: "; cin >> moveMath;
	while (game) {
		if (moveMath % 2 == 0) {
			moveMathP(mathMas, n);
		}
		else if (moveMath % 2 == 1) {
			moveMathS(mathMas, n);
		}
		moveMath++;
	}
}