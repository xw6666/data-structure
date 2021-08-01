#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 13. 罗马数字转整数
int symbol(char ch)
{
    if (ch == 'I')
    {
        return 1;
    }
    else if (ch == 'V')
    {
        return 5;
    }
    else if (ch == 'X')
    {
        return 10;
    }
    else if (ch == 'L')
    {
        return 50;
    }
    else if (ch == 'C')
    {
        return 100;
    }
    else if (ch == 'D')
    {
        return 500;
    }
    else if (ch == 'M')
    {
        return 1000;
    }
    else
    {
        return -1;
    }
}

int romanToInt(char* s) {
    int len = strlen(s);
    int ret = 0;
    int i = 0;
    for (i = 0; i < len - 1; i++)
    {
        if (symbol(s[i]) >= symbol(s[i + 1]))
        {
            ret = ret + symbol(s[i]);
        }
        else
        {
            ret = ret + symbol(s[i + 1]) - symbol(s[i]);
            i++;
        }
    }
    if (i == len - 1)
    {
        ret = ret + symbol(s[len - 1]);
    }

    return ret;
}