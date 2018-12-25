#include<iostream>
const int MAXN=32768;
using namespace std;

int tree[MAXN];

int creat(int _tree[],int _node[],int len)
{
	int i,MAX=1;
	_tree[1]=_node[1];
	int level=1;
	for(int i=2;i<=len;i++)
	{
		level=1;
		while(_tree[level]!=0)
		{
			if(_node[i]<_tree[level])
			level*=2;
			else 
			level=2*level+1;
			MAX=max(MAX,level);
		}
		_tree[level]=_node[i];
	}
	return MAX;
}

int main()
{
	freopen("")
	int n,num;
	cin>>n;
	int node[n+1];
	for(int i=1;i<=n;i++)
	cin>>node[i];
	num=creat(tree,node,n);
	for(int i=1;i<=num;i++)
	cout<<tree[i]<<" ";
	cout<<endl;
	return 0;
}