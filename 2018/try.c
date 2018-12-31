#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(long long n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n%i == 0) {    //能被2到把自身小1的数整除的都不是素数
            return false;
        }
    }
    return true;
}

int  getPrimePair(long long n) {
    if ((n %2== 0) && (n < 2)) {    //不符合题目输入要求返回0，表示失败
        return 0;
    }
    for (int i = 2; i < n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << n << " = " << i << " + " << n - i << endl;
            return 1;
        }
    }
    return 1;    //返回1表示成功
}

int main(int argc, char *argv[]) {
    getPrimePair(2000000000);
    getchar();
    return 0;
}
