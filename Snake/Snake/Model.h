#ifndef __MODEL_H__
#define __MODEL_H__


#define DEFAULT_HEAD 8
#define DEFAULT_RANKNUM 10
typedef enum Direction{
	UP, DOWN, LEFT, RIGHT
}Direction;

typedef struct Position{
	int x;
	int y;
}Position;

typedef struct Node{
	Position pos;
	struct Node *next;
}Node;


typedef struct Snake{
	Node *head;
	Node *tail;
	int speed;
	Direction direction;
}Snake;


typedef struct Game {
	Snake snake;        //��
    //������Ŀǰֻ������,����Ϊ�˼���ʱ�临�Ӷ�,
    //������ͷ���ߵ�β��,�������ñ���,ֻ��Ҫͷ��.
	Position food;      //ʳ������
	int width;          //��
	int height;         //��
    int score;          //����
}Game;


void SnakeInitialize(Snake *psnake);						//�߳�ʼ��
void SnakeDestroy(Snake *pSnake);							//������
void GenerateFood(Game *pgame);								//ʳ���ʼ��
void GameInitialize(Game *pgame);							//��Ϸ��ʼ��
void GameDestroy(Game *pGame);								//��Ϸ����
void SnakeAddHead(Snake *pSnake, Position *nextpos);		//������ͷ
void SnakeRemoveTail(Snake *pSnake);						//��ɾ��β
void SnakeRankSave(int size, int *prank);					//�������а�
void SnakeRankRead(int size, int *prank);					//��ȡ���а�
int SnakeScoreSort(int size, int *prank);					//�����а���������
#endif // !__MODEL_H__

