#include <stdio.h>
#include <string.h>

char s[1000005];
int ans[10];
int l;

int main() {
    while (fgets(s, 100000, stdin)) {
        l = strlen(s);
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < l; i++)
            if (s[i] <= '9' && s[i] >= '0')
                ans[s[i] - '0']++;
        for (int i = 0; i <= 9; i++)
            if(ans[i])
                printf("%d:%d\n", i, ans[i]);
    }
    return 0;
}