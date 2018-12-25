#include<iostream>
using namespace std;
int mingb(int x,int y)
{
	int mo,temp;
	int u=x,i=y;
	if(x<y){temp=x;x=y;y=temp;}
	while(mo!=0)
	{
		mo=x%y;
		x=y;
		y=mo;
	}
	return ((u*i)/x);
}
int maxgy(int x,int y)
{
	int mo,temp;
	if(x<y){temp=x;x=y;y=temp;}
	while(y!=0)
	{
		mo=x%y;
		x=y;
		y=mo;
	}
	return x;
}

int main()
{
	int a,b,c,d;
	int gb,gy;
	int T,ans;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>a>>b>>c>>d;
		gb=mingb(a,c);//q
		gy=maxgy(b,d);//p
		
		int k=maxgy(gb,gy);//d
		if(k==gy)cout<<gb/k<<endl;
		else cout<<gb/k<<"/"<<gy/k<<endl;
	}
	return 0;
} 