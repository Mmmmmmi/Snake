#ifndef __Contact_H__
#define __Contact_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define NAME_MAX 20			//�����ַ������ֵ
#define SEX_MAX 5			//�Ա��ַ������ֵ	
#define TELE_MAX 12			//�绰�ַ������ֵ
#define ADDR_MAX 25			//��ַ�ַ������ֵ
#define DEFAULT_CAPACITY 3	//��ʼ��ʱ�ռ�Ĭ��ֵ
#define ADD_CAPACITY 2		//���ݿռ�Ĭ��ֵ

typedef struct PeoInfo            //��ϵ����Ϣ
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo, *pPeoInfo;

typedef struct Contact           //ͨѶ¼��Ϣ
{
	pPeoInfo data;
	int sz;
	int capacity;
}Contact, *pContact;
void Choose_menu();    //��ӡѡ��˵�
void Initialize_Contact(pContact pcon);     //��ʼ��ͨѶ¼
void Choose();      //ѡ����
void Add_Peoinfo(pContact pcon);       //�������Ϣ
void Delete_Peoinfo(pContact pcon);   //ɾ������Ϣ
void Search_Peoinfo(const pContact pcon);    //�����˵���Ϣ 
void Modify_Peoinfo(pContact pcon);    //�޸��˵���Ϣ 
void Show_Peoinfo(const pContact pcon);    //����˵���Ϣ 
void Sort_Peoinfo(pContact pcon);    //�����˵���Ϣ 
void Empty_Contact(pContact pcon);     //���ͨѶ¼
void Destroy_Contact(pContact pcon);      //���ͨѶ¼

#endif // !__Contact_H__

