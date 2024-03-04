#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(vector<ll> &arr)
{
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
}

void rotate(vector<ll> &arr, ll left, ll right)
{
    ll steps = (right - left) / 2;
    for (ll i = 0; i <= steps; ++i)
        swap(arr[left + i], arr[right - i]);
}

int lowerBound(vector<ll> &arr, ll left, ll right, ll x)
{
    ll l = left, r = right;
    while (l < r)
    {
        ll mid = (l + r) / 2;
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

void inplaceMerge(vector<ll> &arr, ll left, ll mid, ll right)
{
    if (left > mid || mid == right)
        return;
    if (right - left < 2)
    {
        if (arr[left] > arr[right])
            swap(arr[left], arr[right]);
        return;
    }
    ll midA = (left + mid) / 2;
    ll midB = lowerBound(arr, mid + 1, right, arr[midA]) - 1;
    ll midBA = midA + midB - mid;
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

void inplaceMergeSort(vector<ll> &arr, ll left, ll right)
{
    if (left == right)
        return;
    ll mid = (left + right) / 2;
    inplaceMergeSort(arr, left, mid);
    inplaceMergeSort(arr, mid + 1, right);
    inplaceMerge(arr, left, mid, right);
}

vector<ll> task_2()
{
    ll x = 1e7;
    // cin >> x;
    vector<ll> qwadr(1e7 + 1e6);
    vector<bool> q(1e5 + 10, 0);
    ll el = 1, s = 1, sum = 3;
    qwadr[0] = 1;
    for (ll i = 2; i <= x; ++i)
    {
        
        s += sum;
        qwadr[el++] = s;
        if (s < 1e5)
            q[s] = 1;
        sum += 2;
    }
    ll last_c = 0;
    ll r = 1e5;
    for (ll i = 2; i <= r; ++i)
    {
        last_c = i * i * i;
        if (!q[i])
        {
            qwadr[el++] = last_c;
            // cout << *it << " ";
        }
    }
    cout << qwadr[el - 1] << " " << el;
    inplaceMerge(qwadr, 0, x - 1, el - 1);
    return qwadr;
}

ll task(ll x)
{
    // ll x;
    // cin >> x;
    vector<ll> qwadr(1e7 + 1e6);
    vector<bool> q(1e5 + 10, 0);
    ll el = 1, s = 1, sum = 3;
    qwadr[0] = 1;
    for (ll i = 2; i <= x; ++i)
    {
        
        s += sum;
        qwadr[el++] = s;
        if (s < 1e5)
            q[s] = 1;
        sum += 2;
    }
    ll last_c = 0;
    ll r = pow(s, 1. / 3);
    for (ll i = 2; i <= r; ++i)
    {
        last_c = i * i * i;
        if (!q[i])
        {
            qwadr[el++] = last_c;
            // cout << *it << " ";
        }
    }
    inplaceMerge(qwadr, 0, x - 1, el - 1);
    return qwadr[x - 1];
    // cout << result - distance(qwadr.begin(), qwadr.upper_bound(x));
    // cout << "task\n";
}

int main()
{
    int t = 10000000;
    // cin >> t;
    // task(6);
    auto mas = task_2();
    for (int i = 1; i <= t; ++i)
    {
        auto res = task(i);
        if (mas[i - 1] != res){
            cout << i << "correct: " << mas[i - 1] << "\n";
            cout << res << " - result\n";
        }
    }

    return 0;
}