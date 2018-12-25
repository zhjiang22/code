#include<iostream>
#include<stack>
using namespace std;

const int MAXN=1000;

stack<int> x;
char a[36];


int main()
{
    int n,m;
	cin>>n>>m;
	while(n)
	{
		x.push(n%m);
		n/=m;
	} 
	while(!x.empty())
	{
		cout<<x.top();
		x.pop();
	}
	return 0;
}
