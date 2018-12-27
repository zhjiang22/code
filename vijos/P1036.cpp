/*
Orz我们可以看出来
首先要把x轴和y轴分开处理。
每个点上有个权，然后费用总和为所有点到选定点的距离乘上它的权，如果每个点有个权k，
我们可以把这个拆成坐标相同的k个点，这时我们发现问题转化为不带权的中位数问题了！
不带权的中位数问题就是排序之后找到当中的那个点，
而这里我们就是要找到从点1到它的权值部分和正好等于总权值一半的那个点。
于是我们可以先把所有点按坐标排序，然后从头开始扫描，到权值和正好大于等于总权值和一半的时候就是答案了
到底是什么意思呢
我们看其实我们要找的是一个坐标(x,y)满足最优
那么我们的x肯定要是最优	同理y也要最优(因为这里的距离不是欧几里得距离而是横纵坐标之差之和)
就把一个问题拆成了找一个最优的y和找一个最优的x
那么我们就转换为求中位数的问题了
怎么在线性时间内求解中位数？
在区间 [first, last) 内查找中位数时，用一个变量s1表示在序列中所求的带权中位数到first这一段的权值之和
（设带权中位数下标为idx，则ΣW[first..idx]≥s1，W[idx+1..last]<s1）。
用快速选择（快速排序的应用）找到不带权的序列的中位数。
设mid=(first+last)/2，
如果cnt=ΣWi（i∈[first, mid)）≥s1，说明整个序列的带权中位数在区间[first, mid)内；
如果s1-cnt>Wnid，说明整个序列的带权中位数在区间[mid, last)内；
否则，Amid就是带权中位数
嗯这个中位数求解方法很经典很强势
一定要记住
代码中用到了nth_element STL函数
nth_element函数
使用方法：nth_element(start, start+n, end)
使第n大元素处于第n位置（从0开始,其位置是下标为n的元素），并且比这个元素小的元素都排在这个元素之前，
比这个元素大的元素都排在这个元素之后，但不能保证他们是有序的。
*/
#include <algorithm>
#include <cstdio>
using namespace std;

struct node
{
	int x, w;
	bool operator<(const node &rhs) const
	{
		return x < rhs.x;
	}
}x[100000], y[100000];

int Median(node a[],int first,int last, int s1, int s2)
//s1表示在序列中所求的带权中位数到first这一段的权值之和
//
{ //在区间 [first, last) 内查找中位数
	int n = last-first;
	if (n == 1) return a[first].x;
	int cnt = 0;
	int mid = first+n/2;
	nth_element(a+first,a+mid,a+last);
	for (int p = first; p < mid; ++p)
		cnt += a[p].w;
	if (cnt >= s1) return Median(a,first, mid, s1, cnt-s1);
	if (s1-cnt > a[mid].w) return Median(a,mid, last, s1-cnt, s2);
	return a[mid].x;
}

int main()
{
	int i, n, s, w = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		int t1, t2;
		scanf("%d%d%d%d", &x[i].x, &y[i].x, &t1, &t2);
		x[i].w = t1*t2; y[i].w = x[i].w; w += x[i].w;
	}
	printf("%d %d\n", Median(x,0, n, w/2, w/2), Median(y,0, n, w/2, w/2));
}
