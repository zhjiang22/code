/*
这是一道DP题。。。
因为数据太弱的原因，所以PRIM的算法能通过，但其实他是不对的。。。
还有一种有反例的做法就是周长减去最长边
正确的方法是DP！。
题意：给你一个凸包，问遍历所有点一遍的最短路径
这题首先有一个推论，就是最短路径肯定是没有相交的边，所以只可能是一条一条边的向左或者向右拓展
dp[i][j][0] 表示遍历从第i个点开始的j+1个点最后落在第i个点的最短距离
dp[i][j][1]	表示遍历从第i个点开始的j+1个点最后落在第i+j个点的最短距离
dp[i][j][0] = min( dp[(i+1)%N][j-1][1] + calc_dis( i, ( i + j ) % N ), dp[(i+1)%N][j-1][0] + calc_dis( i, ( i + 1 ) % N ) );  
dp[i][j][1] = min( dp[i][j-1][1] + calc_dis( ( i + j - 1 ) % N, ( i + j ) % N ), dp[i][j-1][0] + calc_dis( i, ( i + j ) % N ) );
*/
#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
  
#define MAX 0x3f3f3f3f  
  
struct Node
{  
    double x, y;  
};  
  
double dp[810][810][2];  
Node node[810];  
int N;  
  
double calc_dis( int i, int j )
{  
    return sqrt( ( node[i].x - node[j].x ) * ( node[i].x - node[j].x ) + ( node[i].y - node[j].y ) * ( node[i].y - node[j].y ) );  
}  
  
int main()
{  
    while( scanf( "%d", &N ) != EOF )
    {  
        for( int i = 0; i < N; i++ )
        {  
            scanf( "%lf%lf", &node[i].x, &node[i].y );  
        }  
        for( int i = 0; i < N; i++ )
        {  
            dp[i][0][0] = dp[i][0][1] = 0;  
        }  
        for( int j = 1; j < N; j++ )
        {//注意顺序首先是长度  
            for( int i = 0; i < N; i++ )
            {  
                dp[i][j][0] = min( dp[(i+1)%N][j-1][1] + calc_dis( i, ( i + j ) % N ), dp[(i+1)%N][j-1][0] + calc_dis( i, ( i + 1 ) % N ) );  
                dp[i][j][1] = min( dp[i][j-1][1] + calc_dis( ( i + j - 1 ) % N, ( i + j ) % N ), dp[i][j-1][0] + calc_dis( i, ( i + j ) % N ) );  
            }  
        }  
        double ans = 100000000000;  
        for( int i = 0; i < N; i++ )
        {  
            ans = min( ans, dp[i][N-1][0] );  
            ans = min( ans, dp[i][N-1][1] );  
        }  
        printf( "%.3lf", ans );  
    }  
    return 0;  
}  
