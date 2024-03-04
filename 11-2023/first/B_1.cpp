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

    return {eqX, (arr[moreX] == p) ? (moreX + 1) : moreX};
}

void quickSort(vector<int> & arr, int left, int right){
    // cout << "\n" << left << " " << right << "\n";
    // print(arr);
    if (left >= right) return;
    int mid = (rand() % (right - left)) + left;
    auto [e, g] = partition(arr, arr[mid], left, right);
    // print(arr);
    quickSort(arr, left, e - 1);
    quickSort(arr, g, right);
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    quickSort(arr, 0, arr.size() - 1);
    print(arr);   
    return 0;
}