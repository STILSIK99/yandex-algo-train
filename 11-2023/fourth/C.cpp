#include <bits/stdc++.h>

using namespace std;

void print(vector<bool> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
} 

void recur(int cur, int sum, vector<bool> & groups, vector<vector<short>> & matrix, int &res, vector<bool> &answer){
    if (cur == groups.size()) {
        // cout << "---------------------\n";
        // print(groups);
        // cout << sum << "\n";
        if (sum > res) {
            for(int i = 0; i < groups.size(); ++i)
                answer[i] = groups[i];
            res = sum;
        }
        return ;
    }
    int first = 0, second = 0;
    for(int i = 0; i < cur; ++i)
        if (groups[i]) first += matrix[cur][i];
        else second += matrix[cur][i];
    groups[cur] = 0;
    recur(cur + 1, sum + first, groups, matrix, res, answer);
    groups[cur] = 1;
    recur(cur + 1, sum + second, groups, matrix, res, answer);
}

int main(){
    int n;
    cin >> n;
    vector<vector<short>> matrix(n, vector<short>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }
    vector<bool> groups(n, 0), answer(n, 0);
    int res = 0;
    recur(0, 0, groups, matrix, res, answer);
    cout << res << "\n";
    for(auto x : answer){
        cout << int(x) + 1 << " ";
    }

    return 0;
}