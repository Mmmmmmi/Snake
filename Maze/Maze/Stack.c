#include"Stack.h"

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


//Ë³ÐòÕ»
void Stack_Initialize(Stack *pStack)
{
	assert(pStack != NULL);
	pStack->base = (DataType *)malloc(sizeof(DataType) * DEFAULT_CAPACITY);
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
	assert(pStack != NULL);
	if (pStack->top < pStack->capacity){
		pStack->base[pStack->top] = data;
		pStack->top++;
		return;
	}
	tmp = (DataType *)realloc(pStack->base, (sizeof(DataType) * (pStack->capacity + ADD_CAPACITY)));
	if (tmp == NULL){
		perror("error for realloc Stack");
		exit(EXIT_FAILURE);
	}
	
	pStack->base = tmp;
	pStack->base[pStack->top] = data;
	pStack->capacity += ADD_CAPACITY;
	pStack->top++;
}


DataType Stack_Top(const Stack *pStack)
{
	assert(pStack != NULL);
	if (pStack->top == 0) {
		printf("Õ»Îª¿Õ£¬²é¿´Ê§°Ü£¡\n");
		exit(EXIT_FAILURE);
	}
	return pStack->base[pStack->top - 1];
}


void Stack_Pop(Stack *pStack)
{
	assert(pStack != NULL);
	if (pStack->top == 0) {
		printf("Õ»Îª¿Õ£¬³öÕ»Ê§°Ü£¡\n");
		exit(EXIT_FAILURE);
	}
	pStack->top--;
}


int Stack_Empty(const Stack *pStack)
{
	assert(pStack != NULL);
	return pStack->top == 0;
}


int Stack_Size(const Stack *pStack)
{
	assert(pStack != NULL);
	return pStack->top;
}


void Stack_copy(Stack *pStack1, const Stack *pStack2)
{
	DataType *tmp = NULL;
	assert(pStack1 != NULL && pStack2 != NULL);
	tmp = (DataType*)malloc(sizeof(DataType) * pStack2->capacity);
	if (tmp == NULL) {
		perror("error for malloc pStack2");
		exit(EXIT_FAILURE);
	}
	memcpy(tmp, pStack2->base, sizeof(DataType) * pStack2->top);
	pStack1->base = tmp;
	pStack1->capacity = pStack2->capacity;
	pStack1->top = pStack2->top;
}


void Stack_Destroy(Stack *pStack)
{
	assert(pStack != NULL);
	free(pStack->base);
	pStack->base = NULL;
	pStack->capacity = 0;
	pStack->top = 0;
}