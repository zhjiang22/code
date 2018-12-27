/*
表示很久以前就看到了这道题
一直不敢做啊(Orz原因是因为题目太长看不懂)
关键是vijos上的那个∑公式看不清 所以给了我逃避的理由2333
现在终于下定决心好好做一下
其实发现也不难的(虽然自己一开始没想到这种做法(害羞~))
这题好像有点类似拓扑排序的样子
涉及到了入度和出度酱紫~
我们从输入点开始传递C值，如果C为正则可以传递。
注意到只有当一个结点的所有入度全部传递完成之后这个结点才可以进行传递，而且结点传递之前需要检查C的正负。
用in[],out[]分别记录入度和出度，用一个队列维护入度已经求完的结点，边我们可以用邻接向量存
考虑它所有出度的终点，考虑完成后出队，对于考虑结点而言，对所有出度的in减1，同时判断是否可以入队。
这样其实就很简单了，输出最后网络输出层的时候，我们可以明确当且仅当out[i]=0时(即出度为0)
i点才是最后网络输出层其中的一个点
然后我们就判断所有的最后网络输出层的点有无正值
如果有的话说明有兴奋状态，就输出
如果一个都没有就输出NULL
题目还是很简单的没有什么难点，主要是要看懂题目意思
唉说到底还是考语文啊(友尽><)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int Maxn=205;
struct Edge
{
	int from,to,w;
	Edge(int from,int to,int w):from(from),to(to),w(w){} 
};
vector<Edge> edges;
vector<int> g[Maxn];
queue<int> q;
int in[Maxn],out[Maxn];
int c[Maxn],u[Maxn];
int n,m;

void addEdge(int from,int to,int w)
{
	edges.push_back(Edge(from,to,w));
	int d=edges.size();
	g[from].push_back(d-1);
	in[to]++,out[from]++;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>u[i];
		if(c[i]>0)
			q.push(i);
		if(c[i]==0)
			c[i]-=u[i];
	}
	int x,y,v;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>v;
		addEdge(x,y,v);
	}

	while(!q.empty())
	{
		int k=q.front();	q.pop();
		if(c[k]>0)
		{
			for(int i=0;i<g[k].size();i++)
			{
				int v=edges[g[k][i]].to;
				int w=edges[g[k][i]].w;
				c[v]+=w*c[k];
				if(!(--in[v]))
					q.push(v);
			}
		}
	}
	bool f=1;
	for(int i=1;i<=n;i++)
		if(!out[i]&&c[i]>0)
		{
			cout<<i<<" "<<c[i]<<endl;
			f=0;
		}
	if(f)
		cout<<"NULL"<<endl;
	return 0;
}
     