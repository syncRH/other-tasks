#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;

bool isNumber(char symbol) { return (symbol >= '0' && symbol <= '9'); }

int prioritySymbol(char symbolInput) {
	switch (symbolInput) {
	case '(': return 1;
	case '-': return 2;
	case '+': return 2;
	case '*': return 3;
	case '/': return 3;
	case ')': return 4;
	}
	return 0;
}


string treatmentStack(char symbolInput, stack <char>& stackOperations) {
	string buffer = "";
	if (!stackOperations.empty() && prioritySymbol(symbolInput) != 0) {
		if (prioritySymbol(symbolInput) <= prioritySymbol(stackOperations.top())) {
			if (prioritySymbol(symbolInput) != 1) {
				buffer += stackOperations.top();
				stackOperations.pop();
				stackOperations.push(symbolInput);
			}
			else stackOperations.push(symbolInput);
		}
		if (prioritySymbol(symbolInput) > prioritySymbol(stackOperations.top()) && prioritySymbol(symbolInput) != 4) {
			stackOperations.push(symbolInput);
		}
		if (prioritySymbol(symbolInput) == 4) {
			while (!stackOperations.empty()) {
				if (prioritySymbol(stackOperations.top()) == 1) {
					stackOperations.pop();
					break;
				}
				else {
					buffer += stackOperations.top();
					stackOperations.pop();
				}
			}
		}
	}
	else if (stackOperations.empty()) stackOperations.push(symbolInput);
	return buffer;
}

int main() {
	int len = 0;
	string strInput, strOutput = "";
	queue <int> lengthNumber;
	stack <char> stackOperations;
	getline(cin, strInput);
	for (auto& symb : strInput) {
		if (isNumber(symb)) {
			strOutput += symb;
			len++;

		}
		else {
			strOutput += treatmentStack(symb, stackOperations);
			if (len != 0) {
				lengthNumber.push(len);
				len = 0;
			}
		}
	}
	if (len != 0) {
		lengthNumber.push(len);
		len = 0;
	}
	while (!stackOperations.empty()) {
		strOutput += stackOperations.top();
		stackOperations.pop();
	}
	int jk = 0;
	for (auto& symb : strOutput) {
		if (isNumber(symb)) {
			if (jk != lengthNumber.front()) {
				jk++;
				cout << symb;
			}
			if (jk == lengthNumber.front()) {
				jk = 0;
				lengthNumber.pop();
				cout << " ";
			}
		}
		else cout << symb << " ";
	}
}