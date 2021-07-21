#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//leetcode - 344. ��ת�ַ���
//void reverseString(char* s, int sSize) {
//    int left = 0;
//    int right = sSize - 1;
//    int temp = 0;
//    while (left < right)
//    {
//        temp = s[left];
//        s[left] = s[right];
//        s[right] = temp;
//        left++;
//        right--;
//    }
//}

//��ָ Offer 52. ��������ĵ�һ�������ڵ�
//typedef struct ListNode Node;
//
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    if (headA == NULL || headB == NULL)
//    {
//        return NULL;
//    }
//    Node* curA = headA;
//    Node* curB = headB;
//    while (curA != curB)
//    {
//        if (!curA)
//        {
//            curA = headB;
//        }
//        else
//        {
//            curA = curA->next;
//        }
//
//        if (!curB)
//        {
//            curB = headA;
//        }
//        else
//        {
//            curB = curB->next;
//        }
//
//    }
//
//    return curB;
//}

//��ָ Offer 05. �滻�ո�
//char* replaceSpace(char* s) {
//    //������������
//    int spaceCount = 0;
//    int i = 0;
//    while (s[i] != '\0')
//    {
//        if (s[i] == ' ')
//        {
//            spaceCount++;
//        }
//        i++;
//    }
//    char* str = (char*)malloc(strlen(s) + 1 + 2 * spaceCount);
//    if (str == NULL)
//    {
//        printf("mallocʧ��\n");
//        exit(-1);
//    }
//    i = 0;
//    int j = i;
//    while (s[j] != '\0')
//    {
//        if (s[j] == ' ')
//        {
//            str[i++] = '%';
//            str[i++] = '2';
//            str[i] = '0';
//        }
//        else
//        {
//            str[i] = s[j];
//        }
//        i++;
//        j++;
//    }
//    str[i] = '\0';
//    return str;
//}

//leetcode - 151. ��ת�ַ�����ĵ���
//char* reverseWords(char* s) {
//    int i = 0;
//    while (s[i] != '\0')
//    {
//        if (s[i] == ' ')
//        {
//            i++;
//            while (s[i] == ' ')
//            {
//                //cover
//                int j = i + 1;
//                while (s[j] != '\0')
//                {
//                    s[j - 1] = s[j];
//                    j++;
//                }
//                //�ֶ���'\0'
//                s[j - 1] = s[j];
//            }
//        }
//        else
//        {
//            i++;
//        }
//    }
//
//
//    i = 0;
//    while (s[i] == ' ')
//    {
//        int j = i + 1;
//        while (s[j] != '\0')
//        {
//            s[j - 1] = s[j];
//            j++;
//        }
//        s[j - 1] = s[j];
//    }
//
//    //reverse
//    int len = strlen(s);
//    int left = 0;
//    int right = len - 1;
//    while (left < right)
//    {
//        int temp = s[left];
//        s[left] = s[right];
//        s[right] = temp;
//        left++;
//        right--;
//    }
//
//    i = 0;
//    while (s[i] == ' ')
//    {
//        int j = i + 1;
//        while (s[j] != '\0')
//        {
//            s[j - 1] = s[j];
//            j++;
//        }
//        s[j - 1] = s[j];
//    }
//
//    i = 0;
//    int j = 0;
//    while (s[j] != '\0')
//    {
//        while (s[j] != '\0' && s[j] != ' ')
//        {
//            j++;
//        }
//        left = i;
//        right = j - 1;
//        while (left < right)
//        {
//            int temp = s[left];
//            s[left] = s[right];
//            s[right] = temp;
//            left++;
//            right--;
//        }
//        if (s[j] != '\0')
//        {
//            j++;
//            i = j;
//        }
//    }
//
//    return s;
//}