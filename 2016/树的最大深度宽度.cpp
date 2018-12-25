#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
	int lc,rc;
}tree[1000];
int n;
int d[100]={0},h[100]={0};

void dfs(int x)
{
	if(tree[x].lc)
	{
		h[tree[x].lc]=h[x]+1;
		d[h[tree[x].lc]]++;
		dfs(tree[x].lc);
	}
	if(tree[x].rc)
	{
		h[tree[x].rc]=h[x]+1;
		d[h[tree[x].rc]]++;
		dfs(tree[x].rc);
	}
}

int main()
{
	memset(tree,0,sizeof(tree));
	d[1]=1;	h[1]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>tree[i].lc>>tree[i].rc;
	dfs(1);
	int x=-11,y=-11;
	for(int i=1;i<=n;i++)
	{
		x=max(x,h[i]);
		y=max(y,d[i]);
	}
	cout<<y<<" "<<x<<endl;
	return 0;
} 