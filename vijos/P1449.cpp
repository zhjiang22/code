#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[3];

void check (int& ans) {
    for (int a = 0; a < 3; a++) 
        for (int b = 0; b < 3; b++) 
        {
            if (a == b) continue;
            int ok = true;
            for (int i = 1; i < n; i++) 
                if ((s[a][i] - s[a][i-1] + 26) % 26 != (s[b][i] - s[b][i-1] + 26) % 26) 
                    { ok = false; break;}
            if (ok) 
            {
                ans = ((a+b)*2)%3;
                reverse (s[ans].begin(), s[ans].end());
                int v = (s[a][0] - 'a' + 1 + s[b][0] - 'a' + 1) % 26;
                int l = ((s[ans][0] - 'a' + 1) * 2) % 26;
                if (v == l) 
                    return;
                else 
                { 
                    reverse (s[ans].begin(), s[ans].end());
                     continue;
                 }
        }
    }
}

int main ()
{
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    int ans;
    check (ans);
    cout << s[ans];
    return 0;
}