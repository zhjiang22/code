#include <algorithm>
/*
这种题果断崩溃了
不想多说什么
心好痛
*/
#include <iostream>
using namespace std;

char map[401][401];
int cnt[51][51];

inline void draw(int x,int y) 
{
    map[x+2][y+0] = '+';    map[x+3][y+0] = '-';   
    map[x+4][y+0] = '-';    map[x+5][y+0] = '-';
    map[x+6][y+0] = '+';    map[x+1][y+1] = '/';
    map[x+2][y+1] = ' ';    map[x+3][y+1] = ' ';
    map[x+4][y+1] = ' ';    map[x+5][y+1] = '/';
    map[x+6][y+1] = '|';    map[x+0][y+2] = '+';
    map[x+1][y+2] = '-';    map[x+2][y+2] = '-';
    map[x+3][y+2] = '-';    map[x+4][y+2] = '+';
    map[x+5][y+2] = ' ';    map[x+6][y+2] = '|';
    map[x+0][y+3] = '|';    map[x+1][y+3] = ' ';
    map[x+2][y+3] = ' ';    map[x+3][y+3] = ' ';
    map[x+4][y+3] = '|';    map[x+5][y+3] = ' ';
    map[x+6][y+3] = '+';    map[x+0][y+4] = '|';
    map[x+1][y+4] = ' ';    map[x+2][y+4] = ' ';
    map[x+3][y+4] = ' ';    map[x+4][y+4] = '|';
    map[x+5][y+4] = '/';    map[x+0][y+5] = '+';
    map[x+1][y+5] = '-';    map[x+2][y+5] = '-';
    map[x+3][y+5] = '-';    map[x+4][y+5] = '+';}
int main() {
  ios :: sync_with_stdio(false);
  int n,m;
  cin >> m >> n;
  int y = 0;
  int x = n*4+m*2+1;
  for (int i = 1;i <= 400;i++)
    for (int j = 1;j <= 400;j++) map[i][j] = '.';
  for (int i = 1;i <= m;i++)
    for (int j = 1;j <= n;j++) {
      cin >> cnt[i][j];
      y = max(y,(m-i+1)*2+cnt[i][j]*3+1);
    }
  for (int i = 1;i <= m;i++)
    for (int j = 1;j <= n;j++)
      for (int k = 1;k <= cnt[i][j];k++)
        draw((j-1)*4+(m-i)*2+1,y-(3*k+(m-i+1)*2));
  for (int i = 1;i <= y;i++) {
    for (int j = 1;j <= x;j++)
      cout << map[j][i];
    cout << '\n';
  }
  return 0;
}