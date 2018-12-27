#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int MAXN=65;
int a[MAXN];
int v[MAXN];
int maxa,suma;
int cnt,len;
int n;

inline bool cmp(const int& a,const int& b)
{
	return a>b;
}

void init()
{
    memset(v,0,sizeof(v));
    maxa=suma=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
        maxa=max(maxa,a[i]);
        suma+=a[i];
    }
    sort(a+1,a+n+1,cmp);
}

bool dfs(int cur,int done,int last)
{
	if(cur>cnt)
		return 1;
	if(done==len)
		return dfs(cur+1,0,1);
	/*if(done>len)
		return 0;*/
	int fail=0;
	for(int i=last;i<=n;i++)
	{
		if(done+a[i]<=len&&!v[i]&&fail!=a[i])
		{
			v[i]=1;
			if(dfs(cur,done+a[i],i+1))
				return 1;
			fail=a[i];
			v[i]=0;
			if(!done)//important
				return 0;
			//对于当前一根完全空的想要拼接的木棍，如果第一根树枝都无法满足，后面的空木棍可用的树枝更少，必然更不可行
			//那这第一根树枝肯定无法在后续的拼接中使用，则必然是无解的情况，直接返回
			//剪枝效果极好
		}
	}
	return 0;
}

void work()
{
    for(len=maxa;len<=suma;len++)
    	if(!(suma%len))
    	{
    		cnt=suma/len;
    		if(dfs(1,0,1))
    		{
    			printf("%d\n",len);
    			break;
    		}
    	}
}

int main()
{
	while(scanf("%d",&n)&&n)
	{
		init();
		work();
	}
	return 0;
}