// 给定一个节点，删除该链表节点。链表没有头指针
// A->B->C->D, delete B
// 要删除B，只需要删除C。删除C前将C的next即为D赋值为B->next，再将C的数据赋给B. 再删除C。狸猫换太子

void delNode(Node* pCur)
{
	if (!pCur) return;
	
	pNext = pCur->pNext;
	pCur->next = pNext->next;
	pCur->data = pNext->data;
	delete pNext;
}
