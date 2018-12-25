#include<stdio.h>
char a[100][5];
int main()
{
int i,a=0,b=0,x,y,j=1,n;
scanf("%d",&n);
while(scanf("%c %c",&x,&y)==2&&j<=n)
{
if(x==y);
if(x=='S'&&y=='J') a++;
if(x=='S'&&y=='B') b++;
if(x=='J'&&y=='B') a++;
if(x=='J'&&y=='S') b++;
if(x=='B'&&y=='S') a++;
if(x=='B'&&y=='J') b++;
j++;
}
if(a>b)
printf("ry");
else
printf("RY");
return 0;
}