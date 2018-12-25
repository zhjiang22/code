#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
	int l,r,sum;
}t[500005];
int a[100003];
int n,m;
int ans;

void make(int x,int y,int num)
{
	t[num].l=x;
	t[num].r=y;
	if(x==y)
		t[num].sum=a[y];
	else
	{
		make(x,(x+y)/2,2*num);
		make((x+y)/2+1,y,2*num+1);
		t[num].sum=t[2*num].sum+t[2*num+1].sum;
	}
}

void add(int cur,int k,int q,int num)
{
	t[num].sum+=q*(k-cur+1);
	if(t[num].l==cur&&t[num].r==cur)
		return;
	if(cur>((t[num].l+t[num].r)/2))
		add(cur,q,k,2*num+1);
	else
		add(cur,k,q,2*num);
}

void query(int x,int y,int num)
{
	if(x<=t[num].l&&y>=t[num].r)
		ans+=t[num].sum;
	else
	{
		int p=(t[num].l+t[num].r)/2;
		if(x>p)
			query(x,y,2*num+1);
		else if(y<=p)
			query(x,y,2*num);
		else
		{
			query(x,y,2*num+1);
			query(x,y,2*num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	make(1,n,1);
	cin>>m;
	int t,x,q,p;
	while(m--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>q>>p>>x;
				add(q,p,x,1);
		}
		else if(t==2)
		{
			cin>>q>>p;
			ans=0;
			query(q,p,1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
     