#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int sum = 0;
        while (sum != num)
        {
            if (sum + 1000 <= num)
            {
                sum += 1000;
                res += 'M';
            }
            else if (sum + 900 <= num)
            {
                sum += 900;
                res += 'C';
                res += 'M';
            }
            else if (sum + 500 <= num)
            {
                sum += 500;
                res += 'D';
            }
            else if (sum + 400 <= num)
            {
                sum += 400;
                res += 'C';
                res += 'D';
            }
            else if (sum + 100 <= num)
            {
                sum += 100;
                res += 'C';
            }
            else if (sum + 90 <= num)
            {
                sum += 90;
                res += 'X';
                res += 'C';
            }
            else if (sum + 50 <= num)
            {
                sum += 50;
                res += 'L';
            }
            else if (sum + 40 <= num)
            {
                sum += 40;
                res += 'X';
                res += 'L';
            }
            else if (sum + 10 <= num)
            {
                sum += 10;
                res += 'X';
            }
            else if (sum + 9 <= num)
            {
                sum += 9;
                res += 'I';
                res += 'X';
            }
            else if (sum + 5 <= num)
            {
                sum += 5;
                res += 'V';
            }
            else if (sum + 4 <= num)
            {
                sum += 4;
                res += 'I';
                res += 'V';
            }
            else
            {
                sum += 1;
                res += 'I';
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    while (1)
    {
        system("cls");
        int n = 0;
        cout << "请输入数字:>";
        cin >> n;
        string str = s.intToRoman(n);
        cout << "该数字转换成罗马数字为：" << str << endl;
        system("pause");
    }

    return 0;
}