#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int MAXN=200005;
LL Left[MAXN],Right[MAXN];
int c[MAXN];
int a[MAXN];
int n;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
}

inline int Low_abit(const int& x)
{
	return x&(-x);
}

LL ask(int x)
{
	if(x==0)
		return 0; 
	LL sum=0;
	for(;x;x-=Low_abit(x))
		sum+=c[x];
	return sum;
}

void add(int x)
{
	for(;x<=n;x+=Low_abit(x))
		++c[x];
}

void work()
{
	for(int i=1;i<=n;i++)
	{
		Left[i]=ask(a[i]-1);
		add(a[i]);
	}
	memset(c,0,sizeof(c));
	for(int i=n;i>=1;i--)
	{
		Right[i]=ask(a[i]-1);
		add(a[i]);
	}
	LL ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		ans1+=(i-Left[i]-1)*(n-i-Right[i]);
		ans2+=Left[i]*Right[i];
	}
	cout<<ans1<<" "<<ans2<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
     