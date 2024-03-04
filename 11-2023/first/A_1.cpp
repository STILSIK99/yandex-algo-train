#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}

pair<int, int> partition(vector<int> &arr, int p, int left, int right)
{
    int eqX = left,
        moreX = left;
    for (int i = left; i <= right; ++i)
    {
        // cout << "\n"
        //  << arr[i] << " ";
        if (arr[i] < p)
        {
            swap(arr[i], arr[moreX]);
            swap(arr[eqX++], arr[moreX++]);
        }
        else if (arr[i] == p)
        {
            swap(arr[i], arr[moreX++]);
        }
        else
        {
            if (arr[moreX] == p)
                ++moreX;
        }
        // cout << eqX << " " << moreX << "\n";
        // print(arr);
    }

    return {eqX, moreX};
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int p;
    cin >> p;
    auto [answer, moreX] = partition(arr, p, 0, arr.size() - 1);
    cout << answer << "\n"
         << n - answer;
    return 0;
}