//ÌÞ³ý¶àÓàÀ¨ºÅ-¶þ·Ö·¨ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[1024];//a,sÁ½Êý×éÔªËØÒ»Ò»¶ÔÓ¦£¬a[i]±ê¼Çs[i]ÊÇ·ñ¶àÓà 
char s[1024];

int cal(int begin, int end, int prev_min)
{
  int t, min=4, min_i;
  for (int i=begin; i<=end; i++)//É¨ÃèÕû¸ö×Ö·û´®,ÕÒ³ö×îµÍÔËËã·û 
  {
    switch (s[i])
    {
      case '^':
		if (min>3) 
          min=3, min_i=i;//±ê¼Ç"^"ÔËËã·ûÓÅÏÈ¼¶Îª3 
        break;
      case '*': 
      case '/':
		if (min>2) 
          min=2, min_i=i;//±ê¼Ç"*"ºÍ"/"ÔËËã·ûÓÅÏÈ¼¶Îª2 
		break;
      case '+': 
      case '-':
	    if (min>1) 
          min=1, min_i=i;//±ê¼Ç"+"ºÍ"-"ÔËËã·ûÓÅÏÈ¼¶Îª1 
		break;
      case '('://Óöµ½×óÀ¨ºÅ£¬ÔòÕÒµ½ÓëÖ®Æ¥ÅäµÄÓÒÀ¨ºÅ£¬²¢Ìø¹ýÀ¨ºÅÄÚµÄ×Ö·û 
		i++;
		for (t=1;t!=0;i++)
		{
		  if (s[i]=='(') //¶ÔÀ¨ºÅÄÚ¶àÖØ×óÀ¨ºÅºÍÓÒÀ¨ºÅµÄ´¦Àí 
            t++;
		  if (s[i]==')') 
            t--;
		}
		i--;
		break;
    };
  }

  if (min==4)//È¥À¨ºÅ²Ù×÷ 
  {
     if (s[begin]=='(' && s[end]==')')//Èç¹ûÊ×Î²¼´ÎªÀ¨ºÅ 
     {
        t=cal(begin+1,end-1,0);//Çó³ö³ýÈ¥Ê×Î²À¨ºÅ¼ÌÐøµÝ¹éµÄ·µ»ØÖµmin 
        if (t>=prev_min)
        {
          a[begin]=a[end]=1;//½«Ê×Î²µÄÀ¨ºÅ±ê¼ÇÎª¶àÓà 
          return t;
        }
     }
     return 4;
  }

  cal(begin,min_i-1,min);//µÝ¹é×îµÍÔËËã·ûÇ°¶ËµÄÊ½×Ó 
  if (s[min_i]=='+' || s[min_i]=='*')
    cal(min_i+1,end,min);//µÝ¹é×îµÍÔËËã·ûºó¶ËµÄÊ½×Ó 
  else
    cal(min_i+1,end,min+1);//µÝ¹é×îµÍÈ¥´¦·ûºó¶ËµÄÊ½×Ó£¬µ«ÔËËãÓÅÏÈ¼¶+1 
  return min;
}

int main()
{
  cin>>s;
  int sc=strlen(s);
  cal(0,sc-1,0);
  for (int i=0;i<sc;i++) 
    if (!a[i])//µ±Ç°Î»±ê¼ÇÎª0£¬ÔòÊä³ö 
      cout<<s[i];   
  cout<<'\n';
  return 0;
}
