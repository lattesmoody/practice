#include <iostream>
using namespace std;

int main()
{
    int p,k;
    cin >> p >> k;
    // p가 k보다 큰 경우
    if (p > k){
        cout << p - k + 1;
    }
    // p가 k보다 같거나 작은 경우 에) 100, 123
    else{
        cout << p - k + 1001;
    }
    
    return 0;
}