#include<iostream>
#include<queue>
using namespace std;

queue<int> ooo;

int main()
{
	int n,x,y;
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x==1)
		{
			cin>>y;
			ooo.push(y);
		}
		if(x==2)
		{
			if(ooo.empty())
			{
			cout<<"impossible!";
			return 0;
			}
			else
			ooo.pop();
		}
	}
	if(ooo.empty())
	cout<<"impossible!";
	else
	cout<<ooo.front();
	return 0;
}