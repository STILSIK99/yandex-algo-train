#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

void print(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}

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
    vector<int> d1(n, 0), d2(n, 0);
    int left1 = 0, right1 = -1, left2 = 0, right2 = -1;
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        int len1 = 1;
        if (i < right1)
        {
            len1 = min(d1[left1 + right1 - i], right1 - i + 1);
        }
        // radius
        int _maxLen = min(n - i + 1, i + 1);
        while (len1 < _maxLen)
        {
            int mid = (len1 + _maxLen + 1) / 2;
            int size = mid * 2 - 1;
            int startA = i - mid + 1;
            int startB = n - startA - size;
            if (isEqual(startA, startB, size, xPow, hashes1, hashes2))
            {
                len1 = mid;
            }
            else
            {
                _maxLen = mid - 1;
            }
        }
        left1 = i - len1 + 1;
        right1 = i + len1 - 1;
        d1[i] = len1;

        int len2 = 0;
        _maxLen = min(n - i, i + 1);
        while (len2 < _maxLen)
        {
            int mid = (len2 + _maxLen + 1) / 2;
            int size = mid * 2;
            int startA = i - mid + 1;
            int startB = n - startA - size;
            if (isEqual(startA, startB, size, xPow, hashes1, hashes2))
            {
                len2 = mid;
            }
            else
            {
                _maxLen = mid - 1;
            }
        }
        left2 = i - len2 + 1;
        right2 = i + len2 - 1;
        d2[i] = len2;
        result += d1[i] + d2[i];
    }
    cout << result << "\n";
    return 0;
}