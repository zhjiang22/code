/*
直接模拟栈就好
s为栈(注意是string类)	c数组标记当前某层类型
碰到一个字母
我们把它压入栈中，top++
并用'a'标记当前top层它是字母类型
如果是运算符
我们弹一次栈(注意s数组表达的string就是一步一步出来的表达式)
然后在读取s[top+1](此时top已经--)
用一个临时变量string b来接受一下
然后判断要不要加上括号
1、优先级大的在优先级小的前时后者加括号
2、如果是-或/，同级运算后者加括号
然后更新完b之后
我们再在当前层s[top]后部加上a[i]和b数组
最后别忘了c[]标记当前此层的类型
我们要分两种就是'+''-'和'*''/’
然后就用一个代替一下表达就好了
以此反复
知道所有的读完
此时肯定是有top==1
(因为一定是对应的所以可以弹完只剩最后一个)
而这一个就是答案QAQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string a,b;
string s[260];
char c[260];
int top,l;

bool check(char x)
{
	return (x>='A'&&x<='Z');
}

int main()
{
	cin>>a;
	l=a.length();
	for(int i=0;i<l;i++)
	{
		if(check(a[i]))
			s[++top]=a[i],c[top]='a';
		else
		{
			top--;
			b=s[top+1];
			if(a[i]=='-'&&c[top+1]=='+')//减号需要加上括号
				b='('+b+')';
			if(a[i]=='/'&&c[top+1]!='a')//除号也要
				b='('+b+')';
			if(a[i]=='*'&&c[top+1]=='+')//如果是除并且里面的是加减那么也要加括号
				b='('+b+')';
			if(c[top]=='+'&&(a[i]=='/'||a[i]=='*'))//如果新碰到的是'/'或'*'并且原来的是'+'
				s[top]='('+s[top]+')';
				
			s[top]=s[top]+a[i]+b;
			if(a[i]<='-'&&a[i]>='+')//'+'代表加或减
				c[top]='+';
			else//'*'表示乘或除
				c[top]='*';
		}
	}
	cout<<s[1]<<endl;
	return 0;
}
     