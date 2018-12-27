#include <stdio.h>
#include <string.h>
int main() 
{
  char s[200];char c[1001];
  char a,b;
  int n;
  //int n; fangzhelixunhuancishuhuishaoa
  scanf("%d",&n);getchar(); 
  for(int i=65;i<=122;i++)
  {
    s[i]=i;
  }
  for(int i=0;i<n;i++)
  {
    scanf("%c %c",&a,&b);//gaicheng "%c"jiu shao le xunhuancishu
    getchar();
    s[b]=a;
  }
  scanf("%s",c);
  for(int i=0;i<strlen(c);i++)
  {
    printf("%c",s[c[i]]);
  }
  printf("\n");
  getchar();  getchar();
  return 0;
}