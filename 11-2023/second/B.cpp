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
        hashes[i + 1] = (hashes[i] * x + s[i]) % p;
    }
}

bool isEqual(int startA, int startB, int len, vector<ull> &xPow, vector<ull> &hashes)
{
    ull p = 1e9 + 7;
    // cout << hashes[startA + len] << "\n";
    // cout << hashes[startA] * xPow[len] << "\n";
    // cout << hashes[startB + len] << "\n";
    // cout << hashes[startB] * xPow[len] << "\n";
    // cout << (hashes[startA + len] + hashes[startB] * xPow[len]) % p << "\n";
    // cout << (hashes[startB + len] + hashes[startA] * xPow[len]) % p << "\n";

    ull first = (hashes[startA + len] + hashes[startB] * xPow[len]) % p;
    ull second = (hashes[startB + len] + hashes[startA] * xPow[len]) % p;
    return first == second;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    vector<ull> xPow;
    vector<ull> hashes;
    string s;
    cin >> s;
    accountHashes(s, xPow, hashes);
    int result = s.length();
    for (int k = 1; k < s.length(); ++k)
    {
        if (isEqual(0, k, s.length() - k, xPow, hashes))
        {
            result = k;
            break;
        }
    }
    cout << result;
    return 0;
}