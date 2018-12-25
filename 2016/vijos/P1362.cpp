#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define M 1000000000
using namespace std;
const int MAXN = 310;

int n, mlong, d[MAXN][MAXN];
bool use[MAXN][MAXN];

void Floyd(){
    for(int k=1; k<=n; k++)
      for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
          if(k != i && k!= j && i != j)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);//maybe there is no way, so use min
}

int main()
{
    int x, y, l, lim, ans = M;
    scanf("%d%d", &n, &lim);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        d[i][j] = M;
    for(int i=1; i<n; i++){
      scanf("%d%d%d", &x, &y, &l);
      d[x][y] = d[y][x] = l;
    }
    for(int i=1; i<=n; i++)
      d[i][i] = 0;
    Floyd();    
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        mlong = max(mlong, d[i][j]);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        if(d[i][j] == mlong && !use[i][j] && !use[j][i])
        {
          for(int k=1; k<=n; k++)
            if(d[i][k] + d[k][j] == mlong)
              for(int l=1; l<=n; l++)
                if(d[i][l] + d[l][j] == mlong && d[k][l] <= lim)
                  ans = min(ans, max(min(d[k][i], d[l][i]), min(d[j][k], d[j][l])));
          use[i][j] = true;
        }
    printf("%d", ans);           
    return 0;
}