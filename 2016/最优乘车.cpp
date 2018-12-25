#include<iostream>
#include<cstring>
#include<cstring>
#include<queue>
using namespace std;

const int INF=0x7ffff;
int w[502][502];
int v[502];
int t[502];
int n,e;
queue<int> q;

void Dijkstra()
{
	v[1]=1;
	int p;
	for(int z=2;z<=n;z++)
	{
		int MAX=9999999;
		for(int i=1;i<=n;i++)
			if(!v[i]&&w[1][i]!=0&&w[1][i]<MAX)
			{
				MAX=w[1][i];
				p=i;
			}
		v[p]=1;
		
		for(int i=1;i<=n;i++)
			if(!v[i]&&w[p][i]!=0)
				if(w[1][i]>w[1][p]+w[p][i]||w[1][i]==0)
				w[1][i]=w[1][p]+w[p][i];
	}
}

int main()
{
	cin>>e>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		w[i][j]=0;
	for(int z=1;z<=e;z++)
	{
		memset(t,0,sizeof(t));
		int j=0;
		while(!feof(stdin))
		{
			j++;
			cin>>t[j];
		}
		for(int i=1;i<=j-1;i++)
			for(int k=i+1;k<=j;k++)
			w[t[i]][t[k]]=1;
	}	
	memset(v,0,sizeof(v));
	Dijkstra();
	if(w[1][n]==0)
	cout<<"No";
	else 
	cout<<w[1][n]-1;
	return 0;
}