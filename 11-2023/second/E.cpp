#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

void reverse(string &a, string &b)
{
    for (int i = 0; i < a.size(); ++i)
        b[i] = a[a.size() - 1 - i];
}

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

bool isEqual(int startA, int startB, int len, vector<ull> &xPow, vector<ull> &hashes1, vector<ull> &hashes2)
{
    ull p = 1e9 + 7;
    ull first = (hashes1[startA + len] + hashes2[startB] * xPow[len]) % p;
    ull second = (hashes2[startB + len] + hashes1[startA] * xPow[len]) % p;
    return first == second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ull> xPow;
    vector<ull> hashes1, hashes2;
    string s;
    cin >> s;
    int n = s.size();
    string s2(n, 0);
    reverse(s, s2);
    accountHashes(s, xPow, hashes1);
    accountHashes(s2, xPow, hashes2);
    vector<int> chet(n, 0), nechet(n, 0);
    ull result = n;
    for (int len = n; len >= 2; --len)
    {
        for (int pos = 0; pos <= (n - len); ++pos)
        {
            // cout << pos << " " << pos + len << " " << s.length() - pos - len << "\n";
            int center = pos + (len - 1) / 2;
            if (isEqual(pos, n - pos - len, len, xPow, hashes1, hashes2))
            {
                if (len % 2 == 0)
                {
                    if (chet[center] > len)
                        continue;
                    else
                    {
                        chet[center] = len;
                    }
                }
                else
                {
                    if (nechet[center] > len)
                        continue;
                    else
                    {
                        nechet[center] = len;
                    }
                }
                int n_pos = pos;
                for (int j = len; j > 1; j -= 2)
                {
                    ++result;
                }
            }
        }
    }
    cout << result;
    return 0;
}