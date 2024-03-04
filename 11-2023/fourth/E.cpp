#include <bits/stdc++.h>

using namespace std;

void print(vector<char> &a)
{
    for (auto x : a)
        cout << x;
    cout << "\n";
}

void recur(int pos, vector<char> &chain, vector<char> &opened)
{
    if (pos == chain.size())
    {
        if (!opened.size())
            print(chain);
        return;
    }

    // open new bracket
    if (pos + 2 + opened.size() <= chain.size())
    {
        chain[pos] = '(';
        opened.push_back('(');
        recur(pos + 1, chain, opened);
        chain[pos] = '[';
        opened[opened.size() - 1] = '[';
        recur(pos + 1, chain, opened);
        opened.pop_back();
    }
    // close bracket
    if (opened.size() == 0)
        return;
    char last = opened[opened.size() - 1];
    chain[pos] = (last == '(') ? ')' : ']';
    opened.pop_back();
    recur(pos + 1, chain, opened);
    opened.push_back(last);
}

int main()
{
    int n;
    cin >> n;
    if (n % 2 || !n)
        return 0;
    vector<char> chain(n);
    vector<char> opened;
    recur(0, chain, opened);
    return 0;
}