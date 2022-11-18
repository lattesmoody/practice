#include <iostream>
#include <cstring>

using namespace std;

// 알파벳 대문자 65 ~ 90
// 알파벳 소문자 97 ~ 122
// 대문자 = 소문자 - 32
int main()
{
    char t[80];
    cin >> t;

    for (int i = 0; i <= strlen(t); i++){
        if (t[i] >= 97 && t[i] <= 122){
            t[i] = t[i] - 32;
        }
        cout << t[i];
    }
    

    return 0;
}