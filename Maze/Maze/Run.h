#ifndef __RUN_H__
#define __RUN_H__


#include"Stack.h"


//typedef struct CurPos        //��Stack.h�� ��ΪջԪ�ر��������
//{
//	int row;    //��
//	int col;    //��
//
//}CurPos;







#define COL 6
#define ROW 6







void Print_Maze(int Maze_arr[ROW][COL]);         //����Թ���ͼ

int Judge_Run(int Maze_arr[ROW][COL], CurPos curpos);        //�ж��Ƿ����ͨ��

int Run_Maze_Rec(int Maze_arr[ROW][COL], CurPos curpos, CurPos Maze_Enter);   //�ҳ���

void Run_Maze(int Maze_arr[ROW][COL], CurPos Maze_Enter);      //�ҳ��ڷǵݹ�

void Test_Run(int Maze_arr[ROW][COL], CurPos Maze_Enter);              //����
	   
#endif //__RUN_H__

