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

        while (runner && runner->next)
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
