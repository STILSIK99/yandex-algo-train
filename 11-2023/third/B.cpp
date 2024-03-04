#include <bits/stdc++.h>

using namespace std;

vector<int> deijkstra(vector<vector<pair<int, int>>> &v, int start, int finish)
{
    vector<bool> used(v.size(), 0);
    vector<int> from(v.size(), -1);
    vector<long double> inf(v.size(), 1e9);
    set<pair<long double, int>> que;
    que.insert(make_pair(0, start));
    from[start] = start;
    inf[start] = 0;
    while (!que.empty())
    {
        auto [road, n_v] = *que.begin();
        que.erase(que.begin());
        if (used[n_v])
            continue;
        used[n_v] = 1;
        if (inf[n_v] < road)
            continue;
        if (n_v == finish)
            return from;
        for (auto e : v[n_v])
        {
            static int next_v, next_road;
            next_v = e.first, next_road = road + e.second;
            if (next_v == n_v)
                continue;
            if (inf[next_v] < next_road)
                continue;
            if (inf[next_v] != 1e9)
                que.erase({inf[next_v], next_v});
            inf[next_v] = next_road;
            from[next_v] = n_v;
            que.insert({next_road, next_v});
        }
    }
    return from;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, f;
    cin >> n >> s >> f;
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            static int s;
            cin >> s;
            if (s != -1 && s != 0)
                v[i].push_back({j, s});
        }
    }
    auto roads = deijkstra(v, s - 1, f - 1);
    int node = roads[f - 1];
    if (node != -1)
    {
        list<int> answer{f};
        while (node != -1)
        {
            answer.emplace_front(node + 1);
            if (node == s - 1)
                break;
            node = roads[node];
        }
        for (auto x : answer)
        {
            cout << x << " ";
        }
    }
    else cout << "-1";
    return 0;
}