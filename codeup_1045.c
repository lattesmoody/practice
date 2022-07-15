#include <stdio.h>

int main(){
    int a,b;
    float c;

    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    printf("%d\n", a / b);
    printf("%d\n", a % b);
    printf("%.2f\n", (float)a / b);

    return 0;
}