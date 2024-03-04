#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}


int lowerBound(vector<int> &arr, int left, int right, int x)
{
    int l = left, r = right;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= x){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return (arr[l] < x) ? (l + 1) : l;
}


void rotate(vector<int> & arr, int left, int right){
    int steps = (right - left) / 2;
    for(int i = 0; i <= steps; ++i)
        swap(arr[left + i], arr[right - i]);
}

int main(){
    int i = 0, j = 0;
    vector<int> arr {1, 2, 3 ,4, 1, 2, 3 ,4 , 5, 6};
    rotate(arr, 2, 5);
    print(arr);
    rotate(arr, 2, 3);
    print(arr);
    rotate(arr, 4, 5);
    print(arr);
    return 0;
}
