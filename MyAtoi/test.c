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
	assert(str != NULL);         //��ָ��
	if (*str == '\0')            //�մ�
		return 0;
	//ǰ��Ϊ���ַ�
	while (isspace(*str))            //ͷ�ļ�Ϊctype.h                     
	{
		str++;
	}
	//����������
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
		//�Ƿ�Ϊ�����ַ�����	
		if (isdigit(*str))									  
		{
			ret = ret * 10 + (*str - '0') * (flag);                        
			//�������
			if (ret > INT_MAX || ret < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			//�ַ��еķ������ַ�
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