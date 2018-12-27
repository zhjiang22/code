/*
一道经典的dp
首先我们要弄清一个性质
因为输入的数字达到100位所以肯定是要直接利用字符串读入的
那么我们怎么得到一个合适的代价来转移呢？
我们自然会想到定义s[i][j]表示该字符串中
第i位到第j位的数组合起来%m所得到的值
这个好像有点不好推？
但是有一个很奇妙的性质(也可能是窝数学太弱)
我们可以直接这样递推s[i][j]
即s[i][i]=a[i]%m
s[i][j]=(s[i][j-1]*10+a[i])%m
这样是正确的(等效于约约去了一个m*10^x)
那么我们来考虑状态转移了
和那些乘积最大等经典划分型dp问题一样了
我们是要寻找合适的断点来转移过去
但是我们会发现
如果我们从前面的断点尝试转移到当前的状态
那么我们就要找到在进行这一个操作前对应的状态
等等？取模逆过来是什么？
根本是不可操作的
那么我们自然会想到lrj书中所说的
刷表法！
即对于当前的一个状态(情况)
我们不是尝试来更新得出当前的状态
而是尝试从这个状态推出到别的状态去
即将后面的不断刷新
同时保证到了用某个状态x去刷新别的状态的时候
一定要已经考虑到了所有可能的情况刷出了正确的状态x
不重复不遗漏
那么我们就可以发现
对于某个状态f[j][k]如果在j后面加上一个*号连到i
那么它就可以成功的尝试刷新到i的某个f[i][]的值
即f[i][k*s[j+1][i]%m]=min(f[i][k*s[j+1][i]%m],f[j][k]+1);
k*s[j+1][i]%m即是加上*后达到的值
然后就可以成功的转移了
初值为f[i][s[1][i]]=0(即不加*)
三重循环应该分别是i,j,k
时间复杂度为O(N^2*M)
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
const int MAXM=55;
const int INF=(1<<30)-1;
int f[MAXN][MAXM];//f[i][j]表示前i个数要达到余数j所需要添加的最小括号数
int s[MAXN][MAXN];
char a[MAXN];
int n,m;

void init()
{
	gets(a+1);	cin>>m;
	n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		s[i][i]=(a[i]-'0')%m;
		for(int j=i+1;j<=n;j++)
			s[i][j]=(s[i][j-1]*10+(a[j]-'0'))%m;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			f[i][j]=INF;
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		f[i][s[1][i]]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			for(int k=0;k<m;k++)
				f[i][k*s[j+1][i]%m]=min(f[i][k*s[j+1][i]%m],f[j][k]+1);
	for(int i=0;i<m;i++)
		if(f[n][i]!=INF)
		{
			cout<<i<<" ";
			cout<<f[n][i]<<" ";
			break;
		}
	for(int i=m-1;i>=0;i--)
		if(f[n][i]!=INF)
		{
			cout<<i<<" ";
			cout<<f[n][i]<<" ";
			break;
		}
	return 0;
}
     