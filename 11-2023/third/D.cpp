#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll deijkstra(vector<vector<tuple<int, int, int>>> &v, int start, int finish)
{
    vector<bool> used(v.size(), 0);
    vector<ll> inf(v.size(), 1e16);
    set<pair<ll, int>> que;
    que.insert(make_pair(0, start));
    while (!que.empty())
    {
        auto [time, n_v] = *que.begin();
        que.erase(que.begin());
        if (used[n_v])
            continue;
        used[n_v] = 1;
        if (inf[n_v] < time)
            continue;
        if (n_v == finish)
            return time;
        for (auto e : v[n_v])
        {
            auto [next_v, start_t, finish_t] = e;
            if (next_v == n_v)
                continue;
            if (time > start_t)
                continue;
            if (inf[next_v] < finish_t)
                continue;
            if (inf[next_v] != 1e9)
                que.erase({inf[next_v], next_v});
            inf[next_v] = finish_t;
            que.insert({finish_t, next_v});
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, f, k;
    cin >> n >> s >> f >> k;
    vector<vector<tuple<int, int, int>>> v(n, vector<tuple<int, int, int>>(0));
    for (int i = 0; i < k; ++i)
    {
        static int a, b, start, finish;
        cin >> a >> start >> b >> finish;
        v[a - 1].push_back({b - 1, start, finish});
    }
    cout << deijkstra(v, s - 1, f - 1);

    return 0;
}