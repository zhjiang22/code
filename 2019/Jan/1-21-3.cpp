// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
int l, ok;
char s[1000];
int main()
{
    cin >> s;
    l = strlen(s);
    for (int i = 0; i < l - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            s[i] = -1;
            break;
        }
    }
    for (int i = 0; i < l; i++)
        if (s[i] == -1)
            ok = 1;
    if (ok)
        for (int i = 0; i < l; ++i)
        {
            if (s[i] != -1)
            {
                cout << s[i];
            }
        }
    else
        for (int i = 0; i < l - 1; i++)
            cout << s[i];
}