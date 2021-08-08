/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// solution 1
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        
        while (p1)
        {
            ListNode* p2 = pHead2;
            while (p2)
            {
                if (&(*p1)== &(*p2))
                {
                    return p1;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        return nullptr;
    }
};


// solution2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        auto p1 = headA, p2 = headB;

        // m == n, 同时移动到尾指针；m!=n, p1走完链表1, 走链表2, p2也是。都走完m+n判断最后是否相交。
        while (p1 != p2) {
            p1 = p1 == nullptr ? headB : p1->next;
            p2 = p2 == nullptr ? headA : p2->next;
        }

        return p1;
    }
};
