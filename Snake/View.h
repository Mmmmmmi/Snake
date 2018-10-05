#pragma once


void PrintStart0(int width, int height);					//开始界面0
void PrintStart1(int width, int height);					//开始界面1
void PrintEnd(int width, int height);						//结束界面
void PrintWall(int width, int height);						//输出边界
void PrintSnake(const Snake *pSnake);						//输出蛇
void PrintSnakeBlock(const Position *prevpos, const Position *curpos);	//输出一块蛇身体
void CleanSnakeBlock(const Position *curpos);						//清除一块蛇身体
void PrintFood(const Position *pFood);							//输出食物
void PrintScore(int width, int height, int score);			//输出成绩
void PrintRank(int width, int height, int size, const int *pscore);		//输出成绩排行榜
void PrintGame(const Game *pGame);								//输出游戏
void PrintTest(int x, int y);								//测试