/*
纯模拟水题~~~
好吧窝承认这个代码写的有点丑.....
啊很明显窝就直接想到了用栈来储存界面窗口
如果寻找界面用另一个栈来接收
边弹边判断	然后到时候再弹回去
后面发现好麻烦啊~然后就写丑了。。
其实思路都是这样啦~
模拟题最好还是自己多写多调试~
唯一的坑点就是~	close是一个非法字符串OTZ....
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

struct point
{
	int x1,y1;
	int x2,y2;
};
stack<point> s;
stack<point> s1;
string c;
int n;

void work(int x,int y,int a,int b,int c)
{
	while(!s1.empty())	s1.pop();
	point u;
	bool ok=0;
	while(!s.empty())
	{
		u=s.top();	s.pop();	
		if(x<=u.x2&&x>=u.x1&&y<=u.y2&&y>=u.y1)
		{ok=1;break;}
		s1.push(u);
	}
	if(c==1)
	{
		while(!s1.empty())
			s.push(s1.top()),s1.pop();
		if(ok==1)
			s.push(u);
	}
	else	if(c==2)
	{
		if(ok==0)
			s.push(u);
		while(!s1.empty())
			s.push(s1.top()),s1.pop();
	}
	else
	{
		if(ok==0)
		{
			s.push(u);
			while(!s1.empty())
				s.push(s1.top()),s1.pop();
		}
		else
		{
			u.x1+=a;	u.x2+=a;	u.y1+=b;	u.y2+=b;
			while(!s1.empty())
				s.push(s1.top()),s1.pop();
			s.push(u);
		}
	}
}

int main()
{
	cin>>n;
	int x1,y1,x2,y2;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c[0]=='O')
		{
			cin>>x1>>y1>>x2>>y2;
			s.push((point){x1,y1,x2,y2});
		}
		else	if(c=="Click")
		{
			cin>>x1>>y1;
			work(x1,y1,0,0,1);
		}
		else	if(c[0]=='C')
		{
			cin>>x1>>y1;
			work(x1,y1,0,0,2);
		}
		else
		{
			cin>>x1>>y1>>x2>>y2;
			work(x1,y1,x2,y2,3);
		}
	}
	if(s.empty())
		cout<<"Nothing"<<endl;
	else
	{
		point p=s.top();
		cout<<p.x1<<" "<<p.y1<<" "<<p.x2<<" "<<p.y2<<endl;
	}
	return 0;
}
     