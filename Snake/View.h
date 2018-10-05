#pragma once


void PrintStart0(int width, int height);					//��ʼ����0
void PrintStart1(int width, int height);					//��ʼ����1
void PrintEnd(int width, int height);						//��������
void PrintWall(int width, int height);						//����߽�
void PrintSnake(const Snake *pSnake);						//�����
void PrintSnakeBlock(const Position *prevpos, const Position *curpos);	//���һ��������
void CleanSnakeBlock(const Position *curpos);						//���һ��������
void PrintFood(const Position *pFood);							//���ʳ��
void PrintScore(int width, int height, int score);			//����ɼ�
void PrintRank(int width, int height, int size, const int *pscore);		//����ɼ����а�
void PrintGame(const Game *pGame);								//�����Ϸ
void PrintTest(int x, int y);								//����