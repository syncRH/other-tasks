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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map <ll, ll> mapDays;
    ll k, n, day, temp = 0;
    cin >> n >> k;
    for (size_t i = 1; i <= n; i++) {
        cin >> day;
        int j = day;
        mapDays[day + 1]++;
        /*while (j < k) {
            vecDay[j]++;
            j += day + 1;
        }*/
    }
    auto it = mapDays.end();
    it--;
    ll maxI = it->first;
    vector <ll> vecDay(k, 0);
    for (auto it2 = mapDays.begin(); it2 != mapDays.end(); it2++) {
        for (int b = it2->first - 1; b < k; b += it2->first)
            vecDay[b] += it2->second;
    }
    for (size_t i = 0; i < k; i++)
    {
        cout << vecDay[i] << " ";
    }
    return 0;
}