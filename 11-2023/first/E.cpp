#include <bits/stdc++.h>

using namespace std;
typedef unsigned long ul;

void print(vector<string> &arr)
{
    cout << arr[0];
    for (int i = 1; i < arr.size(); ++i)
        cout << ", " << arr[i];
    cout << "\n";
}

void printBucket(vector<vector<string>> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << "Bucket " << i << ": ";
        if (arr[i].size())
            print(arr[i]);
        else
            cout << "empty\n";
    }
}

int getDigitRank(string s, int digit)
{
    return (s.length() >= digit) ? (s[s.length() - digit] - 48) : 0;
}

void accounting(vector<string> &arr, int digit, vector<int> &account)
{
    vector<vector<string>> counting(10, vector<string>(0));
    account = vector<int>(10, 0);
    for (auto x : arr)
    {
        auto mean = getDigitRank(x, digit);
        ++account[mean];
        counting[mean].push_back(x);
    }
    int last = account[0];
    account[0] = 0;
    for (int i = 1; i < account.size(); ++i)
    {
        static int cur;
        cur = account[i];
        account[i] = account[i - 1] + last;
        last = cur;
    }
    printBucket(counting);
}

void rankSortMerge(vector<string> &in, vector<string> &out, vector<int> &positions, int digit)
{
    for (auto x : in)
    {
        auto pos = positions[getDigitRank(x, digit)]++;
        out[pos] = x;
    }
    // cout << digit << "\n";
    // print(out);
}

void rankSort(vector<string> &arr1, int ranks)
{
    vector<string> arr2(arr1.size());
    vector<int> positions(10);
    cout << "Initial array:\n";
    print(arr1);
    cout << "**********\n";
    for (int digit = 1; digit <= ranks; ++digit)
    {
        cout << "Phase " << digit << "\n";
        if (digit % 2)
        {
            accounting(arr1, digit, positions);
            rankSortMerge(arr1, arr2, positions, digit);
        }
        else
        {
            accounting(arr2, digit, positions);
            rankSortMerge(arr2, arr1, positions, digit);
        }
        cout << "**********\n";
    }
    if (ranks % 2) arr1 = arr2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    size_t rank = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        rank = max(rank, arr[i].length());
    }
    // vector<string> arr{"142", "1123", "12412452", "423", "5264", "24332", "67", "962"};
    // int rank = 8;
    rankSort(arr, rank);
    cout << "Sorted array:\n";
    print(arr);
    return 0;
}