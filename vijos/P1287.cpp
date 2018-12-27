#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MAXN=105;
int f[MAXN];
string p;
vector<int> g[MAXN];
map<string,int> Hash;
int n,tot;

int main()
{
	scanf("%d",&n);
	int a,b;
	for(;n;n--)
	{
		cin>>a>>p>>b;
		int l=g[b].size();
		for(int i=1;i<=a;i++)
		{
			cin>>p;
			if(!Hash[p])
				Hash[p]=++tot;
			bool can=0;
			for(int i=0;i<l;i++)
			{
				if(g[b][i]==Hash[p])
					can=1;
				break;
			}
			if(!can)
			{
				g[b].push_back(Hash[p]);
				f[b]++;
				if(f[b-1]==b-1)
					cout<<b<<" "<<p<<endl;
			}
		}
	}
}
     