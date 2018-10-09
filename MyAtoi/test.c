#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>
enum State
{
	VALID,
	INVALID
};
static enum State state = INVALID;
int my_atoi(const char *str)
{
	long long ret = 0;
	int flag = 1;
	assert(str != NULL);         //空指针
	if (*str == '\0')            //空串
		return 0;
	//前面为空字符
	while (isspace(*str))            //头文件为ctype.h                     
	{
		str++;
	}
	//正负号问题
	if (*str == '-')                                            
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str)                                                   
	{
		//是否为数字字符问题	
		if (isdigit(*str))									  
		{
			ret = ret * 10 + (*str - '0') * (flag);                        
			//溢出问题
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			//字符中的非数字字符
			state = VALID;
			return (int)ret;
		}
		str++;
	}
	state = VALID;
	return (int)ret;
}
int main()
{
	int ret = 0;
	char p[20] = {0};
	printf("Please input->_: ");
	scanf("%s", p);
	ret = my_atoi(p);
	if(state == VALID)
		printf("my_atoi(p) = %d\n", ret);
	printf("atoi(p)    = %d\n", atoi(p));
	return 0;
}