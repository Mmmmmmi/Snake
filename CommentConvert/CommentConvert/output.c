// 1.一般情况
int num = 0;
// int i = 0; 

// 2.换行问题
// int i = 0; 
int j = 0;
// int i = 0; 
int j = 0;

// 3.匹配问题
//int i = 0;/*xxxxx

// 4.多行注释问题
//
//int i=0;
//int j = 0;
//int k = 0;
//
int k = 0;

// 5.连续注释问题
//
//

// 6.连续的**/问题
//*

// 7.C++注释问题
// /*xxxxxxxxxxxx*/


2/3                     //这是正常代码中只遇到一个/的情况


//这是一段代码
//  这段代码只用作测试
//  注释为添加的各种情况
//
int Fib(int n)         
{
	int ret = 0;   ////ret为返回值//
int i = 0;
	int count0 = 1;  //**count0为第n-2个fib的值**
	int count1 = 0;  //**count0为:**
 //第n-2个fib的值**
	for (i = 0; i < n; i++)   //  /*从第一个开始计算*/
	{
		//从第一个
		//开始
		//计算ret的值。
ret = count0 + count1;
		count0 = count1;    //让count0跟着i变化/*
		count1 = ret;
	}
	return ret;       //返回求得的第n个fib的值   /**/
}



