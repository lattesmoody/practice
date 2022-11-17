#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i <= T; i++)
    {
        int b = pow(2,i);
        cout << b << " ";
    }
    return 0;
}