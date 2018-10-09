#ifndef __ConmmentConvert_H__
#define __ConmmentConvert_H__

#include<stdio.h>
#include<stdlib.h>
//#include<io.h>

typedef enum State
{
	NUL_State,
	C_State,
	CPP_State,
	END_State
}State;

void CommentConvert(FILE *PRead, FILE *PWrite);         //×¢ÊÍ×ª»»

void DO_NUL_State(FILE *PRead, FILE *PWrite, State *PState);    //ÎÞ×´Ì¬Ö´ÐÐ²Ù×÷

void DO_C_State(FILE *PRead, FILE *PWrite, State *PState);     //c×¢ÊÍ×´Ì¬Ö´ÐÐ²Ù×÷ /*

void DO_CPP_State(FILE *PRead, FILE *PWrite, State *PState);   //c++×´Ì¬Ö´ÐÐ²Ù×÷  //

#endif // !__ConmmentConvert_H__

