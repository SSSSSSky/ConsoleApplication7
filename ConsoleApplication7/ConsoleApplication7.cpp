#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"io.h"
#include"string.h"
#include "malloc.h"
#include"iostream"
using namespace std;
#define ERROR 0
#define ElemType Student

struct Student
{
	unsigned int	ID;			 // 学号
	char			Name[8];
	char			Subject[50]; // 信息工程 或 光电信息科学与工程
	char			Phone[11];
	int				Sex;		 // 男:0; 女:1
	int				BirthYear;   // 出生年，例如1993

	void init(unsigned int id, const char* name, const char* subject, const char* phone, int sex, int birthyear)
    {
		ID = id;
		strcpy(Name, name);
		strcpy(Phone, phone);
		strcpy(Subject, subject);
		Sex = sex;
		BirthYear = birthyear;
	}

	int getAge()
	{
		return 2018 - BirthYear;
	}

	void print()
	{
		char SexStr[3];
		switch (Sex)
		{
		case 0:
			sprintf(SexStr, "男");
			break;
		case 1:
			sprintf(SexStr, "女");
			break;
		}
		printf("%8s, %3s，%20s，%15d，%5d", Name, SexStr, Subject, ID, getAge());
	}
};

struct  LNode
{
	ElemType data;
	struct LNode   *next;
	struct LNode  *s,*p,*head,*q;
	int size=0;
	
	void Insert(ElemType e)
	{
		
	    head = (LNode*)malloc(sizeof(LNode));  //指向头节点
		p = head;
		for (int i = 0; i < 13; i++)
		{
			s= (LNode*)malloc(sizeof(LNode));
			s->data = e;
			p->next = s;
			size++;
		}
		p->next = NULL;
	}
	
	 void print()
	 {
		// struct Student studentlist;
		 q = head->next;
		 while (q) {
			 //studentlist = q->data;
			 printf("%8s,%20s，%15d\n", q->data.Name, q->data.Subject, q->data.ID);
			 q = q->next;
		 }

	 }
};

int main()
{
	LNode  node;
	struct _finddata_t files;
	int File_Handle;
	int i = 0;
	const char* FileFolder = "C:/Users/Administrator/Desktop/dat";
	//将char*改为const char*，其路径为一常量值，不能直接用char*
	char Pattern[255];
	sprintf(Pattern, "%s/*.dat", FileFolder);

	File_Handle = _findfirst(Pattern, &files);
	if (File_Handle == -1)
	{
		printf("error\n");
		return 0;
		//修改return为return 0
	}
	do
	{
		printf("%s \n", files.name);

		char FilePath[255];
		sprintf(FilePath, "%s/%s", FileFolder, files.name);
		FILE* fid = fopen(FilePath, "r");
		Student student;
		fread(&student, sizeof(Student), 1, fid);
		fclose(fid);
		node.Insert(student);
		i++;
	} while (0 == _findnext(File_Handle, &files));
	_findclose(File_Handle);
	printf("Find %d files\n", i);
	node.print();

}