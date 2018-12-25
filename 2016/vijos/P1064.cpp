/*
模拟
为了使程序简便,使用常量数组将每个数字的写法存下。
每个数字都可以分成5个部分：上横，上竖，中横，下竖，下横（从上往下，其中竖有多种情况），
输出时就按照这5部分输出，可以发现横和竖的输出是相似的，可以合并在一起。
反正我是懒得写QAQ
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int k,st;
char s[256];
int main()
{
    scanf("%d",&k);
    st=k;
    cin>>s;
    for (int l=1;l<=5;l++)
    {
        if (l==1 || l==3 || l==5)
            st=1;
        else st=k;
        for (int j = 1; j <= st; j++)
        {    
           for (int i=0;i<strlen(s);i++)
            {
                if (l==1)
                    {    
                       if (i==0) cout<<" ";
                       if (s[i]!='4' && s[i]!='1') {for (int i=1;i<=k;i++) cout<<"-"; cout<<"   "; }
                       else {for (int q=1;q<=k;q++) cout<<" "; cout<<"   ";}
                    }
                if (l==2)
                    {
                        if (s[i] == '2' || s[i] == '3' || s[i] == '7' || s[i] == '1')
                        { cout<<" "; for (int q=1;q<=k;q++) cout<<" "; cout<<"| "; }
                        else if (s[i] == '5' || s[i] == '6')
                        { cout<<"|"; for (int q=1;q<=k;q++) cout<<" "; cout<<"  "; }
                        else 
                        { cout<<"|"; for (int q=1;q<=k;q++) cout<<" "; cout<<"| "; }
                    }
                if (l==3)
                    {
                       if (i==0) cout<<" ";
                       if (s[i] == '7' || s[i] == '0' || s[i] == '1') {for (int q=1;q<=k;q++) cout<<" "; cout<<"   ";}
                       else {for (int q=1;q<=k;q++) cout<<"-"; cout<< "   ";}
                    }
                if (l==4)
                    {
                        if (s[i] == '4' || s[i] == '3' || s[i] == '7' || s[i] == '9' || s[i] == '5' || s[i] == '1')
                        { cout<<" "; for (int q=1;q<=k;q++) cout<<" "; cout<<"| "; }
                        else if (s[i] == '2')
                        { cout<<"|"; for (int q=1;q<=k;q++) cout<<" "; cout<<"  "; }
                        else 
                        { cout<<"|"; for (int q=1;q<=k;q++) cout<<" "; cout<<"| "; }
                    }
                if (l==5)
                    {
                        if (i==0) cout<<" ";
                        if (s[i]!='4' && s[i]!='1' && s[i]!='7') {for (int i=1;i<=k;i++) cout<<"-"; cout<<"   "; }
                        else {for (int q=1;q<=k;q++) cout<<" "; cout<<"   ";}
                    }
            }
           cout<<endl;
        }
    }
}
