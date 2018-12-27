/*
真水题~
一开始还想来个啥贪心的~
后面发现直接枚举四个使用的数量然后判断得到最小值
因为有个>k continue
所以实际运算次数连10^4都没有~
随便搞一搞就好啦~
注意一下精度运算咯~
来回的距离就是到球的距离*2
PS:把k1的x1打成了x2过了样例还拿了80分....无奈
又WA了一次...害怕窝好弱啊
求rp++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define For(i,x)	for(int (i)=0;(i)<=(x);(i)++)

int k,x1,x2,x3,x4;
double ans=99999.0,cur;

int main()
{
	cin>>k>>x1>>x2>>x3>>x4;
	int k1,d1,d2,v;
	For(i,10)	For(j,10)	For(p,10)	For(q,10)
	{
		if(i+j+p+q>k)	continue;
		k1=(20-i*2)*x1;	v=(10+q)*x4;
		d1=(100-j*7)*x2;	d2=(100-p*9)*x3;
		ans=min(ans,double(k1+(double)(d1*2+d2)/v));
	}
	printf("%0.3lf\n",ans);
	return 0;
}
     