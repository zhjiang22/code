#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct powe
{
	int l,r;
}q[50002];
int n;

int cmp(powe x,powe y)
{
	return x.l<y.l;
}


int main()
{
	freopen("D:\\in.txt","r",stdin);
	freopen("D:\\out.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>q[i].l>>q[i].r;
	sort(q+1,q+n+1,cmp);
	int R=q[1].r;
	for(int i=2;i<=n;i++)
	{
		if(R>=q[i].l)
			R=max(R,q[i].r);
		else 
		{
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<q[1].l<<" "<<R<<endl;
	return 0;
}