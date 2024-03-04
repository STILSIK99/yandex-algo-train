#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}

void rotate(vector<int> &arr, int left, int right)
{
    int steps = (right - left) / 2;
    for (int i = 0; i <= steps; ++i)
        swap(arr[left + i], arr[right - i]);
}

int lowerBound(vector<int> &arr, int left, int right, int x)
{
    int l = left, r = right;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return (arr[l] < x) ? (l + 1) : l;
}

void inplaceMerge(vector<int> &arr, int left, int mid, int right)
{
    if (left > mid || mid == right)
        return;
    if (right - left < 2)
    {
        if (arr[left] > arr[right])
            swap(arr[left], arr[right]);
        return;
    }
    int midA = (left + mid) / 2;
    int midB = lowerBound(arr, mid + 1, right, arr[midA]) - 1;
    int midBA = midA + midB - mid;
    // A' A" B' B"
    if (mid != midB)
    {
        rotate(arr, midA, mid);
        rotate(arr, mid + 1, midB);
        rotate(arr, midA, midB);
    }
    // A' B' A" B"
    inplaceMerge(arr, left, midA - 1, midBA);
    inplaceMerge(arr, midBA + 1, midB, right);
}

void inplaceMergeSort(vector<int> &arr, int left, int right)
{
    if (left == right)
        return;
    int mid = (left + right) / 2;
    inplaceMergeSort(arr, left, mid);
    inplaceMergeSort(arr, mid + 1, right);
    inplaceMerge(arr, left, mid, right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    // vector<int> arr{1, 4, 3, 4, 1, 2, 3, 4, 6, 5};
    if (arr.size() > 1)
        inplaceMergeSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}