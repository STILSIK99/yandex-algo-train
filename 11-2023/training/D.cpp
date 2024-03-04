#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> counter(27, 0);
    for(auto c : a)
        ++counter[c - 'a'];
    for(auto c : b)
        --counter[c - 'a'];
    for(auto el : counter){
        if (el != 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}