#include<bits/stdc++.h>
using namespace std;

const int N=11000;
const double eps=(double)1e-6;
struct node{
    double x,y,r;int val;
}c[N];
int n,m,q0[N],ans;

double dist(double x1,double y1,double x2,double y2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool incir(double x,double y,int id)
{
    return dist(x,y,c[id].x,c[id].y) <= c[id].r*c[id].r;
}

bool cmp_c(node t0,node t1){return t0.val>t1.val;}
bool cmp_q(int x,int y){return x>y;}

void solve(double x,double y)
{
	
    int cnt=0;int val=0;
    for(int j=1;j<=n;j++)
    {
       	if(incir(x,y,j) && cnt<m) 
       	{
			val+=c[j].val;
			cnt++;
	   	}
	    if(cnt>=m) break;
    }
    ans=max(ans,val);
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)        
        {
            scanf("%lf%lf%lf%d",&c[i].x,&c[i].y,&c[i].r,&c[i].val);
        }
        sort(c+1,c+1+n,cmp_c);
        ans=0;
		for(int i=1;i<=n;i++) solve(c[i].x,c[i].y);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(dist(c[i].x,c[i].y,c[j].x,c[j].y) >= (c[i].r-c[j].r)*(c[i].r-c[j].r))
                {

                    double a1=c[i].x,b1=c[i].y;
                    double a2=c[j].x,b2=c[j].y;
                    double r1=c[i].r,r2=c[j].r;
                    if(fabs(b1-b2)<eps)//b1==b2
                    {
                    	if(fabs(a1-a2) <= eps) continue;
                        double x=( r2*r2-r1*r1 + a1*a1 - a2*a2 + b1*b1 - b2*b2)/(2*(a1-a2));
                        double A=1;
                        double B=-2*b1;
                    	// if(i==1 && j==4) printf("ok\n");
                        double C=b1*b1 - r1*r1 + x*x - 2*a1*x + a1*a1;
                        double y1 = (-B + sqrt(B*B-4*A*C))/(2*A);
                        solve(x,y1);
                        double y2 = (-B - sqrt(B*B-4*A*C))/(2*A);
                        solve(x,y2);
                    }
                    else //b1!=b2
                    {
                        double k=(a2-a1)/(b1-b2);
                        double b=( r2*r2-r1*r1 + a1*a1 - a2*a2 + b1*b1 - b2*b2)/(2*(b1-b2));
                        double A=1+k*k;
                        double B=2*k*(b-b1)-2*a1;
                        double C=a1*a1 + (b-b1)*(b-b1) - r1*r1;
                        double x1 = (-B + sqrt(B*B-4*A*C))/(2*A);
                        double y1 = k*x1+b;
                        solve(x1,y1);
                        double x2=  (-B - sqrt(B*B-4*A*C))/(2*A);
                        double y2 = k*x2+b;
                        solve(x2,y2);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}