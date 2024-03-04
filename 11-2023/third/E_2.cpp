#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void print(vector<int> &a, int add)
{
    for (auto x : a)
        cout << x + add << " ";
    cout << "\n";
}

void bfs(vector<map<int, int>> &matrix, vector<int> &distances, int start)
{
    distances[start] = 0;
    vector<bool> used(matrix.size(), 0);
    queue<int> q;
    q.emplace(start);
    used[start] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto e : matrix[node])
        {
            if (used[e.first])
                continue;
            distances[e.first] = distances[node] + e.second;
            q.emplace(e.first);
            used[e.first] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n;
    set<tuple<int, int, int>> yam;
    vector<map<int, int>> lens(n, map<int, int>());
    vector<vector<int>> allLens(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        static int t, s;
        cin >> t >> s;
        yam.insert({s, t, i});
    }
    for (int i = 0; i < n - 1; ++i)
    {
        static int a, b, l;
        cin >> a >> b >> l;
        lens[a - 1][b - 1] = l;
        lens[b - 1][a - 1] = l;
    }
    for (int i = 0; i < n; ++i)
    {
        bfs(lens, allLens[i], i);
    }
    lens.clear();
    vector<ld> times(n);
    vector<int> into(n, 0);
    set<pair<ld, int>> results;
    for(auto it = yam.rbegin(); it != yam.rend(); ++it){
        auto [speed, addTime, v] = *it;
        // cout << get<0>(*it) << " " << get<1>(*it) << " " << get<2>(*it) << "\n";
        ld result = allLens[0][v] / 1. / speed + addTime; 
        into[v] = 0;
        for(auto faster : results){
            if (faster.first > result) break;
            ld road = addTime + allLens[faster.second][v] / 1. / speed + faster.first;
            if (road < result){
                result = road;
                into[v] = faster.second;
            }
        }
        results.insert({result, v});
    }
    cout << fixed << setprecision(10) << results.rbegin()->first << "\n";
    int node = results.rbegin()->second;
    while(node != 0){
        cout << node + 1 << " ";
        node = into[node];
    }
    cout << 1;
    return 0;
}