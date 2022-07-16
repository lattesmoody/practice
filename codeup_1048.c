#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d", a << b); // a << b => a * 2^b
    return 0;
}