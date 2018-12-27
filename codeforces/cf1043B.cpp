#include<bits/stdc++.h>
using namespace std;

const int MAXN=1005;
int d[MAXN];
int n;

void init()
{
	int x,lx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		d[i]=x-lx;	lx=x;
	}
}


void work()
{
	vector<int> v;	v.clear();
	for(int k=1;k<=n;k++)
	{
		bool ok=1;
		for(int i=k+1;i<=n;i++)
			if(d[i]!=d[i-k])
				ok=0;
		if(ok)
			v.push_back(k);
	}
	int l;
	cout<<(l=v.size())<<endl;
	for(int i=0;i<l;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
     