/*
线段树第一题
OTZ今天终于弄懂了线段树区间修改的原理了
以前一直不懂啥标记啥的而且这么懒也没去看
所以自从NOIP模拟赛被虐了之后
决定不能被初中生虐场啊老老实实写线段树吧Orz
嗯感谢这篇好博客让我受教了
http://blog.csdn.net/thinking2013/article/details/41621657
%%%%%%%%%%祝愿rp++
说说我自己的理解吧
其实就是为了偷懒咯
如果你修改一整个区间的话
那么所有的区间对应的结点都要修改
最坏情况可能要修改整个线段树(修改整个区间的时候)
这样比如说我现在跑下去不断递归然后修改修改修改
然后下一次查询直接查询查询查询
可能会感觉很爽
但是我们为什么不再查询或者下一次修改的时候
到达了这个地方顺手把它一改呢？
所以我们就可以打上个标记
比如我们要修改[2,5]
我们就一直递归下去
当找到某个节点的区间	是完全包含于[2,5]中的
我们就修改一下这个点	然后不再往下走了
我们给它打上个tag标记	表示这里本来还要修改但是我太懒了没有改它的子孙
反正我现在修改了	我又用不上它
又不影响我的答案管他呢
然后比如我们下一次修改到某个点	发现这个点有个标记
或者查询某个区间的时候	递归时发现这个点有个标记
那么这个时候就不能无视了
不然就会影响答案的正确性
我们模板中已经有一个专门的函数push_down了
然后我们就push_down把它这个标记传下去
并且清空它自己的标记
注意我们传给儿子就好了
至于孙子我管他呢
要用到的时候自然会从我的儿子传到孙子
这样就节省了很多的时间和效率
OTZ
我的理解就是这样了比较接地气对吧233333333
继续fighting	干下线段树Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=100005;
struct node
{
	int l,r,tag,maxv;
}tree[MAXN*4];
int n,m;
int a[MAXN];

void pushdown(int o)
{
	int &w=tree[o].tag;
	tree[o<<1].tag+=w;
	tree[(o<<1)+1].tag+=w;
	tree[(o<<1)].maxv+=w;
	tree[(o<<1)+1].maxv+=w;
	w=0;
}

void build_tree(int o,int l,int r)
{
	tree[o].l=l;
	tree[o].r=r;
	if(l==r)
	{
		tree[o].maxv=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(o<<1,l,mid);
	build_tree((o<<1)+1,mid+1,r);
	tree[o].maxv=max(tree[o<<1].maxv,tree[(o<<1)+1].maxv);
}

void update(int o,int l,int r,int c)
{
	int x=tree[o].l;	int y=tree[o].r;
	if(x==l&&y==r)
	{
		tree[o].tag+=c;
		tree[o].maxv+=c;
		return;
	}
	if(tree[o].tag)
		pushdown(o);
	int mid=(x+y)>>1;
	if(r<=mid)
		update(o<<1,l,r,c);
	else	if(l>mid)
		update((o<<1)+1,l,r,c);
	else
		update(o<<1,l,mid,c),
		update((o<<1)+1,mid+1,r,c);
	tree[o].maxv=max(tree[o<<1].maxv,tree[(o<<1)+1].maxv);
}

int query(int o,int l,int r)
{
	int x=tree[o].l;	int y=tree[o].r;
	if(l==x&&r==y)
		return tree[o].maxv;
	if(tree[o].tag)
		pushdown(o);
	int mid=(x+y)>>1;
	if(r<=mid)
		return query(o<<1,l,r);
	else	if(l>mid)
		return query((o<<1)+1,l,r);
	else
		return max(query(o<<1,l,mid),query((o<<1)+1,mid+1,r));
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build_tree(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int k,l,r,c;
		cin>>k;
		if(k==1)
		{
			cin>>l>>r>>c;
			update(1,l,r,c);
		}
		else
		{
			cin>>l>>r;
			cout<<query(1,l,r)<<endl;
		}
	}
	return 0;
}
     
