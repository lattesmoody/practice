#include <iostream>

using namespace std;

int main()
{
    int check = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (check == j && check == i)
            {
                printf("#");
                check++;
            }
            else
            {
                printf("+");
            }
        } 
        printf("\n");
    }
}