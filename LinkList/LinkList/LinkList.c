#include "LinkList.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void LinkListInitialize(Node **ppNode)
{
	assert(ppNode != NULL);
	(*ppNode) = NULL;
}

void LinkListDestroy(Node **ppNode)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(ppNode != NULL);
	while (cur != NULL) {
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*ppNode = NULL;
}

static Node* CreatNode(DataType d)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	if (NewNode == NULL) {
		perror("error for malloc NewNode");
		exit(EXIT_FAILURE);
	}
	NewNode->data = d;
	NewNode->next = NULL;
	return NewNode;
}

void LinkListPushFront(Node **ppNode, DataType d)
{
	Node *cur = NULL;
	assert(ppNode != NULL);
	cur = *ppNode;
	*ppNode = CreatNode(d);
	(*ppNode)->next = cur;
}

void LinkListPopFront(Node **ppNode)
{
	Node *del = NULL;
	assert(ppNode != NULL);
	if (*ppNode == NULL) {
		return;
	}
	del = *ppNode;
	*ppNode = (*ppNode)->next;
	free(del);
	del = NULL;
}

void LinkListPushBack(Node **ppNode, DataType d)
{
	Node *cur = NULL;
	assert(ppNode != NULL);
	if (*ppNode == NULL) {
		*ppNode = CreatNode(d);
		return;
	}
	cur = *ppNode;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = CreatNode(d);
}

void LinkListPopBack(Node **ppNode)
{
	Node *del = NULL;
	assert(ppNode != NULL);
	if (*ppNode == NULL) {
		return;
	}

	// 1 
	// 1 2 3
	if ((*ppNode)->next == NULL) {
		free(*ppNode);
		*ppNode = NULL;
		return;
	}
	del = *ppNode;
	while (del->next->next != NULL) {
		del = del->next;
	}
	free(del->next);
	del->next = NULL;
}

Node* LinkListFind(const Node *pNode, DataType d)
{
	const Node *cur = NULL;
	cur = pNode;
	while (cur != NULL){
		if (cur->data == d) {
			return (Node *)cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void LinkListInsert(Node **ppNode, Node *pos, DataType d)
{
	Node *NewNode = NULL;
	Node *cur = NULL;
	assert(ppNode != NULL);
	if (*ppNode == pos) {
		LinkListPushFront(ppNode, d);
	}
	cur = *ppNode;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	NewNode = CreatNode(d);
	NewNode->next = cur->next->next;
	cur->next = NewNode;
}

void LinkListNodeRemove(Node **ppNode, DataType d)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(ppNode != NULL);
	cur = *ppNode;
	del = LinkListFind(*ppNode, d);
	if (del == NULL) {
		printf("不存在该节点，删除失败！\n");
		return;
	}
	if (del == *ppNode) {
		*ppNode = (*ppNode)->next;
		free(del);
		del = NULL;
		printf("删除成功！\n");
		return;
	}
	while (cur->next != del)
	{
		cur = cur->next;
	}
	cur->next = del->next;
	free(del);
	del = NULL;
	printf("删除成功！\n");

}

void LinkListNodeRemoveALL(Node **ppNode, DataType d)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(ppNode != NULL);
	cur = *ppNode;
	while (cur != NULL)
	{
		del = cur;
		if (cur->data == d) {
			if (cur == *ppNode) {
				*ppNode = cur->next;
			}
			else {
				del->next = cur->next;
			}
		}
		cur = del->next;
	}
}

void LinkListErase(Node **ppNode, Node *pos)
{
	assert(ppNode != NULL);
	if (*ppNode == NULL) {     //空
		return;
	}
	if (*ppNode == pos) {       //头
		*ppNode = pos->next;
		free(pos);
		pos = NULL;
		return;
	}
	Node *cur = *ppNode;
	while (cur->next != pos) {
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}

void LinkListPrint(const Node *pNode)
{
	const Node *cur = pNode;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ReversePrint(const Node *pNode)
{
	const Node *cur = pNode;
	const Node *end = NULL;
	while (end != pNode) {
		if (cur->next == end) {
			printf("%d ", cur->data);
			end = cur;
			cur = pNode;
		}
		else {
			cur = cur->next;
		}
	}
	printf("\n");
}

void ReversePrintRec(const Node *pNode)
{
	if (pNode == NULL) {
		return;
	}
	ReversePrintRec(pNode->next);
	printf("%d ", pNode->data);
}

void LinkListReverse(Node **ppNode)
{
	//创建一个新的头  给原来的头删    给新的头插
	Node *cur = NULL;
	Node *NewNode = NULL;
	Node *newcur = NULL;
	assert(ppNode != NULL);
	if (*ppNode == NULL || (*ppNode)->next == NULL) {
		return;
	}
	cur = *ppNode;
	while (cur != NULL) {
		newcur = cur;
		cur = cur->next;
		newcur->next = NewNode;
		NewNode = newcur;
	}
	*ppNode = NewNode;
	LinkListPrint(NewNode);
}

void LinkListReverse1(Node **ppNode)
{
	//改变链表的方向
	Node *prev = NULL;
	Node *cur = NULL;
	Node *next = NULL;
	assert(ppNode);
	cur = *ppNode;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*ppNode = prev;
	LinkListPrint(*ppNode);
}

void EraseNode(Node *pos)
{
	Node *cur = NULL;
	assert(pos);
	cur = pos->next;
 	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(cur);
	cur = NULL;
}

void InsertBeforeNode(Node *pos, DataType data)
{
	Node *newnode = NULL;
	assert(pos);
	newnode = CreatNode(data);
	newnode->next = pos->next;
	pos->next = newnode;
	newnode->data = pos->data;
	pos->data = data;
}

Node* JocephCircle(Node *pNode, int k)
{
	Node *cur = pNode;
	Node *prev = NULL;
	if (pNode == NULL) {       //空
		return NULL;
	}
	if (pNode->next == NULL) {          //只有一个
		return pNode;
	}
	while (cur->next != NULL)                  //变成环状
	{
		cur = cur->next;
	}
	cur->next = pNode;

	cur = pNode;
	prev = cur;
	while (cur->next != cur)
	{
		for (int i = 0; i < k - 1; i++) {           //逢k删除
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		free(cur);
		cur = prev->next;
	}
	printf("%d\n", cur->data);
	return cur;
}

void Merge(Node *list1, Node *list2)
{
	Node *cur1 = NULL;
	Node *cur2 = NULL;
	Node *cur3 = NULL;
	Node *nextcur3 = NULL;
	assert(list1 && list2);
	cur1 = list1;
	cur2 = list2;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data <= cur2->data) {
			if (cur3 == NULL) {
				cur3 = cur1;
			}
			else {
				nextcur3->next = cur1;
			}
			nextcur3 = cur1;
			cur1 = cur1->next;
			nextcur3->next = NULL;

		}
		else if (cur1->data > cur2->data){
			if (cur3 == NULL) {
				cur3 = cur1;
			}
			else {
				nextcur3->next = cur2;
			}
			nextcur3 = cur2;
			cur2 = cur2->next;
			nextcur3->next = NULL;
		}
	}
	if (cur1 != NULL) {
		nextcur3->next = cur1;
	}
	else if(cur2 != NULL){
		nextcur3->next = cur2;
	}
	LinkListPrint(cur3);
}

void PrintInterSet(Node *list1, Node *list2)
{
	Node *cur1 = NULL;
	Node *cur2 = NULL;
	Node *cur3 = NULL;
	Node *nextcur3 = NULL;
	assert(list1 && list2);
	cur1 = list1;
	cur2 = list2;
	while (cur1 != NULL && cur2 != NULL)
	{

#if 0
		if (cur1->data > cur2->data) {
			cur2 = cur2->next;
		}
		else if (cur1->data < cur2->data) {
			cur1 = cur1->next;
		}
		else {
			if (cur3 == NULL) {
				cur3 = cur1;
			}
			else {
				nextcur3->next = cur1;
			}
			nextcur3 = cur1;
			printf("%d  ", cur1->data);
			cur1 = cur1->next;
			cur2 = cur2->next;
			nextcur3->next = NULL;
		}
	}
#else
		//求cur1->data == cur2->data
		while (cur1 != NULL && cur1->data > cur2->data) {
			cur2 = cur2->next;
		}
		if (cur1 == NULL) {
			break;
		}

		//求cur1->data == cur2->data
		while (cur2 != NULL && cur1->data < cur2->data) {
			cur1 = cur1->next;
		}
		if (cur2 == NULL) {
			break;
		}

		while (cur1 != NULL && cur2 != NULL && cur1->data == cur2->data) {
			//存起来
			if (cur3 == NULL) {
				cur3 = cur1;
			}
			else {
				nextcur3->next = cur1;
			}
			nextcur3 = cur1;
			//输出
			printf("%d  ", cur1->data);
			cur1 = cur1->next;
			cur2 = cur2->next;
			nextcur3->next = NULL;
		}
	}
#endif

	printf("\n");
	printf("NewLinkList: ");
	LinkListPrint(cur3);
}

Node* LinkListPrintMidNode(const Node *pNode)
{
	const Node *fast = NULL;
	const Node *slow = NULL;
	if (pNode == NULL) {
		return NULL;
	}
	fast = pNode;
	slow = pNode;
	while (1)
	{
		//1
		//1 2 
		//1 2 3
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		slow = slow->next;
	}
	printf("pNode = %p, data = %d\n", slow, slow->data);
	return (Node *)slow;
}

Node* LinkListReverseNode(const Node *pNode, int k)
{
	int i = k;
	const Node *fast = NULL;
	const Node *slow = NULL;
	if (pNode == NULL) {
		return NULL;
	}
	fast = pNode;
	slow = pNode;
	//1 1 3  5 6 4 2
#if 0
	while (fast && --i) {
		fast = fast->next;
	}
	if (fast == NULL) {
		return NULL;
	}
	while (fast->next != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
#else
	while (fast && i--) {
		fast = fast->next;
	}
	if (fast == NULL) {
		return NULL;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
#endif
	//printf("LinkListReverseNode  key = %d   data = %d\n", k, slow->data);
	return (Node *)slow;
}

void LinkListRemoveReverseNode(Node **ppNode, int k)
{
	Node *del = NULL;
	Node *cur = NULL;
	Node *prev = NULL;
	assert(*ppNode);
	if (*ppNode == NULL || k == 0) {
		return;
	}
	cur = *ppNode;
	del = *ppNode;
	//1
	//1 2 3 4 6 7 8 0 
	while (cur && --k) {
		cur = cur->next;
	}
	if (cur == NULL) {
		del = *ppNode;
		*ppNode = (*ppNode)->next;
		free(del);
		del = NULL;
	}
	else {
		while (cur->next != NULL) {
			prev = del;
			del = del->next;
			cur = cur->next;
		}
		prev->next = del->next;
		free(del);
		del = NULL;
	}
}

void test()
{
	int key = 0;
	Node *pNode = NULL;
	Node *pos = NULL;
	DataType data = 0;


	//LinkListInitialize(&pNode);
	//LinkListPushBack(&pNode, 6);
	//LinkListPushBack(&pNode, 4);
	//LinkListPushBack(&pNode, 2);
	//LinkListPushFront(&pNode, 5);
	//LinkListPushFront(&pNode, 3);
	//LinkListPushFront(&pNode, 1);
	//LinkListPushFront(&pNode, 1);

	//printf("LinkListPrint:    ");
	//LinkListPrint(pNode);
	//
	//LinkListNodeRemove(&pNode, 5);
	//LinkListNodeRemoveALL(&pNode, 1);
	//LinkListPrint(pNode);

	//printf("ReversePrint:     ");
	//ReversePrint(pNode);
	//
	//printf("ReversePrintRec:  ");
	//ReversePrintRec(pNode);
	//printf("\n");

	//printf("LinkListReverse:  ");
	//LinkListReverse(&pNode);


	//printf("LinkListReverse1:  ");
	//LinkListReverse1(&pNode);


	//data = 3;
	//pos = LinkListFind(&pNode, data);
	//printf("LinkListFind data = %d: pos = %p\n", data, pos);
	//data = 999;
	//printf("InsertBeforeNode pos = %p data = %d:  ", pos, data);
	//InsertBeforeNode(pos, data);
	//LinkListPrint(pNode);

	data = 3;
	for (int i = 1; i <= 7; i++) {
		LinkListPushBack(&pNode, i);
	}
	printf("LinkListPrint:    ");
	LinkListPrint(pNode);
	printf("Joceph   k = %d:     ", data);
	JocephCircle(pNode, data);


	//Node *list1 = NULL;
	//Node *list2 = NULL;
	//LinkListInitialize(&list1);
	//LinkListInitialize(&list2);
	//for (int i = 0; i < 7; i++) {
	//	LinkListPushBack(&list1, i);
	//}
	//for (int i = 1; i < 7; i += 2) {
	//	LinkListPushBack(&list2, i);
	//}
	//printf("list1 :");
	//LinkListPrint(list1);
	//printf("list2 :");
	//LinkListPrint(list2);
	//printf("Merge: ");
	//Merge(list1, list2);
	////printf("PrintInterSet: ");
	////PrintInterSet(list1, list2);
	//LinkListDestroy(&pNode);


	//LinkListPrintMidNode(pNode);
	//key = 3;
	//printf("LinkListReverseNode  key = %d   data = %d\n", key, LinkListReverseNode(pNode, 3)->data);
	//LinkListRemoveReverseNode(&pNode, 0);
	//printf("LinkListPrint:    ");
	//LinkListPrint(pNode);
}