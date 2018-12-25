/*
 由上一组合产生下一组合
① 从右向左寻找可以往下取一个元素的数，位置为j。
   （举个例子：从7个数中取4个数，有一个组合为1367，那么6、7就不能再往下取了）
② 数列的j位到n位重新取元素。
注意：
① 从N个连续元素中取M个元素。如果元素序号不连续，就需要修改下面的“+1”。
② 右侧的数字一定严格大于左侧的数字。

如1-7的四个数组合1 3 6 7
找到的位置q为3 则3+1变成4	然后后面都按前面的+1
即 1 3 4 5
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int s,t,w;
string a;

int main()
{
	cin>>s>>t>>w;
	cin>>a;
	for(int p=0;p<5&&(a[0]-'a'<t-w);p++)//控制找的个数(最多5个)，同时a[0]因为是要最小所有也有边界
	{
		int q;
		for(q=w-1;q>=0&&(a[q]-'a'==t-w+q);q--);//从右向左寻找可以往下取一个元素的数，位置为q
			if(q>=0)//如果q>=0即还有下一个排列
			{
				a[q]++;//这个位置+1
				for(int i=q+1;i<w;i++)//后面全部按字典序改变
					a[i]=a[i-1]+1;
				cout<<a<<endl;
			}
	}
	return 0;
}
     