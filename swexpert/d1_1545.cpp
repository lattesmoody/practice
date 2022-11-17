#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a ;
    for (int i = a ; a >= 0; i--){
        cout << a;
        a--;
    }
    return 0;
}