#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

struct Node {
    int val;
    Node* next;
};
Node* first = NULL;

void loopingList(int n, int loopingElem) {
    Node* listUse = first;
    Node* saveLoopingElem = NULL;
    for (int i = 1; i <= n; i++) {
        int x = rand() + 5;
        if (first == NULL) {
            first = new(Node);
            first->val = x;
            first->next = NULL;
            listUse = first;
        }
        else
        {
            listUse->next = new (Node);
            listUse = listUse->next;
            listUse->val = x;
            listUse->next = NULL;
        }
        if (i == loopingElem) {
            saveLoopingElem = listUse;
        }
        if (i == n) {
            listUse->next = saveLoopingElem;
        }
    }
}

void sequenceNode(int n) {
    Node* listUse = first;
    for (int i = 1; i <= n; i++) {
        int x = rand() + 5;
        if (first == NULL) {
            first = new(Node);
            first->val = x;
            first->next = NULL;
            listUse = first;
        }
        else
        {
            listUse->next = new (Node);
            listUse = listUse->next;
            listUse->val = x;
            listUse->next = NULL;
        }
    }
}

int findSequenceNode() {
    int k = 0;
    Node* temp = first;
    while (temp != NULL)
    {
        k++;
        temp = temp->next;
    }
    return k;
}

int findLoopingNode() {
    int kk = 0, k = 0;
    Node* temp = first;
    while (true)
    {
        k++;
        temp = temp->next;
        Node* tempCycle = first;
        while (tempCycle != temp)
        {
            kk++;
            tempCycle = tempCycle->next;
        }
        if (kk != k) break;
        kk = 0;
    }
    return k--;
}

void printList(Node* list) {
    Node* temp = list;
    while (true)
    {
        cout << temp->val << " ";

        temp = temp->next;
    }
}

int main() {
    Node* list = NULL;
    setlocale(LC_ALL, "RUS");
    int n, num, loopingElem;
    cout << "Введите кол-во элементов: "; cin >> num;
    cout << "Выберите список: \n 1. Линейный список \n 2. Цикличный список \n Ввод: "; cin >> n;
    switch (n)
    {
    case 1: {
        sequenceNode(num);
        cout << "Кол-во элементов в списке: " << findSequenceNode();
        break;
    }
    case 2: {
        cout << "Введите элемент зацикливания списка: "; cin >> loopingElem;
        loopingList(num, loopingElem);
        cout << "Кол-во элементов в списке: " << findLoopingNode();
        break;
    }
    }
}