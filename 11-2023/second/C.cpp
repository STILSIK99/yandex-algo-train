#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void reverse(vector<int> & arr1, vector<int> & arr2){
    for(int i = 0; i < arr1.size(); ++i){
        arr2[i] = arr1[arr1.size() - 1 - i];
    }
}

void print(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}

void accountHashes(vector<int> &s, vector<ull> &xPow, vector<ull> &hashes)
{
    ull x = 257;
    ull p = 1e9 + 7;
    ull curX = 1;
    xPow = vector<ull>(s.size() + 1);
    hashes = vector<ull>(s.size() + 1);
    hashes[0] = 0;
    xPow[0] = 0;
    for (int i = 0; i < s.size(); ++i)
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
    vector<ull> xPow;
    vector<ull> hashes1, hashes2;
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(n);
    for(int i = 0; i < arr1.size(); ++i){
        cin >> arr1[i];
    }
    reverse(arr1, arr2);
    accountHashes(arr1, xPow, hashes1);
    accountHashes(arr2, xPow, hashes2);
    int len = arr1.size();
    set<int> ans;
    for (int i = 1; i <= arr1.size() / 2; ++i)
    {
        int pos = len - 2 * i;
        if (isEqual(0, pos, i, xPow, hashes1, hashes2))
        {
            ans.insert(len - i);
        }
    }
    for(auto x : ans){
        cout << x << " ";
    }
    cout << len;
    return 0;
}