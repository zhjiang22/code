#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long n,m;

void init()
{
	cin>>n>>m;
}

long long minv;
long long maxv;

void get_min()
{
	if(m>(n/2))
		minv=0;
	else
		minv=n-m*2;
}

void get_max()
{
	if(m==0)
	{
		maxv=n;
		return;
	}
	long long cur=0;
	while(1)
	{
		long long now=(cur*(cur-1))/2;
		if(m>=now)
			cur++;
		else
			break;
	}
	if(m==(cur-1)*(cur-2)/2)
		maxv=n-(cur-1);
	else
		maxv=n-cur;
}

void work()
{
	get_min();
	get_max();
	cout<<minv<<" "<<maxv<<endl;
}

int main()
{
	init();
	work();
	return 0;
}


while(!q.empty())
{
	//xxxxx
	if(d[v]>d[u]+w)
	{
		d[v]=d[u]+w;
		if(!inq[v])
		{
			inq[v]=1;
			q.push(v);
		}
	}
}