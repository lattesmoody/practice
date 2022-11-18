#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int count;
    string t;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> count;

    for (int i = 1; i <= count; i++)
    {
        // 현재 case 번호 출력
        string number = to_string(i);
        cin >> t;

        // 0000년도 방지
        string tYear = t.substr(0, 4);
        string tMonth = t.substr(4, 2);
        string tDay = t.substr(6, 2);

        int year = stoi(tYear);
        int month = stoi(tMonth);
        int day = stoi(tDay);

        if (year == 0 || month > 12 || month == 0 || day > days[month - 1] || day == 0)
        {
            printf("#%d %d\n", i, -1);
        }
        else
        {
            string result = "#" + number + " " + tYear + "/" + tMonth + "/" + tDay;
            cout << result << endl;
        }
    }
    return 0;
}