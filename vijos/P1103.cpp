#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

#define maxn 500000+10
int fa[maxn];
int n, q;
int ans ;

int solve(int a,int b)
{
    int i=b;
       for(int i = b ; i >= a ; )//从右向左扫描
	{
	    if( fa[i] == i )
        {
            ans--;//切了一个
            fa[i] = a - 1;//标记此水果已切，同时用fa[i]来方便下次快速转换位置
                          //即直接免去查找此区间，跳到区间的一个左端点
            i--;
        }
        else//已经扫过
            i = fa[i];//直接跳到第一次切这个水果的左区间端点向右一个位置（因为已经扫过）
    }
}

int main( )
{
  scanf("%d %d",&n,&q);
     for(int i = 0 ; i <= n ; ++i)
       fa[i] = i;
    ans = n+1;
    for(int i = 1 ; i <= q ; i++)
    {
        int a, b;
         scanf("%d %d",&a,&b);
        if( a > b )
            swap( b, a );
        solve( a, b );
    }
        printf("%d\n",ans);
}