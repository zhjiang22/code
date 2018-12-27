#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e6;
short a[MAXN];
int n,k;

void quick_select(int l, int r, int k) {
    if(l == r && k == r) {
        printf("%hd\n",a[l]);
        return;
    }
    if(l == r)  return;
    int pos = a[(l + r) >> 1];
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[i] <= pos) i++;
        while(i < j && a[j] > pos)  j--;
        swap(a[i],a[j]);
    }
    if(a[i] > pos)  i--;
    if(a[j] <= pos) j++;
    if(i >= k)  quick_select(l, i , k);
    else    quick_select(j, r, k);
}

void init() {
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        scanf("%hd",&a[i]);
}

void work() {
    quick_select(1,n,k);
}

int main() {
    init();
    work();
    return 0;
}
