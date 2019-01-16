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
	Snake snake;        //蛇
    //由于蛇目前只会增长,所以为了减少时间复杂度,
    //让链表头当蛇的尾巴,增长不用遍历,只需要头插.
	Position food;      //食物坐标
	int width;          //宽
	int height;         //高
    int score;          //分数
}Game;


void SnakeInitialize(Snake *psnake);						//蛇初始化
void SnakeDestroy(Snake *pSnake);							//蛇销毁
void GenerateFood(Game *pgame);								//食物初始化
void GameInitialize(Game *pgame);							//游戏初始化
void GameDestroy(Game *pGame);								//游戏销毁
void SnakeAddHead(Snake *pSnake, Position *nextpos);		//蛇增加头
void SnakeRemoveTail(Snake *pSnake);						//蛇删除尾
void SnakeRankSave(int size, int *prank);					//保存排行榜
void SnakeRankRead(int size, int *prank);					//读取排行榜
int SnakeScoreSort(int size, int *prank);					//对排行榜重新排序
#endif // !__MODEL_H__

