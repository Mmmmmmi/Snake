#ifndef __RUN_H__
#define __RUN_H__


#include"Stack.h"


//typedef struct CurPos        //在Stack.h中 作为栈元素被定义过了
//{
//	int row;    //行
//	int col;    //列
//
//}CurPos;







#define COL 6
#define ROW 6







void Print_Maze(int Maze_arr[ROW][COL]);         //输出迷宫地图

int Judge_Run(int Maze_arr[ROW][COL], CurPos curpos);        //判断是否可以通过

int Run_Maze_Rec(int Maze_arr[ROW][COL], CurPos curpos, CurPos Maze_Enter);   //找出口

void Run_Maze(int Maze_arr[ROW][COL], CurPos Maze_Enter);      //找出口非递归

void Test_Run(int Maze_arr[ROW][COL], CurPos Maze_Enter);              //测试
	   
#endif //__RUN_H__

