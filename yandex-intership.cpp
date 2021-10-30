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
typedef unsigned long long ull;

ull findMan(vector <ull>& vectorMans, ull size) { // long search
    bool(flag) = false;
    ll i = 0;
    ull temp = 0;

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
    ull countMans = 0, sizePrevTower = 0, temp, maxSizeTower = 0;
    vector <ull> vectorMans;
    stack <ull> stackTowers;
    cin >> n >> m;


    for (ll i = 0; i < n; i++) {
        cin >> temp;
        stackTowers.push(temp);
        if (temp > maxSizeTower) maxSizeTower = temp;
    }

    for (ll i = 0; i < m; i++) {
        cin >> temp;
        if (temp <= maxSizeTower) vectorMans.push_back(temp);
    }
    sort(vectorMans.begin(), vectorMans.end(), greater<ll>());
    while (!stackTowers.empty()) {
        temp = stackTowers.top();
        if (temp > sizePrevTower || sizePrevTower == 0) {
            auto iter = lower_bound(vectorMans.rbegin(), vectorMans.rend(), (temp - sizePrevTower), greater<ll>()); // binsearh
            if (iter != vectorMans.rend()) {
                countMans++;
          //      vectorMans.erase(std::remove(vectorMans.begin(), vectorMans.end(), iter), vectorMans.end());
            }

            sizePrevTower = temp;
        }
        stackTowers.pop();
    }
    cout << countMans;
    return 0;
}