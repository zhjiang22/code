#include <bits/stdc++.h>
using namespace std;

int h, s;
int f[25];

int dfs(int cur) {
    if(cur <= s)    return f[cur] = 1;
    if(f[cur])  return f[cur];
    for(int i = 1; i <= s; i++)
        f[cur] += dfs(cur - i);
    return f[cur];
}

int main() {
    cin>>h>>s;
    printf("%d\n",dfs(h));
	return 0;
}
