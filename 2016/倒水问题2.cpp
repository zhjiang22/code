#include<iostream>

#include<cstdio>

#include<cstring>

#include<queue>

using namespace std;

int x,y,z,f[101][101],c[4];

struct node

{

int v[4];//3个杯子 

int step;//步数 

};

queue<node>q;

int main()

{

cin>>x>>y>>z;

c[1]=x;c[2]=y;c[3]=201;//三个杯子的最大容积 

node be;

be.step=0;

be.v[1]=0;be.v[2]=0;

be.v[3]=201;

q.push(be);

while(!q.empty())

 {

 	node tmp=q.front();

 	q.pop();

 	if(tmp.v[1]==z||tmp.v[2]==z)//每次去队首元素 判断 

 	 {

 	 	cout<<tmp.step;

 	 	return 0;

 }

 	int i,j;

 	for(i=1;i<=3;i++)//枚举出水的杯子 i

 	 for(j=1;j<=3;j++)//枚举接受倒水的杯子 j

 	   if(!tmp.v[i]||tmp.v[j]==c[j])continue;//如果出水的空了 或者接受倒水的满了 跳过 

 	   else 

 	     {

 	     	int minn=min(tmp.v[i]+tmp.v[j],c[j])-tmp.v[j];//计算到水量 i全倒入 j或者倒满j i不一定倒完 

 	     	node x=tmp;

 	     	x.v[i]-=minn;//出水的- 

 	     	x.v[j]+=minn;//接受倒水的+ 

 	     	x.step=tmp.step+1;//步数++ 

 	     	if(f[x.v[1]][x.v[2]]==0)//是否在q中 

 	     	 {

 	     	 	f[x.v[1]][x.v[2]]=1;

 	     	 	q.push(x);

 }

 }

 }

cout<<"impossible";

return 0;

}

