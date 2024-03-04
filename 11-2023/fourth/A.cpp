#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &a)
{
    for (auto x : a)
        cout << x + 1;
    cout << "\n";
}

void recur(vector<int> &chain, vector<int> &used)
{
    if (chain.size() == used.size())
    {
        print(chain);
        return;
    }
    for (int i = 0; i < used.size(); ++i)
    {
        if (used[i])
            continue;
        chain.push_back(i);
        used[i] = 1;
        recur(chain, used);
        chain.pop_back();
        used[i] = 0;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> used(n, 0);
    vector<int> chain;
    recur(chain, used);

    return 0;
}