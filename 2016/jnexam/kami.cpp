#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

stack<string> s1;//前进栈
stack<string> s2;//后退栈
string a;
string b="http://www.acm.org/ ";
string now;

int main()
{
	while(1)
	{
		cin>>a;
		if(a=="QUIT")
			break;
		if(a=="VISIT")
		{
			s2.push(b);
			cin>>b;
			while(!s1.empty())
				s1.pop();
			cout<<b<<endl;
		}
		else	if(a=="BACK")
		{
			if(s2.empty())
				cout<<"Ignored"<<endl;
			else
			{
				s1.push(b);
				b=s2.top();	s2.pop();
				cout<<b<<endl;
			}
		}
		else	if(a=="FORWARD")
		{
			if(s1.empty())
				cout<<"Ignored"<<endl;
			else
			{
				s2.push(b);
				b=s1.top();	s1.pop();
				cout<<b<<endl;
			}
		}
	}
	return 0;
}
     