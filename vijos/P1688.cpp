/*
微生物世界的等级观念很强，除了菌王外，每个细菌均有且只有一个直接的母体，菌王则没有母体。
这句话就是告诉我们	这个结构是个树结构
如果细菌a是细菌b的母体，细菌b是细菌c的母体，则细菌a就是细菌c的母体。
这就是告诉我们这个关系的传递性了
然后我们很容易想到树形DP
考虑到n不大最大才1000
不妨枚举一开始感染的节点作为根,然后进行树dp.
注意到病毒一定是向下传染的.
对于每个节点标记一个值,表示(感染这个节点后)感染这个节点引领的子树需要多久.
那么如何求出这个值?
设它为d[i],则我们要在第1单位时间传给某棵子树,在第2单位时间传给另一颗子树.....
于是,设它的子节点为j1,j2,...,jk,并且刚好是按照这个顺序传递的(即,先给j1,再给j2,j3...)
则d[i]=min(d[j1]+1,d[j2],d[j3]+3,.....,d[jk]+k);
注意根据排序不等式,想要这个结果最小,那么d[j]应该按照降序排列
所以我们对于每个节点递归dp所有的子树
先求出其子树的最小时间	递归边界是没有子树返回时间应该是0
然后我们将所有的这些子树时间放到一个数组中去
再快排个序
然后肯定就是合理分配时间了
就是上面的d[i]=min(d[j1]+1,d[j2],d[j3]+3,.....,d[jk]+k);
取出最小值即可
然后再递归返回以此类推
挺好写的
复杂度O(n^2logn).
树形dp长姿势惹
窝好弱啊Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=1005;
const int INF=(1<<30)-1;
vector<int> g[MAXN];
vector<int> a;
bool v[MAXN];
int n;
int ans=INF;

void inline Add_Edge(int from,int to)
{
	g[from].push_back(to);
	g[to].push_back(from);
}

void init()
{
	int to;
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>to,
		Add_Edge(i,to);
}

void out()
{
	cout<<ans+1<<endl;
	int d=a.size();
	for(int i=0;i<d;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int dfs(int fa)
{
	v[fa]=true;
	int s[MAXN];
	int tot=0;
	int d=g[fa].size();
	for(int i=0;i<d;i++)
	{
		int k=g[fa][i];
		if(!v[k])
			s[++tot]=dfs(k);
	}
	if(tot==0)
	{
		v[fa]=0;
		return 0;
	}
	sort(s+1,s+tot+1);
	int cost=0;
	for(int i=1;i<=tot;i++)
		cost=max(cost,s[i]+tot-i+1);
	v[fa]=0;
	return cost;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		int w=dfs(i);
		if(w<ans)
			ans=w,a.clear(),a.push_back(i);
		else	if(w==ans)
			a.push_back(i);
	}
	out();
	return 0;
}
