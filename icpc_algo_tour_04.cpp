#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;


/*
* Номера состояний и их расшифровка
* -1 - не приезжал на дачу
* 0 - сосед не приезжал.
* 1 - сосед на даче
* 2 - ожидает уезда
* 3 - стоит на парковке
* 4 - уехал с дачи.
*/
void neighborLeft(stack <int>& stackNeighbor, map <int, int>& mapNeighbor, int numberNeighbor) {
    for (int i = 1; i <= numberNeighbor; i++) {
        if (mapNeighbor[i] != 1) {
            if (stackNeighbor.top() == i) {
                mapNeighbor[i] = 4, stackNeighbor.pop();
            }
        }
        else break;
    }
}

int main()
{
    int n, m, neighbor;
    char action;
    bool(flag) = true;
    stack <int> stackNeighbor;
    map <int, int> mapNeighbor;
    stackNeighbor.push(100001);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> action >> neighbor;
        if ((action == '+') && (neighbor < stackNeighbor.top())) stackNeighbor.push(neighbor), mapNeighbor[neighbor] = 1;
        else if (action == '+' && (neighbor > stackNeighbor.top())) mapNeighbor[neighbor] = 3;
        if ((action == '-') && (stackNeighbor.top() == neighbor)) stackNeighbor.pop(), mapNeighbor[neighbor] = 4;
        else if ((action == '-') && (stackNeighbor.top() != neighbor) && (mapNeighbor[neighbor] != 3)) {
            mapNeighbor[neighbor] = 2;
        }
        else if ((action == '-') && (mapNeighbor[neighbor] == 3)) mapNeighbor[neighbor] = 4;
        if ((action == '-') && (mapNeighbor[neighbor] != 3)) neighborLeft(stackNeighbor, mapNeighbor, n);
    }

    for (int i = 1; i <= n; i++)
    {
        if (mapNeighbor[i] == 4) cout << "YES" << endl;
        else if (mapNeighbor[i] == 1) cout << "NO" << endl;
        else if (mapNeighbor[i] == 2) cout << "NO" << endl;
        else if (mapNeighbor[i] == 3) cout << "NO" << endl;
        else if (mapNeighbor[i] == 0) cout << "-1" << endl;
    }

}