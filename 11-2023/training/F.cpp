#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull task()
{
    ull k, n;
    cin >> k >> n;
    ull result = 0, sum = 0;
    vector<ull> arr(n);
    for (int i = 0; i < n; ++i)
    cin >> arr[i];
    for (int i = n - 1; i >= 0; --i)
    {
        sum += arr[i];
        if (!sum) continue;
        result += 2 * ((sum + k - 1) / k);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << task();
    return 0;
}