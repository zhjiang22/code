#include <bits/stdc++.h>
#include "algebra.h"
#include "work.h"
using namespace std;

int main() {
    mtx a, b;
    cin >> a.row >> a.col;
    for (int i = 1; i <= a.row; i++)
        for (int j = 1; j <= a.col; j++)
            cin >> a.data[i][j];
    b = inv(a);
    for (int i = 1; i <= b.row; i++)
        for (int j = 1; j <= b.col; j++)
            printf("%f%c", b.data[i][j], " \n"[j == b.col]);
    vector<double> v = ct_value(a);
    int l = v.size();
    printf("%d\n",l);
    for (int i = 0; i < l; i++)
        printf("%f%c", v[i], " \n"[i == l - 1]);
    return 0;
}
