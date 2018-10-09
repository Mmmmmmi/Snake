#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node *next;
}Node;


void LinkListInitialize(Node **ppNode);                          //�����ʼ��

void LinkListDestroy(Node **ppNode);                              //��������

void LinkListPushFront(Node **ppNode, DataType d);                  //ͷ��

void LinkListPopFront(Node **ppNode);								//ͷɾ

void LinkListPushBack(Node **ppNode, DataType d);		     //β��

void LinkListPopBack(Node **ppNode);							  //βɾ

Node* LinkListFind(const Node *pNode, DataType d);              //�����в���

void LinkListInsert(Node **ppNode, Node *pos, DataType d);      //����ڵ�

void LinkListNodeRemove(Node **ppNode, DataType d);       // ��ֵɾ����ֻɾ�����ĵ�һ�� 

void LinkListNodeRemoveAll(Node **ppNode, DataType d);       // ��ֵɾ����ɾ������������

void LinkListErase(Node **ppNode, Node *pos);                 //�����ڵ�ɾ���ڵ�

void LinkListPrint(const Node *pNode);                             //��ӡ����

void ReversePrint(const Node *pNode);							   //�����ӡ����

void ReversePrintRec(const Node *pNode);                           //�ݹ������ӡ���� 

void LinkListReverse(Node **ppNode);                                //��������

void LinkListReverse1(Node **ppNode);                                //��������

void EraseNode(Node *pos);                                           //ɾ����ͷ������ķ�β�ڵ�

void InsertBeforeNode(Node *pos, DataType data);					//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������

Node* JocephCircle(Node *pNode, int k);									//������ʵ��Լɪ��(JosephCircle)

void Merge(Node *list1, Node *list2);                               //�ϲ�������������,�ϲ�����Ȼ����

void PrintInterSet(Node *list1, Node *list2);                       //������������е���ͬ����

Node* LinkListPrintMidNode(const Node *pNode);                            //���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������

Node* LinkListReverseNode(const Node *pNode, int k);                     //���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������

void LinkListRemoveReverseNode(Node **ppNode, int k);                    //ɾ������ĵ�����K�����


void test();														//����

#endif	//!__LINKLIST_H__
