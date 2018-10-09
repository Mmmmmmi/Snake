#ifndef __Contact_H__
#define __Contact_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define NAME_MAX 20			//姓名字符串最大值
#define SEX_MAX 5			//性别字符串最大值	
#define TELE_MAX 12			//电话字符串最大值
#define ADDR_MAX 25			//地址字符串最大值
#define DEFAULT_CAPACITY 3	//初始化时空间默认值
#define ADD_CAPACITY 2		//扩容空间默认值

typedef struct PeoInfo            //联系人信息
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo, *pPeoInfo;

typedef struct Contact           //通讯录信息
{
	pPeoInfo data;
	int sz;
	int capacity;
}Contact, *pContact;
void Choose_menu();    //打印选择菜单
void Initialize_Contact(pContact pcon);     //初始化通讯录
void Choose();      //选择功能
void Add_Peoinfo(pContact pcon);       //添加人信息
void Delete_Peoinfo(pContact pcon);   //删除人信息
void Search_Peoinfo(const pContact pcon);    //查找人的信息 
void Modify_Peoinfo(pContact pcon);    //修改人的信息 
void Show_Peoinfo(const pContact pcon);    //输出人的信息 
void Sort_Peoinfo(pContact pcon);    //排序人的信息 
void Empty_Contact(pContact pcon);     //清空通讯录
void Destroy_Contact(pContact pcon);      //清空通讯录

#endif // !__Contact_H__

