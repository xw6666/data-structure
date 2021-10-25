# LeetCode [142. 环形链表 II]

[(https://leetcode-cn.com/problems/linked-list-cycle-ii/)

## 讲解部分

首先使用快慢指针去遍历这个链表，第一个指针叫slow，第二个指针叫fast，他们都从head处开始，fast每次走两个next，slow每次走一个next，如果fast走到了NULL，那么这个链表是一定没有环的，反之，如果fast因为在环中<mark>套圈</mark>，那么当两个指针相遇时，说明了他们套圈了，链表也就有环了，也就是slow == fast时说明链表有环。



下面我们来思考为什么fast比slow走快一个单位一定会追上slow与slow相遇，而不是直接略过slow，。



首先，因为是快走一个单位，那么很好理解，当将超圈的时候，一定会相遇，不会错过。



之后我们找一个规律去找这个环形链表的入环点：

![image-20211025185641737](C:\Users\晓伍\AppData\Roaming\Typora\typora-user-images\image-20211025185641737.png)

如图所示首先假设链表长度为L+C个结点，假设fast指针走了f个结点，slow指针走了s个结点，由于我们知道fast速度是slow的两倍，所以有：

<mark>f = 2s</mark>.........................①

我们再假设现在fast和slow相遇了，证明了有环了，那么fast一定是<mark>套圈</mark>了，于是一定有：

<mark>f  -  2s = nc, (n∈N)</mark>.............................②



之后我们通过①、②可以得到：

<mark>f = 2nc, (n∈N)</mark>........................................③

<mark>s = nc, (n∈N)</mark>..........................................④



现在我们假设有一个结点k从表头走到入环点，那么它走过的结点数为：

<mark>k = L + nc, (n∈N)</mark>...........................................⑤



通过观察④和⑤两个式子，不难得知，<mark>s现在只要再走一个L长度就能到达入环点！</mark>

回到题目中，我们现在虽然不知道这个L有几个结点，但是，我们给出一个k指针从头开始与slow一起一步一步走，当他们相遇时，就到达了入环点。



## 代码部分

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        //首先使用快慢指针检测是否有环
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                break;
            }
        }

        if(fast == NULL || fast->next == NULL)
        {
            return NULL;
        }
        
        //返回入环点
        ListNode* cur = head;
        while(cur != slow)
        {
            cur = cur->next;
            slow = slow->next;
        }

        return  cur;

    }
};
```

