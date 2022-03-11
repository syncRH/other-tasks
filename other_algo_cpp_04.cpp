#include <iostream>
#include <string>
using namespace std;


void initMass(int mas[][2], int sizeMass) {
	cout << "Ввод граничных пар.\n";
	for (int i = 0; i < sizeMass; i++) {
		cout << "Введите " << i + 1 << " граничную пару: ";
		for (int j = 0; j < 2; j++)
		{
			cin >> mas[i][j];
		}
	}
}
int calcAdress(int mas[][2], int n, int A1, int L, int* masD) {
	int buffer = 0, adress = A1;
	cout << "Введите индекс массива: ";
	for (int i = 0; i < n; i++) {
		cin >> buffer;
		adress += masD[i] * (buffer - mas[i][0]);
	}
	return adress;
}

string indexFactors(int mas[][2], int n, int Length, int* masD) {
	string buffer = "";
	for (int i = n; i > 0; i--)
	{
		Length *= abs(mas[i][1] - mas[i][0]) + 1;
		buffer = buffer + ("D") + to_string(i) + (" = ") + to_string(Length) + "\n";
		masD[i - 1] = Length;
	}
	return buffer;
}

string writeByAdress(char* masChar, int adress) {
	string str = "", bufferStr = "Запись в ячейки с индексами: ";
	cout << "Введите символы для записи: "; cin >> str;

	for (size_t i = 0; i < str.length(); i++) {
		masChar[adress + i] = str[i];
		bufferStr += " " + to_string(adress + i);
	}
	return bufferStr + "\n";
}

void writeByIndex(char* masChar) {
	char sym;
	int index;
	cout << "Введите символ для записи: "; cin >> sym;
	cout << "Введите индекс для записи: "; cin >> index;
	masChar[index] = sym;
}

string readByIndex(char* masChar) {
	int index = 0;
	cout << "Введите индекс: "; cin >> index;
	return ("По заданному индексу " + to_string(index) + " расположено значение: " + masChar[index] + "\n");
}

string readByAdress(char* masChar, int adress, int length) {
	string bufferStr = "Элементы расположенные по заданному адресу: ";
	for (int i = 0; i < length; i++) {
		bufferStr.push_back(masChar[adress + i]);
	}
	return bufferStr + "\n";
}

bool choiceOfOperation(int mas[][2], int Length, int A1, int sizeMass, int* masD, char* masChar) {
	int n = 0;
	cout << "Выберите операцию: \n 1 - Записать через адрес. \n 2 - Записать через индекс \n"
		<< " 3 - Прочитать через адрес. \n 4 - Прочитать через индекс. \n Введите цифру: ";
	cin >> n;
	switch (n)
	{
	default: { return false; break; }
	case 1: {
		cout << writeByAdress(masChar, calcAdress(mas, sizeMass, A1, Length, masD)) << endl;
		return true;
		break;
	}
	case 2: {
		writeByIndex(masChar);
		return true;
		break;
	}
	case 3: {
		cout << readByAdress(masChar, calcAdress(mas, sizeMass, A1, Length, masD), Length) << endl;
		return true;
		break;
	}
	case 4: {
		cout << readByIndex(masChar) << endl;
		return true;
		break;
	}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int mas[1000][2] = { 0 }, Length = 0, A1 = 0, sizeMass = 0, masD[1000];
	char masChar[1000];
	cout << "Введите размерность массив: "; cin >> sizeMass;
	cout << "Введите длину слота: "; cin >> Length;
	cout << "Введите адрес первого элемента: "; cin >> A1;
	initMass(mas, sizeMass);
	cout << indexFactors(mas, sizeMass, Length, masD);
	while (choiceOfOperation(mas, Length, A1, sizeMass, masD, masChar));
}