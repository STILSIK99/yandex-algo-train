#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Node
{
    int v, speed;
    ld time;
    vector<int> path;
    Node(int _v, int _speed, ld _time) : v(_v), speed(_speed), time(_time)
    {
        path.reserve(2000);
        path.push_back(v);
    }
    Node(int _v, pair<int, int> &p) : v(_v), speed(0), time(0)
    {
        setSpeed(p);
        path.reserve(2000);
        path.push_back(v);
    }
    Node()
    {
        path.reserve(2000);
        path.push_back(v);
    }
    void setSpeed(pair<int, int> &p)
    {
        speed = p.second;
        time += p.first;
    }
    bool operator<(const Node &a) const
    {
        if (a.time == this->time)
            return this->speed < a.speed;
        return this->time < a.time;
    }
};

void print(vector<int> &a, int add)
{
    for (auto x : a)
        cout << x + add << " ";
    cout << "\n";
}

void bfs(vector<map<int, int>> &matrix, vector<int> & distances){
    int start = 0;
    distances[0] = 0;
    vector<bool> used(matrix.size(), 0);
    queue<int> q;
    q.emplace(start);
    used[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto e : matrix[node]){
            if (used[e.first]) continue;
            distances[e.first] = distances[node] + e.second;
            q.emplace(e.first);
            used[e.first] = 1;
        }
    }
}


Node deijkstra(vector<map<int, int>> &v, int start, int finish, vector<pair<int, int>> &yam)
{
    set<Node> que;
    que.insert(Node(start, yam[start]));
    while (!que.empty())
    {
        auto node = *que.begin();
        que.erase(que.begin());
        if (node.v == finish)
        {
            node.path.push_back(finish);
            return node;
        }
        for (auto e : v[node.v])
        {
            static Node next_n;
            auto [next_v, next_road] = e;
            if (next_v == node.v)
                continue;
            next_n = node;
            next_n.v = next_v;
            next_n.time += next_road / 1. / next_n.speed;
            que.insert(next_n);

            if (node.speed < yam[node.v].second)
            {
                next_n.speed = yam[node.v].second;
                next_n.time = node.time + yam[node.v].first + next_road / 1. / next_n.speed;
                next_n.path.push_back(node.v);
                que.insert(next_n);
            }
        }
    }
    return Node();
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n, k;
    cin >> n;
    vector<pair<int, int>> yam(n);
    vector<map<int, int>> lens(n, map<int, int>());
    vector<int> allLens(n, 0);
    for (int i = 0; i < n; ++i)
    {
        static int t, s;
        cin >> t >> s;
        yam[i] = {t, s};
    }
    for (int i = 0; i < n - 1; ++i)
    {
        static int a, b, l;
        cin >> a >> b >> l;
        lens[a - 1][b - 1] = l;
        lens[b - 1][a - 1] = l;
    }
    bfs(lens, allLens);
    print(allLens, 0);
    ld result = 0;
    vector<int> road;
    for (int i = 1; i < n; ++i)
    {
        static Node node;
        node = deijkstra(lens, i, 0, yam);
        if (node.time > result)
        {
            result = node.time;
            road = node.path;
        }
    }
    cout << fixed << setprecision(10) << result << "\n";
    print(road, 1);
    return 0;
}