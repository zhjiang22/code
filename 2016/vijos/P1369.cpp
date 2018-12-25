/*
一个经典模型
即LIS中一定要包含某一个数
所以我们将要包含的这个数设为x
我们先将x左边所有的比它小的数取出来
跑一边LIS
再将右边所有比它大的数取出来
跑一遍LIS
然后两个LIS的长度之和+1就是答案
即两边加上中间这个数
Orz考虑到数据范围很大啊
LIS如果n^2的话6AC+4TLE，加二分查找nlogn全部Accepted
所以我们就写个LIS二分查找算法就好了
挺裸的一道题QAQ
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[300005];
int f[300005];
int n,k;
int max1,max2;

int find(int m,int key)
{
	int mid,l=1,r=m;
    while(l<=r)
    {
        mid =(l+r)>>1;
        if(a[f[mid]]<key) l=mid+1;
        else if(a[f[mid]]>key) r=mid-1;
        else return mid-1;
    }
    return r;
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int len=0;
	for(int i=1;i<k;i++)
		if(a[i]<a[k])
			a[++len]=a[i];
	f[1]=1;
	max1=(len==0?0:1);
	for(int i=2;i<=len;i++)
	{
		if(a[i]>a[f[max1]])
			f[++max1]=i;
		else
		{
			int x=find(max1,a[i]);
			f[x+1]=i;
		}
	}
	len=0;
	for(int i=k+1;i<=n;i++)
		if(a[i]>a[k])
			a[++len]=a[i];
	memset(f,0,sizeof(f));
	f[1]=1;
	max2=(len==0?0:1);
	for(int i=2;i<=len;i++)
	{
		if(a[i]>a[f[max2]])
			f[++max2]=i;
		else
		{
			int x=find(max2,a[i]);
			f[x+1]=i;
		}
	}
	cout<<max1+max2+1<<endl;
	return 0;
}
     

