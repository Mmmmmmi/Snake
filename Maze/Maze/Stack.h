#ifndef __Stack_H__
#define __Stack_H__




typedef struct CurPos        //栈类型数据
{
	int row;    //行
	int col;    //列

}CurPos;


//栈元素数据类型
typedef CurPos DataType;



//栈类型
typedef struct Stack
{
	DataType *base;
	int top;
	int capacity;
}Stack;

#define ADD_CAPACITY 3
#define DEFAULT_CAPACITY 2

void Stack_Initialize(Stack *pStack);                            //栈初始化

void Stack_Push(Stack *pStack, DataType data);                             //压栈
DataType Stack_Top(const Stack *pStack);                             //返回栈顶元素
int Stack_Empty(const Stack *pStack);                         //判断栈是否为空
int Stack_Size(const Stack *pStack);						//栈已使用空间大小
void Stack_Pop(Stack *pStack);                                //出栈
void Stack_copy(Stack *pStack1, const Stack *pStack2);    //栈拷贝
void Stack_Destroy(Stack *pStack);                      //销毁栈




#endif // !__Stack_H__

