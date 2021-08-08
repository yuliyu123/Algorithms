// 给定一个节点，删除该链表节点。链表没有头指针
// A->B->C->D, delete B
// 要删除B，只需要删除C。删除C前将C的next即为D赋值为B->next，再将C的数据赋给B. 再删除C。狸猫换太子

void delNode(Node* pCur)
{
	if (!pCur) return;
	pNext = pCur->pNext;
	if (!pNext) return;
	pCur->data = pNext->data;
	pCur->next = pNext->next;
	delete pNext;
}

// complete version
#include <stdio.h>
#include <stdlib.h>

typedef struct  LNode
{
	int data;
	LNode *next;
}LNode,*LinkList;

//creat a LinkList with head
bool creatLinklist(LinkList&L, int n)
{
	LinkList p,q;
	L=(LNode*)malloc(n*sizeof(LNode));
	if(!L)
		return false;
	q=L;
	for(int i=1;i<=n;i++)
	{
		p=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		L->next=p;
		L=L->next;
	}
	p->next=NULL;
	L=q;
	return true;
}

//delete a Node in a single/forward Linklist
bool LinklistDelete(LinkList &p)
{
	if (!p) return false;
	LinkList q = p->next;
	if (!q) return false;

	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}

int main()
{
	LinkList Llist,p,t;
	int k;
	int len;
	int elemet;
	int position;
	printf("input the number of LinkList to be created: ");
	scanf("%d",&k);
	creatLinklist(Llist, k);
	printf("\n");
	t=Llist;
	for(int i=0;i<k-4;i++)
		t=t->next;// random a Node
	LinklistDelete(t);
	printf("output the new LinkList:\n");
	p=Llist->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	free(Llist);
}

