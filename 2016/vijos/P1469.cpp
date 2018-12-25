/*
突然发现出奇的简单啊，就是简单的构造小根堆我的天
首先我们看，题目告诉我们：
为了简化题目，数据保证n=2^k-1，即保证最后的堆是一棵满二叉树。
Orz这还做啥啊 水题一道
意思就是这是个满二叉树，根本不用判断出界啥的
那么就很有趣了
排序+构建小根堆是很基本的内容了，递归构造完成即可
他要求字典序最大
所以我们在构造堆的时候，把后半段丢掉左子树，前半段丢在右子树
这样就可以保证字典序最大~
哎大发慈悲来说说构造小根堆的方法吧
以前题目都没碰到这么赤裸裸的基础功
构造小根堆用递归方法做即可，递归传送三个参数：
1.当前堆顶位置cur 2.构造的子树左端点范围 3，右端点范围
因为小根堆要求根最小，所以要从小到大排序
每次取l位置的元素作为堆顶(因为它最小)
然后我们就递归下降构造左右子树即可
详细见代码领悟吧~QAQ
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=70000;
int a[MAXN],tree[MAXN];
int n;

void build(int cur,int l,int r)
{
	tree[cur]=a[l];
	if(cur<<1>n)
		return;
	build((cur<<1)+1,l+1,(l+r+1)>>1);  //注意位运算符号要加上括号(优先级)
	build(cur<<1,((l+r+1)>>1)+1,r);//要加上1除以2,即l+r为奇数的情况
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	build(1,1,n);
	for(int i=1;i<=n;i++)
		cout<<tree[i]<<" ";
	return 0;
}
     