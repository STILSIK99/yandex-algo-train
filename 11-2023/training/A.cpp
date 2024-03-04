#include <bits/stdc++.h>

using namespace std;

int getNoMin(const vector<int> &arr, int left, int right)
{
    int result = arr.at(left);
    for (; left <= right; ++left)
        if (result != arr.at(left))
            return max(result, arr.at(left));
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0; i < m; ++i){
        static int left, right, result;
        cin >> left >> right;
        result = getNoMin(arr, left, right);
        if (result) cout << result << "\n";
        else cout << "NOT FOUND\n";
    }
    return 0;
}