#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}

int recur(int row, vector<int> &col, vector<int> &diag, int n)
{
    int result = 0;
    if (row == n) return 1;
    for (int i = 0; i < n; ++i)
    {
        if (col[i] + diag[i + row] + diag[i - row + 100]) continue;
        col[i] = diag[i + row] = diag[i - row + 100] = 1;
        result += recur(row + 1, col, diag, n);
        col[i] = diag[i + row] = diag[i - row + 100] = 0;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> col(n, 0), diag(100 + 2 * n, 0);
    cout << recur(0, col, diag, n);
    return 0;
}