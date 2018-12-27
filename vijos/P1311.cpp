#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

string a[25];
char w;
int n,l;
int used[25];
int f[25][25];
int ans;

int change(const string &str1, const string &str2)
{
	int i,j;
	int len1=str1.length();
	  for(i = 1; i < len1; i++) {    //枚举循环节长度,从小到大以便获得最长长度.不能等于len1,否则会有包含情况 
        if(i > str2.size())    //如果循环节长度大于要连接的单词,说明在此长度及以后长度无解 
            break;
        for(j = 0; j < i; j++)
            if(str1[len1 - i + j] != str2[j])
                break;

        if(j == i)            //如果上面那个循环执行完毕,说明此循环节长度可行 
            return i;        //返回循环节长度 
    }

    return 0;
}

void dfs(int now)
{
	ans=max(ans,l);
	used[now]++;
	int t;
	for(int i=1;i<=n;i++)
		if(used[i]<2&&f[now][i])
		{
			t=f[now][i];
			l+=t;
			dfs(i);
			l-=t;
		}
	used[now]--;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=change(a[i],a[j]);
	for(int i=1;i<=n;i++)
		if(a[i][0]==w)
			l=a[i].length(),dfs(i);
	cout<<ans<<endl;
	return 0;
}
     