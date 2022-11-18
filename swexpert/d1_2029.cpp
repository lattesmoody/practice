#include <iostream>
using namespace std;

int main()
{
    int t;
    int a, b;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int c, d;
        cin >> a >> b;
        c = a / b;
        d = a % b;
        cout << "#" << i << " " << c << " " << d << "\n";
    }
    return 0;
}