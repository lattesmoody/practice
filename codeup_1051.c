#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d",&a, &b);
    if (b >= a){
        printf("%d", 1);
    }
    else{
        printf("%d" , 0);
    }
    return 0;
}