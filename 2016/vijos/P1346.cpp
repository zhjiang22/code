/*
数学题我从来不擅长http://blog.csdn.net/yyyds/article/details/52214378
*/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#define N 10050

int main()
{
	int pre,x,y,jian,m=1,tempp,tempn,i,k=0,kxy,min,max;
	float umin = -1e9, umax = 1e9;
	int price[N] = {0}, num[N] = {0};
	scanf("%d", &pre);
	scanf("%d%d",&x,&y);
	price[m] = x; num[m] = y;
	scanf("%d""%d",&x,&y);
	while(x!=-1 && y!=-1){
		if(x-price[m] == 1){
			m++;
			price[m] = x;
			num[m] = y;
		}
		else{
			kxy = -(num[m]-y)/(x-price[m]);//kxy为中间每差1元减少的销量
			while(price[m] < x){
				m++;
				price[m] = price[m-1]+1;
				num[m]=num[m-1]+kxy;
			}
		}//中间数据有空缺
		scanf("%d%d",&x,&y);
	}//循环读入数据并补充中间空缺的数据
	scanf("%d",&jian);

	tempn = num[m]; tempp = price[m];
	while(tempn-jian > 0){
		m++;
		tempp++; price[m] = tempp;
		tempn -= jian; num[m] = tempn;
	}//不断增加售价直到销售量为0

	for(i=1; i<=m; i++)
		if(price[i] == pre){
			k = i;
			break;
		}

	if(k == 0){
		printf("NO SOLUTION");
		exit(0);
	}//如果已知价格中没有政府预估价则输出"NO SOLUTION"并退出程序

	for(i = 1; i < k; i++)
		if ((float)((num[k]*(price[k]-price[1])-num[i]*(price[i]-price[1]))/(float)(num[i]-num[k]))<=umax)
           umax=(float)(num[k]*(price[k]-price[1])-num[i]*(price[i]-price[1]))/(float)(num[i]-num[k]);
	//(预估价的总利润-某价位上的总利润)/(某价位销量-预估价销量)=应该收的RMB
	//这个地方不理解的话建议解一下上文列出的不等式
	for(i = k+1; i <= m; i++)
		if ((float)((num[i]*(price[i]-price[1])-num[k]*(price[k]-price[1]))/(float)(num[k]-num[i]))>=umin)
           umin=(float)(num[i]*(price[i]-price[1])-num[k]*(price[k]-price[1]))/(float)(num[k]-num[i]);
	//(某价位上的总利润-预估价的总利润)/(预估价销量-某价位销量)=应该补贴的RMB
	if(umin>umax) printf("NO SOLUTION");//解集为空
	else if(umin > 0){//需要补贴的情况
		if(fabs(umin-(int)(umin))>1e-6) min=(int)(umin)+1;//float存在误差
		else min=(int)(umin);
		printf("%d",min);
	}
	else if(umax < 0){//需要收税的情况
		if(fabs((int)(umax)-umax)>1e-6) max=(int)(umax)-1;//float存在误差
		else max = (int)(umax);
		printf("%d",max);
	}
	else printf("0");//若不需要补贴或收税

	return 0;
}