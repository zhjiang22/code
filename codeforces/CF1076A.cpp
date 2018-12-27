#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
char a[MAXN];
int n;

void init(){
    cin>>n;
    scanf("%s",a);
}

void work(){
    int cur=-1;
    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
        {
            cur=i;
            break;
        }
    if(cur==-1)  cur=n-1;
    for(int i=0;i<n;i++)
        if(i!=cur)
            putchar(a[i]);
    putchar('\n');
}

int main(){
    init();
    work();
    return 0;
}
     