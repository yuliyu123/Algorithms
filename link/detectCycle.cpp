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
        if (!head) return nullptr;
        
        auto slow = head;
        auto fast = head;
        
        while (fast && fast->next)  // fast->next可能是空指针，那么fast->next->next会挂掉
        {
            slow  = slow->next;
            fast  = fast->next->next;
            
            // 相交点一定在环上面，此让从头来的新节点与slow节点第一次相交的地方就是环的入口
            if (slow == fast)
            {
                auto newSlow = head;
                while (newSlow != slow)
                {
                    newSlow = newSlow->next;
                    slow = slow->next;
                }
                return newSlow;
            }
        }
        return nullptr;
    }
};
