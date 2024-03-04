#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}

void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &result)
{
    int i = 0, j = 0;
    while ((i + j) < result.size())
    {
        if (i >= arr1.size())
        {
            for (; j < arr2.size(); ++j)
                result[i + j] = arr2[j];
            break;
        }
        else if (j >= arr2.size())
        {
            for (; i < arr1.size(); ++i)
                result[i + j] = arr1[i];
            break;
        }
        if (arr1[i] <= arr2[j])
            result[i++ + j] = arr1[i];
        else
            result[i + j++] = arr2[j];
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> first(n);
    for (int i = 0; i < n; ++i)
        cin >> first[i];
    cin >> m;
    vector<int> second(m), result(n + m);
    for (int i = 0; i < m; ++i)
        cin >> second[i];
    merge(first, second, result);
    print(result);
    return 0;
}