/*
水题一道啊
一个正确的英语短文一定有几个性质
这个百度上很多可以自行度娘
我们就用一个最重要的性质就可以轻松AC此题
我们先把所有字符储存下来
然后再用计数排序的方法记录下各种字母有多少个(注意大小写要等效)
然后我们很容易知道
英文中出现最多的字母就是e
我们就可以根据这个序列中出现最多的字母与e的差值
来推算出t
这样我们就可以A了这道题目
要注意的是	特别要注意这个t如果直接去减的话可能会是负的
所以我们一定要多加上个26然后运用取模来解决这个问题
如果t小于0我们先加上个26周期保证是正的
转换的时候取个模就好了
详细见代码叭
窝好弱啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char a[10000001];
unsigned long long b[100]={0};

int main()
{
	int p;
	int MAX=0;
	int x=0;
	while(scanf("%c",a+x)!=EOF)
		x++;
	a[x]='\0';
	for(int i=0;i<strlen(a);i++)
		if(a[i]>='a'&&a[i]<='z')
			b[a[i]-'a'+26]++;
		else if(a[i]>='A'&&a[i]<='Z')
			b[a[i]-'A']++;
	for(int i=0;i<52;i++)
		if(b[i]>MAX)
			MAX=b[i],p=i;
	int t=30-p;
	if(t<0)
		t+=26;
	for(int i=0;i<strlen(a);i++)
		if(a[i]>='a'&&a[i]<='z')
			cout<<char(((a[i]-'a'+t)%26)+'a');
		else if(a[i]>='A'&&a[i]<='Z')
			cout<<char(((a[i]-'A'+t)%26)+'A');
		else cout<<a[i];
	return 0;
}
     