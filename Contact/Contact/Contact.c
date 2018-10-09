#include"Contact.h"

enum Option
{
	EXIT,
	ADD,
	DETELE,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY
};

static void Save_Peoinfo(pContact pcon)
{
	int i = 0;
	FILE *fp = NULL;
	assert(pcon);
	fp = fopen("Peoinfo.dat", "wb");
	if (fp == NULL)
	{
		perror("error for fwrite");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < pcon->sz; i++)
	{
		//fprintf(fp, "%10s %5s %5d %15s %25s\n", pcon->data[i].name, pcon->data[i].sex, pcon->data[i].age, pcon->data[i].tele, pcon->data[i].addr);
		fwrite(pcon->data + i, sizeof(PeoInfo), 1, fp);
	}
	fclose(fp);
	fp = NULL;
}

static void Load_Peoinfo(pContact pcon)
{
	FILE *fp = NULL;
	PeoInfo tmp = { 0 };
	assert(pcon);
	fp = fopen("Peoinfo.dat", "rb");
	if (fp == NULL)
	{
		fp = fopen("Peoinfo.dat", "wb");
		perror("error for fread");
		exit(EXIT_FAILURE);
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, fp))
	{
		if (Check_Capacity(pcon) == 0)
		{
			printf("LOAD PEOINFO FAILURE!\n");
			exit(EXIT_FAILURE);
		}
		pcon->data[pcon->sz] = tmp;
		pcon->sz++;
	}
	fclose(fp);
	fp = NULL;
}
void Initialize_Contact(pContact pcon)
{
	pcon->data = (pPeoInfo) malloc (DEFAULT_CAPACITY * sizeof(PeoInfo));
	pcon->sz = 0;
	pcon->capacity = DEFAULT_CAPACITY;
	Load_Peoinfo(pcon);
}

static int Check_Capacity(pContact pcon)
{
	assert(pcon);
	if (pcon->sz == pcon->capacity)
	{
		//ÔöÈÝ
		pPeoInfo tmp = (pPeoInfo) realloc (pcon->data, (pcon->capacity + ADD_CAPACITY) * sizeof(PeoInfo));
		if (tmp != NULL)
		{
			pcon->data = tmp;
			pcon->capacity += ADD_CAPACITY;
			printf("ADD_CAPACITY_SUCCESS!\n");
			return 1;
		}
		else
		{
			printf("ADD_CAPACITY_FAILURE!\n");
			return 0;
		}
	}
	return 1;
}
void Add_Peoinfo(pContact pcon)
{
	pPeoInfo tmp = 0;
	assert(pcon);
	if (Check_Capacity(pcon) == 0)
		return;
	printf("Please input Name:");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("Please input Sex :");
	scanf("%s", pcon->data[pcon->sz].sex);
	printf("Please input Age :");
	scanf("%d", &pcon->data[pcon->sz].age);
	printf("Please input Tele:");
	scanf("%s", pcon->data[pcon->sz].tele);
	printf("Please input Addr:");
	scanf("%s", pcon->data[pcon->sz].addr);
	pcon->sz++;
}
static int Find_Peoinfo(const pContact pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	assert(pcon);
	printf("Please input name->_:");
	scanf("%s", name);
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(name, pcon->data[i].name) == 0)
			return i;
	}
	return -1;
}
void Delete_Peoinfo(pContact pcon)
{
	int i = 0;
	int ret = 0;
	assert(pcon);
	ret = Find_Peoinfo(pcon);
	if (ret == -1)
	{
		printf("DELETE FAILURE, CAN'T FIND!\n");
		return;
	}
	else
	{
		for (i = ret; i < pcon->sz - 1; i++)
		{
			pcon->data[i] = pcon->data[i + 1];
		}
		pcon->sz--;
		printf("DELETE SUCCESS!\n");
	}

}
void Search_Peoinfo(const pContact pcon)
{
	int ret = 0;
	assert(pcon);
	ret = Find_Peoinfo(pcon);
	if (ret == -1)
	{
		printf("SEARCH FAILURE, CAN'T FIND!\n");
	}
	else
	{
		printf("%10s %5s %5s %15s %25s\n", "Name", "Sex", "Age", "Tele", "Addr");
		printf("%10s %5s %5d %15s %25s\n", pcon->data[ret].name, pcon->data[ret].sex, pcon->data[ret].age, pcon->data[ret].tele, pcon->data[ret].addr);
	}
}
void Modify_Peoinfo(pContact pcon)
{
	int ret = 0;
	assert(pcon);
	ret = Find_Peoinfo(pcon);
	if (ret == -1)
	{
		printf("MODIFY FAILURE, CAN'T FIND!\n");
		return;
	}
	else
	{
		printf("Please input Name:");
		scanf("%s", pcon->data[ret].name);
		printf("Please input Sex :");
		scanf("%s", pcon->data[ret].sex);
		printf("Please input Age :");
		scanf("%d", &pcon->data[ret].age);
		printf("Please input Tele:");
		scanf("%s", pcon->data[ret].tele);
		printf("Please input Addr:");
		scanf("%s", pcon->data[ret].addr);
		printf("MODIFY SUCCESS!\n");
	}
}
void Sort_Peoinfo(pContact pcon)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pcon);
	for (i = 0; i < pcon->sz; i++)
	{
		for (j = 0; j < pcon->sz - i - 1; j++)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	printf("SORT SUCCESS!\n");
}
void Empty_Contact(pContact pcon)
{
	assert(pcon);
	pcon->sz = 0;
	pcon->capacity = 0;
	printf("EMPTY SUCCESS!\n");
}
void Show_Peoinfo(const pContact pcon)
{
	assert(pcon);
	int i = 0;
	if (pcon->sz == 0)
	{
		printf("NO PEOINFO£¡\n");
		return;
	}
	printf("%10s %5s %5s %15s %25s\n", "Name", "Sex", "Age", "Tele", "Addr");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%10s %5s %5d %15s %25s\n", pcon->data[i].name, pcon->data[i].sex, pcon->data[i].age, pcon->data[i].tele,pcon->data[i].addr);
	}
}

void Choose_Menu()
{
	printf("*********************************************\n");
	printf("********* 1.add           2.delete **********\n");
	printf("********* 3.search        4.modify **********\n");
	printf("********* 5.show          6.sort   **********\n");
	printf("********* 7.empty         0.exit   **********\n");
	printf("*********************************************\n");
	printf("Please input ->_:");
}
void Choose(pContact pcon)
{
	int input = 0;
	do
	{
		Choose_Menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Add_Peoinfo(pcon);
			break;
		case DETELE:
			Delete_Peoinfo(pcon);
			break;
		case SEARCH:
			Search_Peoinfo(pcon);
			break;
		case MODIFY:
			Modify_Peoinfo(pcon);
			break;
		case SHOW:
			Show_Peoinfo(pcon);
			break;
		case SORT:
			Sort_Peoinfo(pcon);
			break;
		case EMPTY:
			Empty_Contact(pcon);
			break;
		case EXIT:
			Destroy_Contact(pcon);
			Save_Peoinfo(pcon);
			printf("EXIT SUCCESS!!!\n");
			break;
		default:
			printf("INPUT ERROR !!!\n");
			break;
		}
	} while (input);
}

void Destroy_Contact(pContact pcon)
{
	free(pcon->data);
	pcon->data = NULL;
	pcon->capacity = 0;
	pcon->sz = 0;
}



