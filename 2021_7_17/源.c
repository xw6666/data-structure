#define _CRT_SECURE_NO_WARNINGS 1
//leetcode - 14. �����ǰ׺
//char* longestCommonPrefix(char** strs, int strsSize) {
//    int i = 0;
//    int j = 0;
//    while (strs[i][j] != '\0')
//    {
//        for (i = 0; i < strsSize - 1; i++)
//        {
//            if (strs[i][j] != strs[i + 1][j])
//            {
//                break;
//            }
//        }
//        if (i < strsSize - 1)
//        {
//            break;
//        }
//        j++;
//    }
//    char* res = (char*)malloc(sizeof(char) * (j + 1));
//    for (i = 0; i < j; i++)
//    {
//        res[i] = strs[0][i];
//    }
//    res[i] = '\0';
//    return res;
//}

//leetcode - 19. ɾ������ĵ����� N �����
//typedef struct ListNode Node;
//
//struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    Node* newHead = (Node*)malloc(sizeof(Node));
//    newHead->next = head;
//
//    Node* cur = head;
//    Node* prev = newHead;
//    Node* fast = head;
//    while (n--)
//    {
//        //��cur�������
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        prev = cur;
//        cur = cur->next;
//        fast = fast->next;
//    }
//    //ɾ�����cur
//    Node* temp = cur;
//    prev->next = prev->next->next;
//    free(temp);
//    temp = NULL;
//
//    return newHead->next;
//}