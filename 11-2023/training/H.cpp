#include <iostream>

using namespace std;

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    int _maxB = (b + n - 1) / n;
    if (a > _maxB){
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}