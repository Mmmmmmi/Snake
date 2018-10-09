#define _CRT_SECURE_NO_WARNINGS

#include"CommentConvert.h"



void CommentConvert(FILE *PRead, FILE *PWrite)
{
	//状态机  多个状态
	//   无状态  c注释状态   c++状态   eof状态
	State state = NUL_State;
	while (state != END_State)         //当文件未读完时
	{
		switch (state)
		{
			case NUL_State:
				DO_NUL_State(PRead, PWrite, &state);
				break;
			case C_State:
				DO_C_State(PRead, PWrite, &state);
				break;
			case CPP_State:
				DO_CPP_State(PRead, PWrite, &state);
				break;	
		}
	}	
}


void DO_NUL_State(FILE *PRead, FILE *PWrite, State *PState)
{
	int first = fgetc(PRead);
	switch (first)
	{
		case '/':                  //注释的开始
		{
			int second = fgetc(PRead);
			switch (second)
			{
				//      // /* 
				case'*':                          //c注释开始
				{
					fputc('/', PWrite);
					fputc('/', PWrite);
					*PState = C_State;
				}
					break;
				case'/':						//c++注释开始
				{
					fputc(first, PWrite);
					fputc(second, PWrite);
					*PState = CPP_State;
				}
					break;
				default:                      //正常读到代码
				{
					fputc(first, PWrite);
					ungetc(second, PRead);
				}
					break;
			}
		}
			break;
		case EOF:                  //文件的结束
			*PState = END_State;
			break;
		default:                    //正常代码
		{
			fputc(first, PWrite);
		}
			break;
	}
}


void DO_C_State(FILE *PRead, FILE *PWrite, State *Pstate)       //c注释的处理
{
	int first = fgetc(PRead);
	//        a   */   **/    */i
	switch (first)
	{
		case '*':
		{
			int second = fgetc(PRead);
			switch (second)
			{
				case '/':                          //c注释结束
				{
					int third = fgetc(PRead);
					if (third == '\n')
					{
						fputc(third, PWrite);
					}
					else                        //考虑到连续两个c注释的问题 比如  /* int a = 1; */  /* int b = 1;*/   将它们放在两行
					{
						fputc('\n', PWrite);
						ungetc(third, PRead);
					}
					*Pstate = NUL_State;
				}
					break;
				case '*':                      //   **/  ******/   等问题
				{
					fputc(first, PWrite);
					ungetc(second, PRead);
				}
					break;
				default:                      //正常读到代码
				{
					fputc(first, PWrite);
					ungetc(second, PRead);
				}
					break;
			}
		}
			break;
		case '\n':             //多行注释
		{
			fputc(first, PWrite);
			fputc('/', PWrite);
			fputc('/', PWrite);
		}
			break;
		default:
		{
			fputc(first, PWrite);
		}
			break;
	}
}


void DO_CPP_State(FILE *PRead, FILE *PWrite, State *PState)
{
	int first = fgetc(PRead);
	switch (first)
	{
		case '\n':                       //c++注释结束
		{
			fputc(first, PWrite);
			*PState = NUL_State;
		}
			break; 
		case EOF:                 //文件尾
			*PState = END_State;
			break;
		default:                         //正常读到代码
			fputc(first, PWrite);
			break;

	}
}
