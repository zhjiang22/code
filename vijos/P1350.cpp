/*
说实话看了半天题目题目真心看不懂什么意思
然后突然就明白了
就是对于数列中的任何一个数
都可以表示为前面几个数之和
贪心+IDDFS
数列生成的原则一定是ai=ai-1+aj(j<i)
为什么呢？
假设ai的分解中没有ai-1那么ai-1这个数就是毫无用处的，删掉更优
A[D]=A[D-1]+A[K](K=D-1 downto 1)
如果当前最大数超过需要的数了，最优性剪枝
还加入了一个可行性剪枝
时间直接从800ms到了15ms
很强势
就是sum<<(depth-cur+1)<x
什么意思呢
我们使用DFSID，如果还能迭代d次，当前最大数*2^d次方小于n，可行性剪枝。
搜索顺序题目没有说明
但是从小到大搜索就是对了
然后还是看不懂题目是什么意思
我真是个弱逼
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=1005;
int depth;
int a[MAXN];
int now=1;
int x;

bool dfs(int cur,int sum)
{
    if(cur>depth)
    {   
        if(sum==x)
            return true;
        return false;
    }
    if(sum<<(depth-cur+1)<x)//巧妙的可行性剪枝
        return false;
    for(int i=now;i>=1;i--)
        if(sum+a[i]<=x)//最优性剪枝(如果已经大于x了果断剪枝)
        {
            a[++now]=sum+a[i];
            if(dfs(cur+1,sum+a[i]))
                return true;
            now--;//还原变量
        }
    return false;
}

int main()
{
    cin>>x;
    a[1]=1;
    while(++depth)
        if(dfs(1,1))
            break;
    cout<<depth+1<<endl;
    for(int i=1;i<=depth+1;i++)
        cout<<a[i]<<" ";
    return 0;
}
     