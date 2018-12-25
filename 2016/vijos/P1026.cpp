/*
数据是不是太弱了一点
不管是直接bfs+hash(用vector保存)还是二进制+SPFA都是0ms秒杀？
也是醉了
学习了~再一次感受到了隐式图搜索的内涵
和补丁vs漏洞差不多的叭~
其实搜索和最短路从某种程度上来说
本质上是一样的吧
这里我用的是二进制+SPFA
首先我们理清楚二进制的问题
因为我们发现病情不过就是10种对吧
那么我们如果用一个vector来保存肯定是会更麻烦并且更慢的对叭~
那么我们可以直接二进制位运算一搞
一个状态s其每个有效位上的0或者1必然就是表示与其对应的疾病的有无
比如最低位为1表示第一种病是有的
那么我们可以用两个数组a[],b[]分别记录下药性
a[i]的二进制位上为1表示i这种药可以治愈对应的病
同理b[i]的二进制位上为1表示i这种药可以导致得对应的病
那么我们可以先预处理出a[] b[]
然后我们就以所有病都有的状态s为源点开始SPFA	有s=(1<<n)-1
关键是如何建立隐式图？
即如何从一个结点状态扩展到另一个状态?
这就涉及到我们的update操作了
很奇妙的位运算
具体也有注释了
最后说说心得叭~
其实感觉所有的bfs都可以转换为最短路来做
只不过是d[i]有的时候i无法表示一个状态
所以不太好做
而位运算就是一种强大的工具将两者连接了起来
算法真是奇妙>3<
QAQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN=12;
const int MAXM=105;
const int MAX=(1<<10)+5;
const int INF=(1<<30)-1;
queue<int> q;
bool in[MAX];	int d[MAX];//SPFA相关
int a[MAXM];//记录治愈药性
int b[MAXM];//记录毒性
int n,m;
int s;//初始状态

void init()
{
	int x;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=0;j<n;j++)
		{
			cin>>x;
			if(x==1)
				a[i]|=(1<<j);
			else	if(x==-1)
				b[i]|=(1<<j);
		}
	s=(1<<n)-1;	//初始时所有患病
	for(int i=0;i<=(1<<n)-1;i++)
		d[i]=INF;
}

inline int update(int x,int k)
{
	x&=(~a[k]);//a[k]取反之后不能治愈的变为了1,只有两个都为1才会患病
	x|=b[k];//有一个为1则这种病会患上
	return x;
}

void SPFA()
{
	d[s]=0;	q.push(s);	in[s]=1;
	while(!q.empty())
	{
		int u=q.front();	in[u]=0;	q.pop();
		for(int i=1;i<=m;i++)
		{
			int v=update(u,i);
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				if(!in[v])
					q.push(v),in[v]=1;
			}
		}
	}
	if(d[0]==INF)
		cout<<"The patient will be dead."<<endl;
	else
		cout<<d[0]<<endl;
}

int main()
{
	init();
	SPFA();
	return 0;
}
     