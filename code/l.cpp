#include <bits/stdc++.h>
using namespace std;

const int MAXN=4e5+5;
char a[MAXN];
int p[30];
int pos[MAXN][30];
int L;
int n;

void init()
{
	gets(a);
	cin>>n;
	L = strlen(a);
	memset(p,-1,sizeof(p));
	memset(pos,-1,sizeof(pos));
	for(int i=L-1;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			if(p[j]!=-1)
				pos[i+1][j]=p[j];
		if(p[a[i]-'a']==-1)	p[a[i]-'a']=i+1;
		else	p[a[i]-'a']=min(p[a[i]-'a'],i+1);
	}
	for(int i=0;i<26;i++)
		pos[0][i]=p[i];
}

char ch[MAXN];

void work()
{
	string c;
	char x;
	int cur = 0;
	stack<int> s;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=="push")
		{
			cin>>x;
			s.push(cur);
			int& k=pos[cur][x-'a'];
			if(k==-1)
			{
				printf("NO\n");
				cur = L+10;
			}
			else
			{
				printf("YES\n");
				cur = k;
			}
			// cout<<cur<<endl;
		}
		else
		{
			cur=s.top();	s.pop();
			// cout<<"pop "<<cur<<endl;
			if(cur==L+10)
				printf("NO\n");
			else
				printf("YES\n");	
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	work();
	return 0;
}