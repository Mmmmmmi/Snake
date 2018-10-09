#ifndef __Stack_H__
#define __Stack_H__




typedef struct CurPos        //ջ��������
{
	int row;    //��
	int col;    //��

}CurPos;


//ջԪ����������
typedef CurPos DataType;



//ջ����
typedef struct Stack
{
	DataType *base;
	int top;
	int capacity;
}Stack;

#define ADD_CAPACITY 3
#define DEFAULT_CAPACITY 2

void Stack_Initialize(Stack *pStack);                            //ջ��ʼ��

void Stack_Push(Stack *pStack, DataType data);                             //ѹջ
DataType Stack_Top(const Stack *pStack);                             //����ջ��Ԫ��
int Stack_Empty(const Stack *pStack);                         //�ж�ջ�Ƿ�Ϊ��
int Stack_Size(const Stack *pStack);						//ջ��ʹ�ÿռ��С
void Stack_Pop(Stack *pStack);                                //��ջ
void Stack_copy(Stack *pStack1, const Stack *pStack2);    //ջ����
void Stack_Destroy(Stack *pStack);                      //����ջ




#endif // !__Stack_H__

