#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll deijkstra(vector<vector<pair<int, int>>> &v, int start, int finish)
{
    vector<bool> used(v.size(), 0);
    vector<ll> inf(v.size(), 1e16);
    set<pair<ll, int>> que;
    que.insert(make_pair(0, start));
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
            return road;
        for (auto e : v[n_v])
        {
            static ll next_v, next_road;
            next_v = e.first, next_road = road + e.second;
            if (next_v == n_v)
                continue;
            if (inf[next_v] < next_road)
                continue;
            if (inf[next_v] != 1e9)
                que.erase({inf[next_v], next_v});
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
    int n, k, s, f;
    cin >> n >> k;
    vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(0));
    for (int i = 0; i < k; ++i)
    {
        static int a, b, l;
        cin >> a >> b >> l;
        v[a - 1].push_back({b - 1, l});
        v[b - 1].push_back({a - 1, l});
    }
    cin >> s >> f;
    cout << deijkstra(v, s - 1, f - 1);

    return 0;
}