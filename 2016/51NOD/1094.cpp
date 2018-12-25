#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAXN=10005;
const int INF=(1<<30)-1;
int a[MAXN];
long long s[MAXN];
map<long long,int>Map;
int n,k;
int l,r;

void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		s[i]=s[i-1]+a[i];
}

int main()
{
	init();
	int l=INF;
	for(int i=0;i<=n;i++)
	{
		if(Map[s[i]-k]&&Map[s[i]-k]<l)
		{
			l=Map[s[i]-k];
			r=i;
		}
		if(!Map[s[i]])
			Map[s[i]]=i+1;
	}
	if(l==INF)
		cout<<"No Solution"<<endl;
	else
		cout<<l<<" "<<r<<endl;
	return 0;
}
     