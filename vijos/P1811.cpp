/*
水题啊直接模拟不就好了
这里可以用一个优先队列来减小代码量咯
OTZ因为这个接水顺序固定了
所以下一个准备接水的人肯定是在目前还要接水的接水量最少的人后面接着
他的水龙头接水
所以我们用一个优先队列来维护m个水龙头还需要多久可以接水
初始化肯定是m个0
然后每次就寻找这个最小的
加上去现在这个人
再更新一下时间就好了
下面还有个非优先队列的自己啃叭~
Orz
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>  
using namespace std;

priority_queue<int,vector<int>,greater<int> >q;
int n,m,x;

int main()
{
    scanf("%d%d",&n,&m);    
    for(int i=1;i<=m;i++)
    	q.push(0);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&x);
    	q.push(q.top()+x),q.pop();
    }
    while(q.size()-1)
    	q.pop();
    printf("%d\n",q.top());
}
/*
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,m,mn,mx=0,q;
    int s[101]={0};
    int w[10001];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
		mn=999999;
		for(int j=1;j<=m;j++){
			if(s[j]<mn){q=j;mn=s[j];}
        }
        s[q]+=w[i];
    }
    for(int i=1;i<=m;i++)
		mx=max(s[i],mx);
    cout<<mx;
    return 0;
}
*/