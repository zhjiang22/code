/*
很裸的一道搜索题啊
我们看这个数据范围就知道不写搜索都对不起出题人了
我们可以直接bfs+判重
判重我们知道，我们可以用hash,set,map等方法来做咯
这里为了好写一点
就用的set映射来判重
(闲的无聊实验证明了一下set会比map慢一点啊Orz)
Orz还是速度还是可以的(不过NOIP最好还是手写hash叭)
然后这样直接bfs就很简单了
基本功吧
整个题目唯一的稍微的难点就在于字符串的处理了
感觉像是在考字符串？
我们怎么找到一个字符串中有没有可以变换的子串然后改变它
OTZ这很麻烦的鬼东西如果用数组的话
但是如果我们用string就很好做了
加上几个string的函数
就跟水题一样如履平地233333
然后随便乱搞叭
嗯就这样了
那段bfs扩展的字串处理有点复杂
也可以用自己的方法搞咯
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

struct node
{
	string s;
	int step;
};
queue<node> q;
set<string> vis;
string start,to;
string a[15];
string b[15];
int l=1;

void init()
{
	cin>>start>>to;
	while(cin>>a[l]>>b[l])
		l++;
	node t;
	t.step=0;
	t.s=start;
	q.push(t);
}

void bfs()
{
	node t;
	while(!q.empty())
	{
		t=q.front();	q.pop();
		if(t.step>10)
			break;
		if(t.s==to)
		{
			cout<<t.step<<endl;
			return;
		}
		if(!vis.count(t.s))
		{
			vis.insert(t.s);
			for(int i=1;i<=l;i++)
				if(t.s.find(a[i])>=0)
					for(int j=t.s.find(a[i]);j>=0&&j<=(t.s.length()-a[i].length());j=t.s.find(a[i],j+1))
					{
						node w=t;
						w.step++;
						w.s.replace(j, a[i].size(), b[i]);
                        q.push(w);
					}
		}
	}
	cout<<"NO ANSWER!"<<endl;
}

int main()
{
	init();
	bfs();
	return 0;
}
     