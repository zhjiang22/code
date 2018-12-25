#include<iostream>
#include<string>
#include <cstdlib>
#include<map>
using namespace std;

int main(void)
{
  char a[11],b[11];
  map<string,string>wa;//记录foreign到engliash的映射

  while(true)//输入字典 
  {
    char t;  //临时变量 
    if((t=getchar())=='\n')  //判定是否输入了空行
      break;
    else     //输入english
    {
      a[0]=t;
      int i=1;
      while(true)
      {
    t=getchar();
    if(t==' ')
    {
      a[i]='\0';
      break;
    }
    else
      a[i++]=t;
      }
    }
    cin>>b;
    getchar();  //处理 输入foreign后的 回车符

    wa[b]=a;
  }

  char word[11];
  while(cin>>word)//开始翻译 
  {
    if(wa[word]!="")
      cout<<wa[word]<<endl;
    else
      cout<<"eh"<<endl;
  }
  return 0;
}
