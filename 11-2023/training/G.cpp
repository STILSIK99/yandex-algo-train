#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<short, short>>> getModArr(vector<vector<short>> &arr, int n, int m)
{
    // first - vertical, second - horizontal
    vector<vector<pair<short, short>>> modified(n, vector<pair<short, short>>(m, make_pair(0, 0)));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (arr[i][j] == 0)
                continue;
            modified[i][j] = make_pair(1, 1);
            if (i > 0)
                modified[i][j].first += modified[i - 1][j].first;
            if (i > 0)
                modified[i][j].second += modified[i][j - 1].second;
        }
    }
    return modified;
}

int getMaxSide(vector<vector<pair<short, short>>> &field, int x, int y)
{
    auto p = field[x][y];
    int maxSide = min(p.first, p.second);
    if (maxSide == 1)
        return 1;
    for (int step = 1; step < maxSide; ++step)
    {
        auto nextP = field[x - step][y - step];
        static int nextMaxSide;
        nextMaxSide = min(nextP.first, nextP.second);
        maxSide = min(maxSide, nextMaxSide + step);
        if (nextMaxSide == 1)
            break;
    }
    return maxSide;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<short>> field(n, vector<short>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> field[i][j];
    }
    auto _arr = getModArr(field, n, m);
    int result = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {   
            pair<short, short> *p = &_arr[i][j];
            if (max(p->first, p->second) > result){
                result = max(result, getMaxSide(_arr, i, j));
            }
        }
    }
    cout << result;
    return 0;
}