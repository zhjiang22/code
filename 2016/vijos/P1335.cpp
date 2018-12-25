/*
不需要什么枚举代码量++
直接循环暴力搞定23333
有点6感觉
详细见代码注释
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
int a[10][10];

int main()
{
	cin>>t;
	while(t--)
	{
		int cur=0;
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++)
				cin>>a[i][j];
		for(int k=1;k<=9;k++)//检查行或者列
			for(int i=1;i<=9;i++)
				for(int j=1;j<i;j++)
					if(a[k][i]==a[k][j]||a[i][k]==a[j][k])
						cur=1;
		for(int x=1;x<=9;x+=3)//枚举每个九宫格左上角的坐标
			for(int y=1;y<=9;y+=3)
			{
				for(int i=0;i<9;i++)//每个九宫格九个数，与左上角差值压缩
					for(int j=0;j<9;j++)
					{
						if(i==j)	continue;//相同时
						else
						{
							int i1=i/3,i2=i%3;//解
							int j1=j/3,j2=j%3;//压
							if(a[x+i1][y+i2]==a[x+j1][y+j2])//判断
								cur=1;
						}
					}	
			}
		if(cur)
			cout<<"Wrong"<<endl;
		else
			cout<<"Right"<<endl;
	}
	return 0;
}
     