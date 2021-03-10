//链表是否有环：快慢指针的思想。
//当慢指针走的时候，如果链表有环，则快指针一定会与慢指针相遇。
//
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
    bool hasCycle(ListNode *head) {
        auto walker = head;
        auto runner = head;

        while (runner && runner->next) // runner->next可能是空指针，那么runner->next->next会挂掉
        {
            walker = walker->next;
            runner = runner->next->next;

            if (walker == runner)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
​// 空间复杂度O(1), head充当慢节点，只有一个runner新节点
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        auto runner = head;
        while (runner && runner->next)
        {
            head = head->next;
            runner = runner->next->next;
            if (head == runner)
            {
                return true;
            }
        }
        return false;
    }
};

