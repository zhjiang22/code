//输出卡特兰数   
    //首先需要肯定，程序是正确的   
    //这算是大数乘除法！记住他们是如何处理的！由于数据很大，用基本数据类型根本无法满足要求，只能用数组来表示！  
    #include <iostream>  
    #include<cstdio>  
    #include<memory.h>  
    using namespace std;  
    #define MAX 101  
    #define BASE 10000//base只是一个基度，对最终取值并没有影响，相反，base取值愈大，计算量愈小  
    //base发生改变的时候，下面的输出也要相应地做出调整，否则也会输出错误答案！除非当base取10！  
    void multiply(int a[],int len,int b)//乘法   
    {  
        for(int i=len-1,carry=0;i>=0;--i)//从最后一位开始相乘,依次向前与每一位相乘   
        {//问题在于，为什么BASE=10000？   
            carry+=b*a[i];  
            a[i]=carry%BASE;  
            carry/=BASE;  
        //cout<<"carry="<<carry<<" "<<"a["<<i<<"]="<<a[i]<<endl;//以4个0为一组  
        }   
    }  
    void divide(int a[],int len,int b)//除法，很妙的！这种除法可能想不到，仔细体会！   
    {//应当如何除呢？  
        for(int i=0,div=0;i<len;++i)//从高位除起  
        {  
            div=div*BASE+a[i];  
            a[i]=div/b;//b为除数  
            div%=b;  
        }  
    }  
    int main()  
    {  
        int i,j,h[101][MAX];  
        memset(h[1],0,MAX*sizeof(int));//赋值，每一个都置为0   
        for(i=2,h[1][MAX-1]=1;i<=100;++i)//运用递归，并且h[1]=1;   
        {  
            memcpy(h[i],h[i-1],MAX*sizeof(int));//h[i]=h[i-1];按字节拷贝，保证了h[i]和h[i-1]指向数组的一致性   
            multiply(h[i],MAX,4*i-2);//h[i]*=(4*i-2);  
            divide(h[i],MAX,i+1);//h[i]/=(i+1);          
        }//递归得到前100项的卡特兰数！  
        while(cin>>i && i>=1 && i<=100)//输入i的值   
        {  
                    // for(i=1;i<=100;i++)  
                    // {  
            for(j=0;j<MAX && h[i][j]==0;++j);//从0位开始搜索，找到不为0的第一个数   
            //printf("%d\n",EOF);在c语言中，EOF=-1；  
            printf("%d",h[i][j++]);//像是这个输出，就很妙了，第一位可能不足四位，就地输出！  
                  for(;j<MAX;++j)  
            {  
            //  if(h[i][j]==0)  
            printf("%04d",h[i][j]);//处在中间的值也可能没有四位，这时候要注意了，往左边加0，凑足4位，不然答案会出错！  
                //  else  
             // printf("%d",h[i][j]);//不断输出值   
              
           }  
          
            printf("\n");  
        }  
        system("pause");  
          
        return 0;  
    }