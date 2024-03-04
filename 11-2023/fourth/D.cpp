#include <bits/stdc++.h>
typedef unsigned int ui;

using namespace std;

int fullRoad = 0;

long double deijkstra(vector<vector<short>> &v, int start, int finish)
{
    vector<bool> used(v.size(), 0);
    vector<long double> inf(v.size(), 1e9);
    set<pair<long double, int>> que;
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
        for (int i = 0; i < v.size(); ++i)
        {
            static short next_v, next_road;
            if (v[n_v][i] < 1)
                continue;
            next_v = i, next_road = road + v[n_v][i];
            if (next_v == n_v)
                continue;
            if (inf[next_v] < next_road)
                continue;
            if (inf[next_v] != 1e9)
                que.erase({next_road, next_v});
            inf[next_v] = next_road;
            que.insert({next_road, next_v});
        }
    }
    return -1;
}

int zhad(vector<vector<short>> &matrix)
{
    int result = 0;
    int start = 0;
    int n = matrix.size();
    vector<bool> used(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int road = 1e9;
        int next_v;
        for (int j = 1; j < n; ++j)
        {
            if (used[j] || matrix[start][j] == 0)
                continue;
            if (road > matrix[start][j])
            {
                road = matrix[start][j];
                next_v = j;
            }
        }
        if (next_v == start)
            return -1;
        result += road;
        used[next_v] = 1;
        start = next_v;
    }
    auto x = deijkstra(matrix, start, 0);
    if (x == -1)
        return -1;
    return result + x;
}

template <class T>
void print(vector<T> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}

int recur(ui road, int curLen, int pos,
          int &best, vector<vector<short>> &matrix,
          vector<short> &mins, vector<int> &path, vector<int> &sums)
{
    // cout << "-----------\n";
    // cout << curLen << "\n";
    // print(path);
    // cout << "-----------\n";
    if (road == fullRoad)
    {
        auto x = deijkstra(matrix, pos, 0);
        if (x == -1)
            return -1;
        if (curLen + x < best)
        {
            best = curLen + x;
            // cout << "----------------------\n";
            // cout << "Found\n";
            // print(sums);
            // cout << curLen + matrix[pos][0] << "\n";
            // print(path);
            // cout << "----------------------\n";
        }
        return curLen + x;
    }
    int result = -1;
    for (int i = 1; i < matrix.size(); ++i)
    {
        if (matrix[pos][i] == 0)
            continue;
        if (road & (1 << i))
            continue;
        if (best <= curLen + matrix[pos][i]) continue;
        road |= (1 << i);
        path.push_back(i);
        sums.push_back(matrix[pos][i]);
        auto x = recur(road, curLen + matrix[pos][i], i, best, matrix, mins, path, sums);
        path.pop_back();
        sums.pop_back();
        road ^= (1 << i);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    vector<vector<short>> matrix(n, vector<short>(n));
    vector<short> mins(n);
    for (int i = 0; i < n; ++i)
    {
        int _min_mean = 1e9;
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
            if (_min_mean > matrix[i][j])
                _min_mean = matrix[i][j];
        }
        mins[i] = _min_mean;
    }
    for (int i = 1; i < n; ++i)
    {
        fullRoad += 1 << i;
    }
    // cout << fullRoad << "\n";
    int best = zhad(matrix);
    vector<int> s1, s2;
    if (best == -1) {
        cout << -1;
        return 0;
    }
    int res = recur(0, 0, 0, best, matrix, mins, s1, s2);
    if (res == -1)
        cout << best;
    else
        cout << min(res, best);
    return 0;
}