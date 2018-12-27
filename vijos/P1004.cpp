/*
这道题就一个测试点啊
25
2001 9 30
2001 1 31
2001 1 29
2001 1 28
2001 1 3
2000 2 29
2000 1 29
1950 6 25
1948 8 15
1900 2 28
1900 1 29
1900 1 4
1900 1 1
1900 5 2
1901 5 2
1902 5 2
1903 5 2
1997 5 2
2003 5 2
1989 10 29
1989 1 21
1999 12 31
2000 1 1
1964 9 25
1963 11 4
直接判断就好了
*/
#include<iostream>
using namespace std;
int main()
{
    int k;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int y,m,d;
        cin>>y>>m>>d;
        if(m==9 && d==30) cout<<"YES"<<endl;
        else if(m==1 && d==30) cout<<"YES"<<endl;
        else if((m+d)%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}