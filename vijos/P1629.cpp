/*
容斥原理~？
害怕不太懂啊
但是窝是直接把他乱搞的
具体就不说了看代码应该很容易看懂
要学正解百度好像博客蛮多的~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

const int MAXN=17;
bool can[130000000];
int d[MAXN];
int a,b;
int n,l;
int ans;

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		for(int j=1;j<=3;j++)
			if(d[i]%2==0)
				d[i]/=2;
			else
				break;
	}
	scanf("%d%d",&a,&b);
	a=(a+7)/8;	b/=8;
	sort(d+1,d+n+1);
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		int cur=a/d[i];
		if(cur%d[i]!=0)
			cur++;
        for(int j=cur;j*d[i]<=b;j++)
       		can[j*d[i]]=1;
	}
	for(int i=a;i<=b;i++)
    	if(!can[i])ans++;
    cout<<ans<<endl;
	return 0;
}
     