
#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include "Model.h"
#include "View.h"





//移动光标到指定位置   x为横   y为纵
static void SetCurPos(int X, int Y)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOutput, coord);
}

static void NewCurPos(int X, int Y)
{
	X = 2 * (X + 1);
	Y = Y + 1;
	SetCurPos(X, Y);
}

void ViewInit(int width, int height)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(hStdOutput, &info);
	info.bVisible = 0;
	SetConsoleCursorInfo(hStdOutput, &info);
}

void PrintStart0(int width, int height)
{
	ViewInit(width, height);
	NewCurPos(width / 4, height / 2);
	printf("PRESS SPACE TO START GAME ！");
}

void PrintStart1(int width, int height)
{
	ViewInit(width, height);
	NewCurPos(width / 4, height / 2);
	printf("                            ");
}

void PrintEnd(int width, int height)
{
	ViewInit(width, height);
	NewCurPos(width / 3, height / 2);
	printf("GAME OVER！");
	NewCurPos(width + 2, height);
}

void PrintWall(int width, int height)
{
	int i = 0;


	//上
	SetCurPos(0, 0);
	for (i = 0; i < width + 2; i++) {
		printf("█");
	}


	//左
	for (i = 0; i < height + 2; i++) {
		SetCurPos(0, i);
		printf("█");
	}

	//下
	SetCurPos(0, height + 1);
	for (i = 0; i < width + 2; i++) {
		printf("█");
	}

	//右
	for (i = 0; i < height + 2; i++) {
		SetCurPos(2 * (width + 1), i);
		printf("█");
	}
}

void PrintSnake(const Snake *pSnake)
{
	Node *cur = NULL;
	assert(pSnake != NULL);
	for (cur = pSnake->tail; cur != NULL; cur = cur->next)
	{
		NewCurPos((cur->pos).x, (cur->pos).y);
		if (cur == pSnake->head) {
			printf("⊙");
		}
		else {
			printf("※");
		}
	}
	SetCurPos(65, 16);

}

void PrintSnakeBlock(const Position *prevpos, const Position *curpos)
{
	NewCurPos(prevpos->x, prevpos->y);
	printf("※");
	NewCurPos(curpos->x, curpos->y);
	printf("⊙");
}

void CleanSnakeBlock(const Position *curpos)
{
	NewCurPos(curpos->x, curpos->y);
	printf("  ");
}

void PrintFood(const Position *pFood)
{
	NewCurPos(pFood->x, pFood->y);
	printf("●");
}

void PrintScore(int width, int height, int score)
{
	NewCurPos(width + 2, height / 3);
	printf("当前分数：%d", score);
}

void PrintRank(int width, int height, int size, const int *pscore)
{
	int i = 0;
	assert(pscore != NULL);
	NewCurPos(width + 15, 0);
	printf("Rank:");
	for (i = 1; i <= size; i++) {
		NewCurPos(width + 15, i);
		printf("第%2d名：%5d分", i, *(pscore + i - 1));
	}
}

void PrintFunction(int width, int height)
{
	NewCurPos(width + 2, height / 2);
	printf("空格键暂停");
	NewCurPos(width + 2, (height / 2) + 5);
	printf("长按方向键加速");
}

void PrintGame(const Game *pGame)
{
	PrintWall(pGame->width, pGame->height);
	PrintSnake(&(pGame->snake));
	PrintScore(pGame->width, pGame->height, pGame->score);
	PrintFunction(pGame->width, pGame->height);
}
