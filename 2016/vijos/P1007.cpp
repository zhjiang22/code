//ans=点点距之和+圆周
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const float P = 3.1416;
const int N = 105;
struct point{
    float x;
    float y;
    point(){x = y = 0.0;};
    double operator - (const point a){
        return (sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y)));
    }
}A[N];
int n;
float r,len;
int main(){
    scanf("%d%f",&n,&r);
    for(int i = 0;i < n;i++) scanf("%f%f",&A[i].x,&A[i].y);
    len += (A[0] - A[n - 1]);
    for(int i = 1;i < n;i++) len += (A[i] - A[i - 1]);
    len += (P * r * 2.0);
    printf("%.2f\n",len);
    return 0;
}