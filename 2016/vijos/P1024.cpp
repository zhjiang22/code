/*
一道很纯粹的模拟题惹~
嗯其实很好写的呀~只要注意一些细节问题
循环节的问题的话应该碰到过很多了
只需要用个set维护是否出现(或者手写个hash也不麻烦)
然后不断进行操作产生新的数
直到产生了一个已经产生过的数结束~
那么我们很容易发现	这个数用直接数字肯定是不方便的
所以窝们用string类就好啦~
然后string字母排个序	组合出最大值最小值
然后得到一个新的string
至于输出答案的问题窝们可以用一个vector记录一下循环中的各个字符串
然后碰到已经出现的字符串停止之后
就再到向量中去找到这个字符串上一次出现的位置
就一直输出到最后就好啦~
花了快半小时才写好+调试好	然后发现全WA只有10分
害怕啊	后来发现数据有一个地方写成了int没开longlong
Orz果真窝好弱
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

vector<string> ans;
set<string> s;
string now;
int l;

void init()
{
	ans.clear();	s.clear();
}

long long getmax(string& c)
{
	long long ans=0;
	for(int i=l-1;i>=0;i--)
		ans=(ans*10)+c[i]-'0';
	return ans;
}

long long getmin(string& c)
{
	long long ans=0;
	for(int i=0;i<l;i++)
		ans=(ans*10)+c[i]-'0';
	return ans;
}

string tostring(long long x)
{
	char a[1000];
	int l=0;
	while(x)
	{
		a[l++]=x%10+'0';
		x/=10;
	}
	a[l]='\0';
	string c(a);
	reverse(c.begin(),c.end());
	return c;
}

int main()
{
	while(cin>>now)
	{
		init();
		while(!s.count(now))
		{
			s.insert(now);	ans.push_back(now);
			sort(now.begin(),now.end());
			l=now.length();
			long long a=getmax(now);	long long b=getmin(now);
			now=tostring(a-b);
		}
		ans.push_back(now);
		int k=0;	while(ans[k]!=now)	k++;
		cout<<ans[k]<<" ";
		while(ans[++k]!=now)
			cout<<ans[k]<<" ";
		cout<<endl;
	}
	return 0;
}
     