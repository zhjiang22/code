/*
这道题目很明显是一道并查集题目~
设f[i]表示从1-i区间内的1的个数的奇偶性
对于一个查询(a,b)如果答案是偶数
说明1-(a-1)与1-n的含1个数的奇偶性相同
即有f[a-1]==f[b]
否则f[a-1]!=f[b]
那么对于奇偶性来说就只有两种情况咯
相同奇偶性或者不同奇偶性
这就是和关押罪犯那道题有点像只有两种集合
那么我们用a和a+maxn表示一个对立面
如果a和b同奇偶就将a,b合为一个集合
a+maxn,b+maxn也会为相同集合
否则就说明a的相反面和b同集,b的相反面也和a同集合
我们就将(a,b+maxn) (b,a+maxn)合并为一个集合
判断时如果是同奇偶，
就判断a和b+maxn(或者a+maxn,b)是不是同一个集合，如果是说明矛盾
否则按上面合并
同理如果是非同奇偶，
那么就检查a,b(或者a+maxn,b+maxn)是否是一个集合不是矛盾，
否则按上面合并即可
同时我们注意到这个下标大小可能到1000000000
这实在太大了，我们就想到用hash压缩一下，不然根本放不下
这道题就这样解决了~orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int Hash=6000,maxn=10000;

int f[2*maxn+10];
int Map[Hash+10];
string s;
int n,k,a,b;

int hash1(int x)
{
    int b=x%Hash;
    while(Map[b]!=-1&&Map[b]!=x)
      b=(b+1)%Hash;
    Map[b]=x;
    return b;
}

int getfather(int x)
{
    return f[x]==x?x:f[x]=getfather(f[x]); 
}


void Union(int a,int b)
{
    a=getfather(a);
    b=getfather(b);
    if(a!=b)
      f[a]=b;
}
int main()
{
  memset(Map,-1,sizeof(Map));
  cin>>n>>k;
  for(int i=1;i<=2*maxn+9;i++)
    f[i]=i;
  int i;
  for(i=1;i<=k;i++)
  {
      cin>>a>>b>>s;
      a=hash1(a-1);
      b=hash1(b);
      if(s[0] == 'e')
      {
        if(getfather(a)==getfather(b+maxn))
          break;
        Union(a,b);
        Union(a+maxn,b+maxn);
      }
      else
      {
        if(getfather(a)==getfather(b))
          break;
        Union(a,b+maxn);
        Union(a+maxn,b);
      }
  }
  cout<<i-1<<endl;//要-1
  return 0;
}
     