#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int p, int left, int right)
{
    int l = left;
    int r = right;
    while (l < r)
    {
        while (arr[l] < p)
            if (l < right)
                ++l;
            else
                break;
        while (arr[r] >= p)
            if (r > left)
                --r;
            else
                break;
        if (l >= r)
            break;
        swap(arr[l], arr[r]);
    }
    return (arr[l] < p) ? l : l - 1;
}

void quickSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    if (l + 1 == r){
        if (arr[l] > arr[r]){
            swap(arr[l], arr[r]);
        }
        return;
    }
    int x = arr[(rand() % (r - l)) + l];
    int p = partition(arr, x, l, r);
    quickSort(arr, l, p);
    quickSort(arr, p + 1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    quickSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << " ";

    return 0;
}