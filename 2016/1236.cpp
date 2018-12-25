/*
这题~....害怕
可以直接贪心？不知道正确性与否惹~
但是数据是过了也不知道是不是数据太弱
窝感觉无懈可击啊~
分享个别人的博客咯~
{
首先，题目让你求出"XXYY"，"XYXY"，"XYYX"，"XXXX"类似的句子。
通过仔细的分析，可以发现，只要出现两对相同，就可以满足韵脚。
例如:1 2 1 2 ,2 1 2 1,1 1 2 2……
接着，题目告诉了我们重要的一点
“词的句子间不能交错，比如你选了1 4 6 8做为一首诗，那么7你就不能再选了。 ”
其实到这里，正解就已经很明显了：先从左到右扫一遍韵脚，开一个记录数组，
假如有满足"XXYY"，"XYXY"，"XYYX"，"XXXX"，那么就ans+1，并将记录数组清空。
这样做为什么正确？ 因为你要保证用到的韵脚越少，拼成的句子越多，并且句子与句子之间不能重叠，
假如你对[1,100)这个区间进行选择，你肯定是将这个区间里所有的句子能拼多少拼多少，如果你操作完了这个区间，
那么这个区间就相当于“报废”了，因为句子与句子之间不能重叠。
}
所以直接贪心扫描就好了~复杂度O(n)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=4005;
int v[MAXN];
int a[MAXN];
bool flag;
int n,ans;

void init()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
		v[a[i]]++;
		if(v[a[i]]==2)
		{
			if(flag)
			{
				flag=0;	ans++;
				memset(v,0,sizeof(v));
			}
			else
				flag=1;
		}
		else	if(v[a[i]]==4)
		{
			ans++;
			flag=0;
			memset(v,0,sizeof(v));
		}
	}
	cout<<ans<<endl;
	return 0;
}
     