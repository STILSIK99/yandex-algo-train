#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void task()
{
    ull n, a, b;
    cin >> n >> a >> b;
    ull _min = n - (n % a);
    ull _max = n / a * b;
    if (n >= _min && n <= _max)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        task();
    }

    return 0;
}