
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"Stack.h"




void Stack_Initialize(Stack *pStack)
{
	assert(pStack);
	pStack->base = (DataType *)malloc((sizeof(DataType) * DEFAULT_CAPACITY));
	if (pStack->base == NULL) {
		perror("error for realloc Stack");
		exit(EXIT_FAILURE);
	}
	pStack->capacity = DEFAULT_CAPACITY;
	pStack->top = 0;
}
void Stack_Push(Stack *pStack, DataType data)
{
	DataType *tmp = NULL;
	assert(pStack);
	if (pStack->top < pStack->capacity) {
		pStack->base[pStack->top] = data;
		pStack->top++;
		return;
	}
	tmp = (DataType *)realloc(pStack->base, (sizeof(DataType) * (pStack->capacity + ADD_CAPACITY)));
	if (tmp == NULL) {
		perror("error for realloc Stack");
		exit(EXIT_FAILURE);
	}
	pStack->base = tmp;
	pStack->base[pStack->top] = data;
	pStack->top++;
	pStack->capacity += ADD_CAPACITY;
}
DataType Stack_Top(const Stack *pStack)
{
	assert(pStack != NULL);
	if (pStack->top == 0) {
		printf("ջΪ�գ��鿴ʧ�ܣ�\n");
		exit(EXIT_FAILURE);
	}
	return pStack->base[pStack->top - 1];
}
unsigned Stack_Size(Stack *pStack)
{
	return (unsigned)pStack->top;
}
void Stack_Pop(Stack *pStack)
{
	assert(pStack != NULL);
	if (pStack->top == 0) {
		printf("ջΪ�գ���ջʧ�ܣ�\n");
		return;
	}
	//pStack->base[pStack->top - 1] = 0;
	pStack->top--;
}
int Stack_Full(const Stack *pStack)
{
	assert(pStack);
	return pStack->top == pStack->capacity;
}
int Stack_Empty(const Stack *pStack)
{
	assert(pStack);
	return pStack->top == 0;
}
void Stack_Copy(Stack *pStackDest, const Stack *pStackSrc)
{
	DataType *tmp = NULL;
	assert(pStackDest != NULL);
	assert(pStackSrc != NULL);
	tmp = (DataType*)malloc(sizeof(DataType) * pStackSrc->capacity);
	if (tmp == NULL) {
		perror("error for malloc pStackDest");
		exit(EXIT_FAILURE);
	}

	memcpy(tmp, pStackSrc->base, (sizeof(DataType) * pStackSrc->top));
	pStackDest->base = tmp;
	pStackDest->capacity = pStackSrc->capacity;
	pStackDest->top = pStackSrc->top;


}
void Stack_Destroy(Stack *pStack)
{
	assert(pStack);
	assert(pStack->base);
	free(pStack->base);
	pStack->base = NULL;
	pStack->capacity = 0;
	pStack->top = 0;
}

void test()
{
	Stack stack = { NULL, 0 };
	Stack stack1 = { NULL, 0 };

	Stack_Initialize(&stack);
	Stack_Push(&stack, 3);
	Stack_Push(&stack, 2);
	Stack_Push(&stack, 1);
	Stack_Push(&stack, 0);
	//Stack_Copy(&stack1, &stack);
	//printf("stack:\n");
	//printf("%d\n", Stack_Top(&stack));
	//Stack_Pop(&stack);
	//printf("%d\n", Stack_Top(&stack));
	//Stack_Pop(&stack);
	//printf("%d\n", Stack_Top(&stack));
	//Stack_Pop(&stack);
	//printf("%d\n", Stack_Top(&stack));
	//Stack_Pop(&stack);
	//printf("stack1:\n");
	//printf("%d\n", Stack_Top(&stack1));
	//Stack_Pop(&stack1);
	//printf("%d\n", Stack_Top(&stack1));
	//Stack_Pop(&stack1);
	//printf("%d\n", Stack_Top(&stack1));
	//Stack_Pop(&stack1);
	//printf("%d\n", Stack_Top(&stack1));
	//Stack_Pop(&stack1);
	Stack_Destroy(&stack);
	//Stack_Destroy(&stack1);
}
