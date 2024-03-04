#include <bits/stdc++.h>
using namespace std;

void task(){


    
    // cout << "task\n";
}

int main(){
    int t = 10;
    // cin >> t;
    int last = 0;
    for(int i = 1; i < t; ++i){
        static int s;
        s = i * i * i;
        cout << s << " " << s - last << "\n";
        last = s;
    }

    return 0;
}