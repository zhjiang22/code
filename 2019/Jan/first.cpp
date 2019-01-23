#include <bits/stdc++.h>
using namespace std;

int k;

int main() {
    int n;
    int a[10000];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
    return 0;
}