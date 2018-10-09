#define _CRT_SECURE_NO_WARNINGS
#include"CommentConvert.h"


void test()
{
	FILE *PRead = fopen("input.c", "r");
	if (PRead == NULL)
	{
		perror("error for PRead ");
		exit(EXIT_FAILURE);
	}
	FILE *PWrite = fopen("output.c", "w");
	if (PRead == NULL)
	{
		perror("error for PWrite ");
		exit(EXIT_FAILURE);
	}
	CommentConvert(PRead, PWrite);
	fclose(PRead);
	PRead = NULL;
	fclose(PWrite);
	PWrite = NULL;
}

int main()
{
	test();
	return 0;
}