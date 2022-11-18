#include <iostream>
#include <cstring>
// ASCII 참조 사이트: https://maincodes.tistory.com/68

using namespace std;

// 알파벳 대문자    65 ~ 90

int main()
{
    char t[200];
    cin >> t;
    for (int i = 0; i < strlen(t); i++)
    {
        printf("%d ", t[i]-64);
    }
    return 0;
}