

#include<stdio.h>
#include"Run.h"
#include<Windows.h>


static int FLAG = 0;     //标记是否找到出口
static Stack path;       //路径
static Stack min_path;   //最小路径


//输出迷宫地图数组
void Print_Maze_Arr(int Maze_arr[ROW][COL])         
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d  ", Maze_arr[i][j]);
		}
		printf("\n");
	}		
}


//输出迷宫地图
void Print_Maze(int Maze_arr[ROW][COL])         
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (Maze_arr[i][j] == 0)
				printf("█");
			if (Maze_arr[i][j] == 1)
				printf("  ");
			if (Maze_arr[i][j] == 2)
				printf("○");
			//printf("%d  ", Maze_arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//判断是否可以通过
int Judge_Run(int Maze_arr[ROW][COL], CurPos curpos)       
{
	if (curpos.row < 0 || curpos.row > ROW || curpos.col < 0 || curpos.col > COL)    //超出迷宫范围
		return 0;
	return Maze_arr[curpos.row][curpos.col] == 1;
}


static int Is_Exit(CurPos cur, CurPos Maze_Enter, int Row, int Col)
{
	if (cur.col == 0 || cur.col == Col - 1 || cur.row == 0 || cur.row == Row - 1) {               //边界上
		if (cur.row != Maze_Enter.row && cur.col != Maze_Enter.col) {
			return 1;
		}
	}
	return 0;
}

//走迷宫
//递归
int Run_Maze_Rec(int Maze_arr[ROW][COL], CurPos curpos, CurPos Maze_Enter)
{
	CurPos next = { 0 };
	if (Judge_Run(Maze_arr, curpos))   //当在棋盘内部并且可以走
	{
		Maze_arr[curpos.row][curpos.col] = 2;    //标记此处走过
		Stack_Push(&path, curpos);               //将刚走过的路压入路径栈中
		Print_Maze(Maze_arr);
		//上
		next.row = curpos.row - 1;
		next.col = curpos.col;
		if (Judge_Run(Maze_arr, next))
		{
			Run_Maze_Rec(Maze_arr, next, Maze_Enter);      //进行递归
		}
		//右
		next.row = curpos.row;
		next.col = curpos.col + 1;
		if (Judge_Run(Maze_arr, next))
		{
			Run_Maze_Rec(Maze_arr, next, Maze_Enter);      //进行递归
		}
		//下
		next.row = curpos.row + 1;
		next.col = curpos.col;
		if (Judge_Run(Maze_arr, next))
		{
			Run_Maze_Rec(Maze_arr, next, Maze_Enter);      //进行递归
		}
		//左
		next.row = curpos.row;
		next.col = curpos.col - 1;
		if (Judge_Run(Maze_arr, next))
		{
			Run_Maze_Rec(Maze_arr, next, Maze_Enter);      //进行递归
		}
	}
	if((curpos.row == 0 || curpos.row == (ROW - 1) || curpos.col == 0 || curpos.col == (COL - 1)))  //走到迷宫边上
	{
		if (curpos.row != Maze_Enter.row && curpos.col != Maze_Enter.col)   //不在入口位置
		{
			if (Stack_Empty(&min_path) || Stack_Size(&path) < Stack_Size(&min_path))
			{
				Stack_copy(&min_path, &path);                     //一直存最小的路径
			}
			printf("=============================出口为： %d  %d  =================================\n\n\n", curpos.row, curpos.col);
			FLAG = 1;
		}
	}
	Maze_arr[curpos.row][curpos.col] = 1;    //取消标记
	Stack_Pop(&path);                  //从此处退走 所以出栈
	Print_Maze(Maze_arr);              //后退的路线
	return FLAG;
}

//非递归
void Run_Maze(int Maze_arr[ROW][COL], CurPos Maze_Enter)
{
	Stack Path;
	CurPos cur = { 0 };
	CurPos next = { 0 };
	cur.row = Maze_Enter.row;
	cur.col = Maze_Enter.col;
	Stack_Initialize(&Path);
	while (1) {


		Maze_arr[cur.row][cur.col] = 2;     //标记走过
		
		system("CLS");
		Print_Maze(Maze_arr);
		Sleep(300);

		if (Is_Exit(cur, Maze_Enter, ROW, COL))     //判断是否结束
		{
			break;
		}
		//左
		next.row = cur.row;
		next.col = cur.col - 1;
		if (Judge_Run(Maze_arr, next)) {
			Stack_Push(&Path,cur);
			cur.row = next.row;
			cur.col = next.col;
			continue;
		}
		//上
		next.row = cur.row - 1;
		next.col = cur.col;
		if (Judge_Run(Maze_arr, next)) {
			Stack_Push(&Path, cur);
			cur.row = next.row;
			cur.col = next.col;
			continue;

		}
		//右
		next.row = cur.row;
		next.col = cur.col + 1;
		if (Judge_Run(Maze_arr, next)) {
			Stack_Push(&Path, cur);
			cur.row = next.row;
			cur.col = next.col;
			continue;

		}
		//下
		next.row = cur.row + 1;
		next.col = cur.col;
		if (Judge_Run(Maze_arr, next)) {
			Stack_Push(&Path, cur);
			cur.row = next.row;
			cur.col = next.col;
			continue;

		}
		if (Stack_Empty(&Path)) {
			break;
		}
		cur = Stack_Top(&Path);                    //都不能走 回溯
		Stack_Pop(&Path);
	}
	if (Stack_Empty(&Path)) {
		printf("无出口！\n");
	}
	else {
		printf("出口为 ：%d, %d\n", cur.row, cur.col);
	}
	Stack_Destroy(&Path);
}

//测试
void Test_Run(int Maze_arr[ROW][COL], CurPos Maze_Enter)
{

#if 0
	Stack_Initialize(&path);
	Stack_Initialize(&min_path);

	if (!Run_Maze_Rec(Maze_arr, Maze_Enter, Maze_Enter)) {
		printf("迷宫无出口!!!!\n");
		return;
	}
	printf("最短路径为： %d\n", Stack_Size(&min_path));
	Stack_Destroy(&path);
	Stack_Destroy(&min_path);
#else
	Run_Maze(Maze_arr, Maze_Enter);
#endif

}

