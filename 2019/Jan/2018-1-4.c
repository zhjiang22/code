#include <stdio.h>
#include <stdlib.h>

int n;
int a[100];

void pre_dfs(int x) {
    printf("%d\n", a[x]);
    if (x * 2 <= n)
        pre_dfs(2 * x);
    if (x * 2 <= n)
        pre_dfs(2 * x + 1);
}

void in_dfs(int x) {
    if (x * 2 <= n)
        in_dfs(x * 2);
    printf("%d\n", a[x]);
    if (x * 2 + 1 <= n)
        in_dfs(x * 2 + 1);
}

void post_dfs(int x) {
    if (x * 2 <= n)
        post_dfs(x * 2);
    if (x * 2 + 1 <= n)
        post_dfs(x * 2 + 1);
    printf("%d\n", a[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("Preorder\n");
    pre_dfs(1);
    printf("Inorder\n");
    in_dfs(1);
    printf("Postorder\n");
    post_dfs(1);
    return 0;
}