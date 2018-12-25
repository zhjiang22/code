#include<iostream>
#include<algorithm>
using namespace std;

int map[100][100];
int d[100];
int visit[100]={0};

int n,m;
const int INF=9999999;

void Dijkstra(int s)
{
	int Min,p;
	for(int i=1;i<=n;i++)
		d[i]=map[s][i];
	visit[s]=1;
	d[s]=0;
	for(int i=1;i<n;i++)
	{
		Min=INF;
		for(int j=1;j<=n;j++)
			if(!visit[j]&&Min>d[j])
			{
				p=j;
				Min=d[j];
			}
		visit[p]=1;
		for(int j=1;j<=n;j++)
			if(!visit[j]&&Min+map[p][j]<d[j])
				d[j]=Min+map[p][j];
	}
	
	for(int i=1;i<=n;i++)
    	cout<<d[i]<<' ';
  	cout<<endl;
}

int main()
{
	
	cin>>n;
  	int i,j;
  	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	    {
	      cin>>map[i][j];
	      if(map[i][j]==0)
	        map[i][j]=INF;
	    }
	Dijkstra(1);
	return 0;
}