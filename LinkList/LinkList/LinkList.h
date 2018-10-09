#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node *next;
}Node;


void LinkListInitialize(Node **ppNode);                          //链表初始化

void LinkListDestroy(Node **ppNode);                              //链表销毁

void LinkListPushFront(Node **ppNode, DataType d);                  //头插

void LinkListPopFront(Node **ppNode);								//头删

void LinkListPushBack(Node **ppNode, DataType d);		     //尾插

void LinkListPopBack(Node **ppNode);							  //尾删

Node* LinkListFind(const Node *pNode, DataType d);              //链表中查找

void LinkListInsert(Node **ppNode, Node *pos, DataType d);      //插入节点

void LinkListNodeRemove(Node **ppNode, DataType d);       // 按值删除，只删遇到的第一个 

void LinkListNodeRemoveAll(Node **ppNode, DataType d);       // 按值删除，删除所有遇到的

void LinkListErase(Node **ppNode, Node *pos);                 //给定节点删除节点

void LinkListPrint(const Node *pNode);                             //打印链表

void ReversePrint(const Node *pNode);							   //逆序打印链表

void ReversePrintRec(const Node *pNode);                           //递归逆序打印链表 

void LinkListReverse(Node **ppNode);                                //链表逆置

void LinkListReverse1(Node **ppNode);                                //链表逆置

void EraseNode(Node *pos);                                           //删除无头单链表的非尾节点

void InsertBeforeNode(Node *pos, DataType data);					//在无头单链表的一个节点前插入一个节点（不能遍历链表）

Node* JocephCircle(Node *pNode, int k);									//单链表实现约瑟夫环(JosephCircle)

void Merge(Node *list1, Node *list2);                               //合并两个有序链表,合并后依然有序

void PrintInterSet(Node *list1, Node *list2);                       //输出两个链表中的相同数据

Node* LinkListPrintMidNode(const Node *pNode);                            //查找单链表的中间节点，要求只能遍历一次链表

Node* LinkListReverseNode(const Node *pNode, int k);                     //查找单链表的倒数第k个节点，要求只能遍历一次链表

void LinkListRemoveReverseNode(Node **ppNode, int k);                    //删除链表的倒数第K个结点


void test();														//测试

#endif	//!__LINKLIST_H__
