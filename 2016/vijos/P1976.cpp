/*
一道有趣的题目Orz
说说我做这道题的思路经历吧
一看到这道题
我就直接想到了其实就是求颜色相同且距离差值为偶数的点对
然后想直接枚举一下O(n^2)
看一下数据范围n到了10万
肯定超时
怎么做呢Orz
然后我就看到了数据范围中那一句
"且不存在出现次数超过 20 的颜色"
然后瞬间就想到
这题的突破口在颜色数量少？
看一下颜色也不少呀百分之百的范围
然后就先去看第四题了
果然第四题直接写了个暴力
然后就直接回来看到这道题
想了半天
诶不对突破口应该就是这个颜色数量！
我们可不可以记录下每个颜色出现的奇数位置或者偶数位置
诶不对 (～￣▽￣)→))*￣▽￣*)o
傻了
我们可以记录下每种颜色的出现位置啊
那这样就不大了对吧
然后我就直接赤裸裸地写了个vector保存下这个颜色出现位置
然后对于每一个点都进入它的颜色中的vector[]来找满足条件的数
匆匆打完
完美23333333
然后四题都检查完了
就提交了	90分一个点过不去
Orz难道这不是标程？QAQ
忍住不看题解
继续想吧
盯着屏幕发呆啊
然后突然就想到了
我擦我傻了
为啥要遍历所有的点然后找是否成立呢？
我们可以直接进入所有的颜色集合中去
然后在这里面找一下所有可能的配对
这样的时间瞬间就缩小了很多
QAQ
好有道理的样子
然后就瞬间改了过来
AC了
长见识了QAQ
嗯有了这个思路应该能听懂了吧QWQ
注意因为数据很大啊
加的时候和乘的时候都取一下模
才不会溢出
QAQ反正碰到取模的就有可能溢出的地方都保险加上个取模
毕竟这东西又不要你钱又不要你命的
QAQ考试一定要小心
长知识了
挺锻炼逻辑思维的
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN=100006;
const int mod=10007;
struct node
{
	int num,color;
}a[MAXN];
vector<int> c[MAXN];
int n,m;
int ans;

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].num);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].color);
}

int main()
{
	init();
	for(int i=1;i<=n;i++)
		c[a[i].color].push_back(i);
	for(int k=1;k<=m;k++)
	{
		int d=c[k].size();
		for(int i=0;i<d;i++)
			for(int j=i+1;j<d;j++)
				if((c[k][j]-c[k][i])%2==0)
					ans=(ans+(c[k][j]+c[k][i])%mod*(a[c[k][j]].num+a[c[k][i]].num)%mod)%mod;
	}
	printf("%d\n",ans%mod);
	return 0;
}
     