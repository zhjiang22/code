/*
可以这很强势
一遍写完调试了两分钟过了样例直接AC秒杀~
和P1026很像	都是可以位运算处理然后转换SPFA
当然bfs+hash也是可以的
题目的确有点繁琐(当初看到这个逃了好几次)
但是静下心来仔细看就好了
check函数和get函数很精妙
位运算又进一步加强了
这种题目还是要自己多写写好
详细看P1026的题解叭~~~
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=(1<<16)-1;
const int MAXM=102;
const int INF=(1<<30)-1;
int B1[MAXM],B2[MAXM];
int F1[MAXM],F2[MAXM];
bool in[MAXN];
queue<int> q;
int t[MAXM];
int d[MAXN];
int n,m;
int s;

void init()
{
	string a,b;
	cin>>n>>m;
	s=(1<<n)-1;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i]>>a>>b;
		for(int j=0;j<n;j++)
			if(a[j]=='+')
				B1[i]|=(1<<j);
			else	if(a[j]=='-')
				B2[i]|=(1<<j);
		for(int j=0;j<n;j++)
			if(b[j]=='-')
				F1[i]|=(1<<j);
			else	if(b[j]=='+')
				F2[i]|=(1<<j);
	}
	for(int i=0;i<MAXN;i++)
		d[i]=INF;
}

bool check(int x,int k)
{
	for(int i=0;i<n;i++)
		if((1<<i)&B1[k]&&(!((1<<i)&x)))
			return 0;
	for(int i=0;i<n;i++)
		if((1<<i)&B2[k]&&(1<<i)&x)
			return 0;
	return 1;
}

int get(int x,int k)
{
	x&=(~F1[k]);
	x|=F2[k];
	return x;
}

void SPFA()
{
	d[s]=0;	q.push(s);	in[s]=1;
	while(!q.empty())
	{
		int u=q.front();	q.pop();
		in[u]=0;
		for(int i=1;i<=m;i++)
		{
			if(!check(u,i))
				continue;
			int v=get(u,i);
			if(d[v]>d[u]+t[i])
			{
				d[v]=d[u]+t[i];
				if(!in[v])
				{
					q.push(v);
					in[v]=1;
				}
			}
		}
	}
	if(d[0]==INF)
		cout<<0<<endl;
	else
		cout<<d[0]<<endl;
}

int main()
{
	init();
	SPFA();
	return 0;
}
     