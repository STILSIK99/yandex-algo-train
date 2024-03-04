#include <bits/stdc++.h>

using namespace std;

long double deijkstra(vector<vector<int>> &v, int start, int finish)
{
    vector<bool> used(v.size(), 0);
    vector<long double> inf (v.size(), 1e9);
    set<pair<long double, int>> que;
    que.insert(make_pair(0, start));
    while(!que.empty()){
        auto [road, n_v] = *que.begin();
        que.erase(que.begin());
        if (used[n_v]) continue;
        used[n_v] = 1;
        if (inf[n_v] < road) continue;
        if (n_v == finish) return road;
        for(int i = 0; i < v.size(); ++i){
            static int next_v, next_road;
            if (v[n_v][i] < 1) continue;
            next_v = i, next_road = road + v[n_v][i];
            if (next_v == n_v) continue;
            if (inf[next_v] < next_road) continue;
            if (inf[next_v] != 1e9) que.erase({next_road, next_v});
            inf[next_v] = next_road;
            que.insert({next_road, next_v});
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, f;
    cin >> n >> s >> f;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> v[i][j];
        }
    }
    cout << deijkstra(v, s - 1, f - 1);
    
    return 0;
}