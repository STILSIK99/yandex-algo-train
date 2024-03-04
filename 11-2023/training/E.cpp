#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n), sums(n, 0);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
        sums[i] = sum;
    }
    for(int i = 0; i < n; ++i){
        static int prev, past;
        prev = arr[i] * (i + 1) - sums[i];
        past = sum - sums[i] - (arr[i] * (n - i - 1));
        cout << prev + past << ' ';
    }

    return 0;
}