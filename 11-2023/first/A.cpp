#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int p, int left, int right)
{
    if (arr.size() == 0) return 0;
    while(left < arr.size()){
        while (arr[left] < p)
            if (left < arr.size() - 1)
                ++left;
            else break;
        while (arr[right] >= p)
            if (right > 0)
                --right;
            else break;
        if (left >= right) break;
        swap(arr[left], arr[right]);
    }
    return (arr[left] < p) ? left + 1 : left;
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
    int answer = partition(arr, p, 0, arr.size() - 1);
    cout << answer << "\n" << n - answer;
    return 0;
}