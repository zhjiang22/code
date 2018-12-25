#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int INF=0x7fff;
int t[100][100],v[100][100];
int d[100],ji[100];
int n,m;
queue<int> q;
bool inque[100];

void SPFA()
{
	d[1]=ji[1]=0;
	inque[1]=true;
	q.push(1);
	
	while(!q.empty())
	{				
		int x=q.front();
		q.pop();
		inque[x]=false;
		
		for(int i=1;i<=n;i++)
		{
			if(d[x]+t[x][i]<d[i])
			{
				d[i]=d[x]+t[x][i];
				ji[i]=ji[x]+v[x][i];
				if(!inque[i])
				{
					q.push(i);
					inque[i]=true;
				}			
			}
			if(d[x]+t[x][i]==d[i])
			ji[i]= max(ji[i],ji[x]+v[x][i]);
		}
	}
	cout<<d[n]<<" "<<ji[n];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		d[i]=INF;
	memset(v,0,sizeof(v));
	memset(inque,false,sizeof(inque));
	for(int i=1;i<=m;i++)
	{
		int x,y,t1,v1;
		cin>>x>>y>>t1>>v1;
		t[x][y]=t[y][x]=t1;
		v[x][y]=v[y][x]=v1;
	}
	SPFA();
	return 0;
}