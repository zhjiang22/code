#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

char rd;	int pn;
template<typename Type>
inline void read(Type& v)
{
	pn=1;
	while((rd=getchar())<'0'||rd>'9')
		if(rd=='-')
			pn=-1;
	v=rd-'0';
	while((rd=getchar())>='0'&&rd<='9')
		v=v*10+rd-'0';
	v*=pn;
}
template<typename Type>
inline void out(Type v,bool c=1)
{
	if(v==0)
		putchar(48);
	else  
    {
    	if(v<0)
    	{
    		putchar('-');
    		v=-v;
    	}
    	int len=0,dg[20];  
    	while(v>0)
    	{
    		dg[++len]=v%10;
    		v/=10;
    	}  
    	for(int i=len;i>=1;i--)
    		putchar(dg[i]+48);  
    }
    if(c)
    	putchar('\n');
    else
    	putchar(' ');
}

int n;
string s;
vector<string> words;
map<string,int> c;

string repr(const string& s)
{
	string ans=s;
	int l=ans.length();
	for(int i=0;i<l;i++)
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}

void init()
{
	while(cin>>s)
	{
		if(s[0]=='#')
			break;
		words.push_back(s);
		string r=repr(s);
		if(!c.count(r))
			c[r]=0;
		c[r]++;
	}
}

void work()
{
	vector<string> ans;
	int l1=words.size();
	for(int i=0;i<l1;i++)
		if(c[repr(words[i])]==1)
			ans.push_back(words[i]);
	sort(ans.begin(),ans.end());
	int l2=ans.size();
	for(int i=0;i<l2;i++)
		cout<<ans[i]<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
     