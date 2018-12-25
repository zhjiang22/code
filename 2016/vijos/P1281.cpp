/*
先取的人如果取了偶数位的数，则下面的人就只能取奇数位的了。
反之，如果先取者取了奇数位的数，则后面的人就只能取偶数位的了。
所以先取者只要比较一下奇数位和还有偶数位和的大小，就能左右比赛了。
因为他们智商好高啊，所以就是
谁先取谁赢,水题啊
所以我得告诉你
cin cout太慢啦
加个ios::sync_with_stdio(false)吧
*/
#include <iostream>
#include <cstdio>
using namespace std;  

char name[][10] = { "wind", "lolanv" };
int t;

int main()
{ 
    ios::sync_with_stdio(false);
    cin >> t;
    int size, who;
    while (t--)
    {
        cin >> size >> who;
        int k;
        for (int i = 0; i < size; i++)
             cin>>k;
        cout << name[who] << endl;
    }
    return 0;
}