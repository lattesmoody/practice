#include <stdio.h>
// 정수 2개를 입력받아 합을 출력하는 프로그램을 작성, 입력되는 정수는 -1073741824 ~ 1073741824
int main(){
    long long a, b, c;
    scanf("%lld %lld", &a, &b);
    c = a + b;
    printf("%lld", c);
    return 0;
}