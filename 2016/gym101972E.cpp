#include<bits/stdc++.h>
using namespace std;

const int N=10010;
bool bk[N];
char s[10];

int main()
{
	//freopen("a.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			if(s[0]=='S') bk[i]=0;
			else bk[i]=1;
		}
		int now=k,ans=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s);
			if(s[0]=='W')
			{
				int x;
				scanf("%d",&x);
				if(x<=now && !bk[x]) ans++;
				now=max(now,x);
			}
			else	now=n;
		}
		printf("%d\n",ans);
	}
	return 0;
}