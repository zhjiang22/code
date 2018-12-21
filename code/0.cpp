#include "bits/stdc++.h"
using namespace std;

const int N=100010;
int a[N],vis[N],in[N],nxt[N];
struct node{
	int d,id;
}num[N];
struct qnode{
	int x,nxt;
	bool operator < (const qnode & t) const{
		return t.nxt > nxt;
	}
};
priority_queue<qnode> q;


bool cmp_num(node x,node y)  
{
	return x.d<y.d;
}

int main()
{
	freopen("a.in","r",stdin);
	int T,n,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			num[i].d=a[i];num[i].id=i;
		}
		sort(num+1,num+1+n,cmp_num);
		int now=0; num[0].d=0;
		for(int i=1;i<=n;i++)
		{
			if(num[i].d!=num[i-1].d) now++;
			a[num[i].id]=now;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++) nxt[i]=n+1;
		for(int i=n;i>=1;i--)
		{
			if(vis[a[i]]) nxt[i]=vis[a[i]];
			vis[a[i]]=i;
		}
		while(!q.empty()) q.pop();
		memset(in,0,sizeof(in));
		int ql=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			// cout<<q.size()<<endl;
			if(in[a[i]]) 
			{
				qnode t;t.x=a[i],t.nxt=nxt[i];
				q.push(t);
				continue;
			}
			if(ql<k) 
			{
				qnode t;t.x=a[i],t.nxt=nxt[i];
				q.push(t);
				ql++;ans++;
				in[a[i]]=1;
			}
			else
			{
				qnode t=q.top();q.pop();
				in[t.x]=0;ql--;
				// printf("t.x  = %d\n",t.x);
				t.x=a[i],t.nxt=nxt[i];
				q.push(t);
				ql++;ans++;
				in[a[i]]=1;
			}
		}
		// cout<<q.size()<<endl;
		// return 0;
		printf("%d\n",ans);
	}
	return 0;
}