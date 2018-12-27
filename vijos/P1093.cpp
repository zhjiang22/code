//斐波那契数列~不解释
#include<cstdio>
using namespace std;
const int st=7654321;
int a[3],n;
int main(){
    scanf("%d",&n);
    a[0]=1;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<n;i++)
        a[i%3]=(a[(i-1)%3]+a[(i-2)%3])%st;
    printf("%d",a[(n-1)%3]);
    return 0;
} 