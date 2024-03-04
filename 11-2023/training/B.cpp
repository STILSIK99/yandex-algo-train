#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    return (a > b) ? gcd(a % b, b) : gcd(b % a, a);
}


int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int nok = b * d / gcd(b, d);
    int sum = a * (nok / b) + c * (nok / d);
    int div = gcd(nok, sum);
    cout << sum / div << " " << nok / div;
    return 0;
}