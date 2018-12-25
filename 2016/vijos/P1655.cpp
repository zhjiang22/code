/*
这种题目随便乱搞就行了
我发个别人的题解叭
写了一下证明 觉得还是蛮清晰的QAQ
-Proof:
我们先证明 当有 起初态任意一个为 1 4 5 先手必胜
先手：x,1——取x——>胜
先手：x,4——取x——>后手：2,2（只能取2...）——>先手：1,1——>胜
先手：x,5——取x——>后手：2,3（剩下2的上面讨论了..于是取2剩下3）
——>先手：1,2——>胜
对于任意一个数 x ≡ 2 or 3 （mod 5） 我们将他拆成两个数 a b 那么我们可以断定 a 和 b其中一定有一个 mod 5 ≠ 2 or 3
然而对于任意一个 x ≡ 0 or 1 or 4 我们都可以拆成两个数 且都满足 mod 5余 2 or 3 然后这样就必胜态一直可以是自己保持着必胜态 然后数会一直减小 所以最后回到了我们最早的证明
end-
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
char s1[10003],s2[10003];
 
int main()
{
    while(1)
    {
        scanf("%s",s1);
        if(s1[0]=='-')return 0;
        scanf("%s",s2);
        int a=s1[strlen(s1)-1]-'0',b=s2[strlen(s2)-1]-'0';
        a%=5;b%=5;
        if((a==2||a==3)&&(b==2||b==3))
            printf("SheepDaddy\n");
        else 
            printf("MengMeng\n");
    }
    return 0;
}