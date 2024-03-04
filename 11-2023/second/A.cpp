#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void accountHashes(string &s, vector<ull> &xPow, vector<ull> &hashes)
{
    ull x = 257;
    ull p = 1e9 + 7;
    ull curX = 1;
    xPow = vector<ull>(s.size() + 1);
    hashes = vector<ull>(s.size() + 1);
    hashes[0] = 0;
    xPow[0] = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        curX = (curX * x) % p;
        xPow[i + 1] = curX;
        hashes[i + 1] = (hashes[i] * x + s[i] - 'a' + 1) % p;
    }
}

bool isEqual(int startA, int startB, int len, vector<ull> &xPow, vector<ull> &hashes)
{
    ull p = 1e9 + 7;
    ull first = (hashes[startA + len] + hashes[startB] * xPow[len]) % p;
    ull second = (hashes[startB + len] + hashes[startA] * xPow[len]) % p;
    return first == second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ull> xPow;
    vector<ull> hashes;
    string s;
    cin >> s;
    accountHashes(s, xPow, hashes);
    int n;
    cin >> n;
    // for (auto x : hashes)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // for (auto x : xPow)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
    for (int i = 0; i < n; ++i)
    {
        static int L, A, B;
        cin >> L >> A >> B;
        cout << ((isEqual(A, B, L, xPow, hashes)) ? "yes\n" : "no\n");
    }

    return 0;
}