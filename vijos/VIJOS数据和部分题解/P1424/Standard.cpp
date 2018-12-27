#include<fstream>
using namespace std;
ifstream fin("cannon.in");
ofstream fout("cannon.out");
int n,m,map[101][11];
int dp[3][1048577],power[11];
bool visit[3][1048577];
int Start,Finish;
void init()
{
     int i,j;
     char x;
     fin>>n>>m;
     for (i=1;i<=n;i++)
       for (j=1;j<=m;j++)
       {
           fin>>x;
           if ( x=='H' )
            map[i][j]=0;
           else
            map[i][j]=1;
       }
     power[0]=1;
     for (i=1;i<=10;i++)
      power[i]=power[i-1]*4;
}
void type(int a[],int code)
{
     int i;
     fout<<code<<endl;
     for (i=1;i<=m;i++)
       fout<<a[i]<<" ";
     fout<<endl;
}
void draw(int a[],int code,int floor)
{
     
     int i;
     for (i=1;i<=m;i++)
      a[i]=0;
     i=m;
     while ( code!=0 )
     {
           a[i]=code%4;
           code=code/4;
           i--;
     }
     for (i=1;i<=m;i++)
       if ( a[i]!=0 )
        a[i]--;
}
int change(int a[])
{
    int i,sum=0;
    for (i=1;i<=m;i++)
      sum=sum*4+a[i];
    return(sum);
}
void possible(int a[],int floor,int k)
{
     int p1,p2,p3,p4,code;
     
     code=change(a);
     visit[2][code]=1;
     if ( dp[2][code]<dp[1][k] )
      dp[2][code]=dp[1][k];
     for (p1=1;p1<=m;p1++)
     {
         if ( map[floor][p1]==1 && a[p1]==0 )
         {
              a[p1]=3;
              //
              code=change(a);
              visit[2][code]=1;
              if ( dp[2][code]<dp[1][k]+1 )
               dp[2][code]=dp[1][k]+1;
              //
              a[p1]=0;
         }
         for (p2=p1+3;p2<=m;p2++)
         {
             if ( map[floor][p1]==1 && map[floor][p2]==1 && a[p1]==0 && a[p2]==0 )
             {
                  a[p1]=3; a[p2]=3;
                  //
                  code=change(a);
                  visit[2][code]=1;
                  if ( dp[2][code]<dp[1][k]+2 )
                   dp[2][code]=dp[1][k]+2;
                  //
                  a[p1]=0; a[p2]=0;
             }
             for (p3=p2+3;p3<=m;p3++)
             {
                 if ( map[floor][p1]==1 && map[floor][p2]==1 && map[floor][p3]==1 && a[p1]==0 && a[p2]==0 && a[p3]==0 )
                 {
                      a[p1]=3; a[p2]=3; a[p3]=3;
                      //
                      code=change(a);
                      visit[2][code]=1;
                      if ( dp[2][code]<dp[1][k]+3 )
                       dp[2][code]=dp[1][k]+3;
                      //
                      a[p1]=0; a[p2]=0; a[p3]=0;
                 }
                 for (p4=p3+3;p4<=m;p4++)
                 {
                     if ( map[floor][p1]==1 && map[floor][p2]==1 && map[floor][p3]==1 && map[floor][p4]==1 && a[p1]==0 && a[p2]==0 && a[p3]==0 && a[p4]==0 )
                     {
                          a[p1]=3; a[p2]=3; a[p3]=3; a[p4]=3;
                          //
                          code=change(a);
                          visit[2][code]=1;
                          if ( dp[2][code]<dp[1][k]+4 )
                           dp[2][code]=dp[1][k]+4;
                          //
                          a[p1]=0; a[p2]=0; a[p3]=0; a[p4]=0;
                     }
                 }
             }
         }
     }
}
void work()
{
     visit[1][0]=1;
     int i,j,plan[11],best=0;
     for (i=1;i<=n;i++)
     {
         for (j=0;j<=power[m];j++)
         {
             if ( visit[1][j]==1 && dp[1][j]+2>=best )
             {
                  draw(plan,j,i);
                  possible(plan,i,j);
                  
             }
         }
         for (j=0;j<=power[m];j++)
         {
             dp[1][j]=dp[2][j];
             visit[1][j]=visit[2][j];
             if ( best<dp[1][j] )
              best=dp[1][j];
         }
     }
     fout<<best;
}
main()
{
      init();
      work();
}
