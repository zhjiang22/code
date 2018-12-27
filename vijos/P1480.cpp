/*
这题有毒不要靠近
现在的人啊
来考验我的耐心？
OTZ我就一个弱弱为啥浪费我一天的时间
我给满分都是爸爸的爱
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=166000;
const int INF=0x7fffff;
int p[260];
int k,l;
int cnt;
string a;

void init()
{
	cin>>a;
	l=a.length();
	for(int i=0;i<=256;i++)
		p[i]=i*i;
	while(p[k]<=l)
		k++;
	k--;
}

void out(int l,int r)
{
	char q[260][260];
	int x=sqrt(r-l);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=x;j++)
			q[i][j]=a[l++];
	for(int j=1;j<=x;j++)
		for(int i=1;i<=x;i++)
			printf("%c",q[i][j]);
}

int main()
{
	init();
	int o=l;
	int cur=0;
	for(int i=k;i>=1;i--)
	{
		while(o>=p[i])
		{
			out(cur,cur+p[i]);
			cur+=p[i];
			o-=p[i];
		}
	}
		
	//getans();
	//cout<<l<<endl;
	//for(int i=cnt;i>=1;i--)
		//cout<<ans[i]<<" ";
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN=66000;
const int INF=0x7fffff;
int f[MAXN];
int pre[MAXN];
int ans[MAXN];
int p[500];
int k,l;
int cnt;
string a;

void init()
{
	cin>>a;
	l=a.length();
	for(int i=0;i<=256;i++)
		p[i]=i*i;
	while(p[k]<=l)
		k++;
	k--;
	for(int i=1;i<=l;i++)
		f[i]=INF;
}

void out(int l,int r)
{
	char q[260][260];
	int x=sqrt(r-l);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=x;j++)
			q[i][j]=a[l++];
	for(int j=1;j<=x;j++)
		for(int i=1;i<=x;i++)
			cout<<q[i][j];
}

void getans()
{
	int cur=0;
	for(int i=cnt;i>=1;i--)
	{
		out(cur,cur+ans[i]);
		cur+=ans[i];
	}
}

int main()
{
	init();
	f[0]=0;
	for(int i=k;i>=1;i--)
		for(int j=p[i];j<=l;j++)
		{
			if(f[j-p[i]]+1<f[j])
			{
				f[j]=f[j-p[i]]+1;
				pre[j]=i;
			}
		}
		int s=l;
		while(s>0)
		{
			ans[++cnt]=p[pre[s]];
			s-=p[pre[s]];
		}
	getans();
	return 0;
}*/