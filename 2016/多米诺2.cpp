#include <iostream>

#include <cstring>

#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 55;

int n, m, k, ans;

int a[N][N];

int f[N * N][N * N];

int b[N * N];

bool vis[N * N];

int fx[4] = {-1, 0, 1, 0};

int fy[4] = {0, 1, 0, -1};



void Build()

{

int num, nnum, x, y;

for(int i = 1; i <= n; ++i)

for(int j = 1; j <= m ; ++j)

{

if(a[i][j]) continue;

num = (i - 1) * m + j;

for(int p = 0; p < 4; ++p)

{

x = i + fx[p];

y = j + fy[p];

if(x < 1 || y < 1 || x > n || y > m || a[x][y]) continue;

nnum = (x - 1) * m + y;

f[num][nnum] = 1;

}

}

}



void Init()

{

int x, y;

scanf("%d %d %d", &n, &m, &k);

for(int i = 1; i <= k; ++i)

{

scanf("%d %d", &x, &y);

a[x][y] = 1;

}

Build();

}



bool find(int t)

{

for(int i = 1; i <= n * m ; ++i)

{

if(f[t][i] && !vis[i])

{

vis[i] = 1;

if(!b[i] || find(b[i]))

{

b[i] = t;

return true;

}

}

}

return false;

}



void Hungary()

{

for(int i = 1; i <= n * m ; ++i)

{

memset(vis, 0, sizeof vis);

if(find(i)) ans++;

}

ans /= 2;

}



int main()

{

Init();

Hungary();

cout << ans;

return 0;

}

