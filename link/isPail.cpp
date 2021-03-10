/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
/*
判断链表是否为回文链表
*/

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if (!head) return true;
        auto ptr = head;
        stack<int> stk;
        int count = 0;
        while (ptr)
        {
            ++count;
            stk.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (count)
        {
            if (ptr->val != stk.top()) return false;
            stk.pop();
            --count;
            ptr = ptr->next;
        }
        return true;
    }
};
