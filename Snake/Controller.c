#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <windows.h>
#include "Model.h"
#include "View.h"

static Position GetNextPos(const Snake *pSnake)						//获取蛇下一步要走的坐标
{
	assert(pSnake != NULL);
	Position nextpos = pSnake->head->pos;
	switch(pSnake->direction) {
	case UP:
		nextpos.x = (pSnake->head->pos).x;
		nextpos.y = (pSnake->head->pos).y - 1;
		break;
	case DOWN:
		nextpos.x = (pSnake->head->pos).x;
		nextpos.y = (pSnake->head->pos).y + 1;
		break;
	case LEFT:
		nextpos.x = (pSnake->head->pos).x - 1;
		nextpos.y = (pSnake->head->pos).y;
		break;
	case RIGHT:
		nextpos.x = (pSnake->head->pos).x + 1;
		nextpos.y = (pSnake->head->pos).y;
		break;
	}	
	return nextpos;
}

static int IsEat(const Position *pFood, const Position *nextpos)
{
	return (pFood->x == nextpos->x) && (pFood->y == nextpos->y);
}

static void Pause()
{
	while (1) {
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE)) {
			break;
		}
	}
}

static int GameOver(const Game *pGame)
{
	Node *cur = NULL;
	assert(pGame != NULL);


	//左边
	if (pGame->snake.head->pos.x < 0) {
		return 1;
	}
	//右边
	if (pGame->snake.head->pos.x >= pGame->width) {
		return 1;
	}
	//上边
	if (pGame->snake.head->pos.y < 0) {
		return 1;
	}
	//下边
	if (pGame->snake.head->pos.y >= pGame->height) {
		return 1;
	}
	//自己
	for (cur = pGame->snake.tail; cur != pGame->snake.head; cur = cur->next) {
		if (cur->pos.x == pGame->snake.head->pos.x && cur->pos.y == pGame->snake.head->pos.y) {
			return 1;
		}
	}

	return 0;
}

void RunGame()
{
	Game game;
	int isspeed = 0;
	int *prank = NULL;
	prank = (int *)malloc(sizeof(int) * (DEFAULT_RANKNUM + 1));
	//游戏初始化
	GameInitialize(&game);
	//读取排行榜
	SnakeRankRead(DEFAULT_RANKNUM, prank);
	PrintGame(&game);
	PrintRank(game.width, game.height, DEFAULT_RANKNUM, prank);
	PrintStart0(game.width, game.height);
	Pause();
	PrintStart1(game.width, game.height);
	while (1) {
		PrintFood(&(game.food));
		PrintScore(game.width, game.height, game.score);
		//PrintSnake(&(game.snake));
		//根据按键 检测方向
		isspeed = 0;          //如果两次都按相同的 则加速
		if (GetAsyncKeyState(VK_UP) && game.snake.direction != DOWN) {
			if (game.snake.direction == UP) {
				isspeed = 1;
			}
			game.snake.direction = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && game.snake.direction != UP) {
			if (game.snake.direction == DOWN) {
				isspeed = 1;
			}
			game.snake.direction = DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) && game.snake.direction != RIGHT) {
			if (game.snake.direction == LEFT) {
				isspeed = 1;
			}
			game.snake.direction = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && game.snake.direction != LEFT) {
			if (game.snake.direction == RIGHT) {
				isspeed = 1;
			}
			game.snake.direction = RIGHT;
		}
		else if (GetAsyncKeyState(VK_SPACE)) {
			Pause();
		}

		//判断按完之后的情况
		Position nextpos = GetNextPos(&(game.snake));
		//走的这里的时候，蛇的头部已经到达了下一个坐标处，只差赋值
		// 吃到食物   没吃食物
		if (IsEat(&(game.food), &nextpos)) {
			//吃到食物 尾巴不变 头变长一个  重新生成食物  分数增加
			GenerateFood(&game);
			if (game.snake.speed > 80) {
				game.snake.speed -= 5;
			}
			game.score += 10;
		}
		else {
			//没吃到  尾巴消了  头变长一个
			SnakeRemoveTail(&(game.snake));
		}
		SnakeAddHead(&(game.snake), &nextpos);

		if (GameOver(&game)) {
			break;
		}

		if (isspeed) {
			Sleep(50);
		}
		else {
			Sleep(game.snake.speed);
		}

	}
	//将新成绩放在最后一位，对成绩排序，只保存除最后一位的
	(*(prank + DEFAULT_RANKNUM)) = game.score;
	SnakeScoreSort(DEFAULT_RANKNUM + 1, prank);
	SnakeRankSave(DEFAULT_RANKNUM, prank);
	//再输出一边，作用为有新成绩立马刷新榜单
	PrintRank(game.width, game.height, DEFAULT_RANKNUM, prank);
	PrintEnd(game.width, game.height);
	Pause();
	GameDestroy(&game);
}

int main()
{
    srand((unsigned)time(NULL));
	RunGame();
	return 0;
}

