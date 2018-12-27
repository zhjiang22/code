/*
此题神坑啊，一定要注意剪切粘贴的细节；坑啊坑啊
天啊噜啊
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int maxn=100000+10;
int text[maxn],buffer[maxn];
int n,k;
int a,b,c;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		text[i]=i;
	while(k--)
	{
		cin>>a>>b>>c;
		int z=b-a+1;
		memcpy(buffer,text+a,sizeof(int)*z);//将剪切断落复制出来
		memmove(text+a,text+b+1,sizeof(int)*(n-b));//将剪切断落后面的部分给弄到剪切断落位置前面来
		n-=z;//长度剪掉，到这里为止完成了将剪切断落剪出来的任务
		memmove(text+c+z+1,text+c+1,sizeof(int)*(n-c));//将粘贴位置数字后移
		memcpy(text+c+1,buffer,sizeof(int)*z);//将断落粘贴进去
		n+=z;
	}
	for(int i=1;i<=10;i++)
		cout<<text[i]<<endl;
	return 0;
}
     