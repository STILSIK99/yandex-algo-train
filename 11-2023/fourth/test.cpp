#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int s = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2)
            s += (1 << i);
    }
    cout << s << '\n';
    for (int i = 0; i < 10; ++i)
    {
        if (s & (1 << i))
            cout << i << " ";
    }
    return 0;
}