#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

struct node
{
	int x,y;
	node(int x=0,int y=0) {this->x=x,this->y=y;}
};

node operator +(const node&a,const node&b)
{
	return node(a.x+b.x,a.y+b.y);
}

ostream& operator << (ostream &out,const node &a)
{
	out<<"("<<a.x<<","<<a.y<<")";
	return out;
}

int main()
{
	 node a(1,2),b(3,4),c;
	 cout<<c<<endl;
	 cout<<a+b<<endl;
	 return 0;
}
     