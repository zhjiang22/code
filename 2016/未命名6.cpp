#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=102;

struct node
{
	long long number;
	double score;
};

node a[MAXN];

int cmp(node c,node d)
{
	return c.score>d.score;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i].number>>a[i].score;
	sort(a,a+n,cmp);
	cout<<a[k-1].number<<" "<<a[k-1].score;
	return 0;
}
