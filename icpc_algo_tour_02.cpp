#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <iomanip>
using namespace std;
typedef long long ll;

using namespace std;
typedef  vector<double>  vect;
typedef  vector<vect>    matrix;

matrix  minor(matrix A, const int& i, const int& j)
{
    A.erase(A.begin() + i);
    for (auto& a_m : A)
    {
        a_m.erase(a_m.begin() + j);
    }
    return A;
}

double det(const matrix& A)
{
    int  m = A.size();
    int  n = A[0].size();
    if (m != n)
        return NAN;
    if (n == 1)
        return A[0][0];
    int  signum = 1;
    int  summ = 0;
    int  j = 0;
    for (auto& a_0j : A[0])
    {
        summ += a_0j * signum * det(minor(A, 0, j));
        // signum *= -1;
        j++;
    }
    return summ;
}


int main()
{
    int n, temp;
    cin >> n;
    matrix A;
    matrix B;
    vect BC;
    for (size_t i = 1; i <= n + 1; i++)
    {
        BC.push_back(0);
    }
    for (size_t i = 1; i <= n + 1; i++)
    {
        for (size_t j = 0; j < n + 1; j++)
        {
            cin >> temp;
            BC[j] = temp;
        }
        A.push_back(BC);
    }
    cout << det(A);
    return 0;
}