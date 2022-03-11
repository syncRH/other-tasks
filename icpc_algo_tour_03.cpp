#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <iomanip>
using namespace std;
typedef long long ll;

unsigned long long findMan(vector <unsigned long long>& vectorMans, unsigned long long size) {
    bool(flag) = false;
    ll i = 0;
    unsigned long long temp = 0;
    while (i < vectorMans.size() && !flag) {
        if (vectorMans[i] <= size) {
            temp = vectorMans[i];
            vectorMans.erase(vectorMans.begin() + i);
            flag = true;
        }
        else i++;
    }
    if (flag) return temp;
    else return 0;
}

int main() {
    ll n, m;
    unsigned long long countMans = 0, sizePrevTower = 0, temp;
    vector <unsigned long long> vectorMans;
    stack <unsigned long long> stackTowers;
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        cin >> temp;
        stackTowers.push(temp);
    }

    for (ll i = 0; i < m; i++) {
        cin >> temp;
        vectorMans.push_back(temp);
    }
    sort(vectorMans.begin(), vectorMans.end(), greater<ll>());
    while (!stackTowers.empty()) {
        temp = stackTowers.top();
        if (temp > sizePrevTower || sizePrevTower == 0) {
            countMans += findMan(vectorMans, (temp - sizePrevTower)) > 0;
            sizePrevTower = temp;
        }
        stackTowers.pop();
    }
    cout << countMans;
    return 0;
}