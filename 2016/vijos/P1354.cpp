/*
直接高精度啊
2^n+1-2
懒得写了直接抄
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  ios :: sync_with_stdio(false);
  int n,len = 1,num[101];
  fill(num+1,num+100+1,0);
  num[1] = 1;
  len = 2;
  cin >> n;
  n++;
  while (n--) {
    for (int i = 1;i <= len;i++) num[i] *= 2;
    for (int i = 1;i <= len;i++)
      if (num[i] >= 10) {
        num[i+1] += num[i]/10;
        num[i] %= 10;
      }
    if(num[len] != 0) len++;
  }
  num[1] -= 2;
  for (int i = 1;i < len;i++) {
    if (num[i] < 0) {
      num[i+1] -= 10;
      num[i] += 10;
    }
  }
  if (num[len] < 0) len--;
  for (int i = len-1;i >= 1;i--) cout << num[i];
  return 0;
}