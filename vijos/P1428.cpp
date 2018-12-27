#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define LL long long
LL f[60][60];
struct node
{
	LL a,b,w;
}q[1002];
int n,s,b;

int main()
{
	LL ans=9999999;
	cin>>n>>s>>b;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		cin>>q[i].a>>q[i].b>>q[i].w;
	for(int i=1;i<=n;i++)
	{
		for(int j=s;j>=0;j--)
			for(int k=b;k>=0;k--)
				if(f[j][k])
				{
					LL w1=j+q[i].a;
					LL w2=k+q[i].b;
					if(w1>s)	w1=s;
					if(w2>b)	w2=b;
					LL v=f[j][k]+q[i].w;
					if(f[w1][w2]==0)
						f[w1][w2]=v;
					else
						f[w1][w2]=min(f[w1][w2],v);
				}
	}
	cout<<(f[s][b]-1)*2<<endl;//f[0][0]初始时为1，应减去，同时要买两片费用*2
	return 0;
}
     