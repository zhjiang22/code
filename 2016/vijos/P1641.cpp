/*
老血已吐~很容易想到贪心算法(DP也是可以但是稍微要优化一下)
实在是坑爹....可怕
我们可以这样贪~：
对于要弹奏的K个音色
我们一定是先将出现的所有N-1个音色都弹完了之后再换弦
而弹这些音色用的就是没有出现的那个第N个音色~！
因为弹奏是要按照顺序来的
其实可以证明这样贪心不会丢失最优解~！
那么我们就可以想到这样来做
先对于每个要弹奏的音色在n种音色中找到其对应的编号
然后从头开始弹下去
标记每个弹过的曲子
当所有曲子都弹过的时候
就不得不换弦了
注意！这最后弹的第n种音色是换弦之后弹奏的！
同时换了弦之后要及时清除弹奏过的标记
但当前这个标记还是要打上的
注意题目中虽然没有说无解的情况
但是实际是有无解的情况的
即当n=1时	则必然有要换k次弦...(雾
一开始用的string处理字符串
结果T了4个点...
然后一用字符数组
瞬间30ms出解却又WA两个点..
找了半天才发现在用memcmp的时候如果一个字符串过长加的那个长度参数
会非法越界访问更短的字符串..
然后就WA...(真RE)
竟然被窝机智地发现惹~！
真心坑....
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <map>
using namespace std;

const int MAXN=105;
const int MAXK=1005;
char a[MAXN][300];
int b[MAXK];
bool can[MAXN];
int n,k;
int ans,cnt;
int T;

void init()
{
	char c[300];
	cin>>n>>k;
	getchar();
	for(int i=1;i<=n;i++)
		gets(a[i]);
	for(int i=1;i<=k;i++)
	{
		gets(c);
		for(int j=1;j<=n;j++)
			if(strlen(c)==strlen(a[j]))
				if(memcmp(a[j],c,strlen(c))==0)
				{
					b[i]=j;
					break;
				}
	}
}


void work()
{
	if(n==1)
	{
		printf("For %d# problem we need %d\n",++cnt,k);
		return;
	}
	ans=0;
	memset(can,0,sizeof(can));
	for(int i=1;i<=k;i++)
	{
		can[b[i]]=1;
		bool flag=0;
		for(int j=1;j<=n;j++)
			if(!can[j])
				flag=1;
		if(!flag)
		{
			ans++;
			memset(can,0,sizeof(can));
			can[b[i]]=1;
		}
	}
	printf("For %d# problem we need %d\n",++cnt,ans);
}

int main()
{
	cin>>T;
	while(T--)
	{
		init();
		work();
	}
}
     