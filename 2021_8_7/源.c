#define _CRT_SECURE_NO_WARNINGS 1

//leetcod - 125. 验证回文串
bool isPalindrome(char* s) {
    int len = strlen(s);
    char* str = (char*)malloc(sizeof(char) * (len + 1));
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if ((s[i] >= '0' && s[i] <= '9'))
        {
            str[j++] = s[i];
        }
        else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                str[j++] = s[i] + ('a' - 'A');
            }
            else
            {
                str[j++] = s[i];
            }
        }
    }

    str[j] = '\0';
    // printf("%s\n",str);
    int left = 0;
    int right = j - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}