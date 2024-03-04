#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int id = -1;
    set<char> open{'(', '[', '{'};
    if (s.length() % 2)
    {
        cout << "no";
        return 0;
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (open.count(s[i]))
        {
            ++id;
            if (id != i)
                s[id] = s[i];
        }
        else
        {
            if (id == -1)
            {
                cout << "no";
                return 0;
            }
            if ((s[i] == ')' && s[id] == '(') ||
                (s[i] == '}' && s[id] == '{') ||
                (s[i] == ']' && s[id] == '['))
            {
                --id;
                continue;
            }
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}