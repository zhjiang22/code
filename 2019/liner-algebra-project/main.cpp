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
    cout << det(a) << endl;
    return 0;
}