#include <bits/stdc++.h>
using namespace std;

int getfather(int x) {
    return fa[x] == x ? x : fa[x] == getfather(fa[x]);
}

void init() {
    
}

void work() {

}

int main() {
    init();
    work();
    return 0;
}