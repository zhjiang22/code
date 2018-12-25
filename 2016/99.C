#include<stdio.h>
#include<string.h>
int main()
{
char a[100];
int i,j,ok=0;
gets(a);
for(i=0;i<strlen(a);i++)
{
if(a[i]=='"'&&!ok)
{
printf("``");
ok=!ok;
continue;
}
if(a[i]=='"'&&ok)
{
printf("''");
ok=!ok;
}
else
printf("%c",a[i]);
}
return 0;
}