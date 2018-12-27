/*
这道题目的状态不难想
关键是想到一个方便转移的状态很难呐
我们来看
设f[i,j]为以a[i-j+1…..i]结尾的递增序列的最长长度
即表示前i个最后一个是[i-j+1..i]
这样就会方便很多了
f[i,j]=max{f[i-j,k]}+1     
其中k=1…i-j且a[i-j-k+1…i-j]<a[i-j+1…..i]
就是在枚举前一段的长度。
这个转移出来了我们得到了f[l][]
所以我们要枚举所有的结尾点遍历一遍
得到了最优解
这里最难的就是打印了
我们有两种做法
1.用一个数组把用了哪个k存下
2.直接递归打印
这里用的是递归打印(因为我太弱惹不会别的啊)
模仿了一下题解中的做法
然后就直接乱搞就好了
注意多解时题目中的要求
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=105;
char a[MAXN];
int f[MAXN][MAXN];
int ans;
int l;

void init()
{
	cin>>(a+1);
	l=strlen(a+1);
	memset(f,-0x3f,sizeof(f));
	for(int i=1;i<=l;i++)
		f[i][i]=1;
}

bool check(int i, int j, int k, int w)
{
        if (i > j || k > w) 
        	return 1;
        while (i < j && a[i] == '0') 
        	i++;
        while (k < w && a[k] == '0') 
        	k++;
        if (j-i != w-k) 
        	return j-i > w-k;
        while (i <= j) 
        {
                if (a[i] != a[k]) 
                	return a[i] > a[k];
                i++;	k++;
        }
        return 0;
}

bool print(int i,int j)//和状态定义对应
{
	if(i==j)//第一个的时候
	{
		for(int k=1;k<=i;k++)
			cout<<a[k];
		return true;
	}
	for(int k=1;k<=i-j;k++)
		if(f[i-j][k]+1==f[i][j]&&check(i-j+1,i,i-j-k+1,i-j))
			if(print(i-j,k))//还能继续递归继续打
			{
				cout<<',';
				for(int p=i-j+1;p<=i;p++)
					cout<<a[p];
				return true;
			}
	return false;
}

int main()
{
	init();
	for(int i=1;i<=l;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i-j;k++)
				if(check(i-j+1,i,i-j-k+1,i-j))
					f[i][j]=max(f[i][j],f[i-j][k]+1);
	ans=1;
	for(int i=2;i<=l;i++)
		if(f[l][i]>f[l][ans])
			ans=i;
	print(l,ans);
	return 0;
}
     