#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student
{
	int id;
	char name[30];
	float classnum;
	float score[5];
	Student* prev;
	Student* next;
};

Student* input()
{
	int n = 0,i;
	Student* p1, * p2, * head;       //创立节点计数
	p1 = p2 = (Student*)malloc(sizeof(Student));//开放内存空间
	printf("请按学号、姓名、班级、五门课的成绩输入学生信息：(输入0以结束)\n");
	scanf_s("%d", &p1->id);
	while (p1->id == 0)
	{
		p1->next = NULL;
		return p1;
	}
	scanf_s("%s", p1->name,30);
	scanf_s("%f", &p1->classnum);
	for (i = 0; i < 5; i++)
	{
		scanf_s("%f",&p1->score[i]);
		printf("\0");
	}
	getchar();
	head = NULL;
	while (1)
	{
		n++;//节点计数增加
		if (n == 1) {
			head = p1;
			p1->prev = NULL;//第一个节点前为空
		}
		else
		{
			p2->next = p1;
			p1->prev = p2;
		}
		/*第二次即以后赋值开始*/
		p2 = p1;
		p1 = (Student*)malloc(sizeof(Student));//开拓内存空间，即第n+1个节点储存的内存
		scanf_s("%d", &p1->id);
		while (p1->id == 0)
		{
           p2->next = NULL;
	       return head; //返回值为head——此时还是第一个节点的指针（即Student型地址）
		}
		scanf_s("%s", p1->name,30);
		scanf_s("%f", &p1->classnum);
		for (i = 0; i < 5; i++)
		{
			scanf_s("%f", &p1->score[i]);
		}
		getchar();
    }	
}

void delete0(Student* stu, int n)
{
	Student* p, * head;
	for (p = stu, head = p; p != NULL; p = p->next)
		if (p->id == n)
		{
			if (p == head)          //第一个节点就符合检索条件
			{
				head = p->next;
				p->next->prev = NULL;
				head->next = p->next->next;
			}
			else if (p->next == NULL)//最后一个节点符合条件
				p->prev->next = NULL;
			else                     //除第一个和最后一个的节点符合条件
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
			}
		}
	*stu = *head;//相当于返回head值
}

int insert(Student** stu, int m, char direc, Student* ins)
{
	Student* p, * head;
	for (p = *stu, head = p; p != NULL; p = p->next)
	{
		if (p->id == m)
		{
			if (direc == 'B' || direc == 'b')//在指定节点前插入
			{
				if (p == head)
				{
					ins->next = p;
					ins->prev = NULL;
					head = ins;
				}
				else
				{
					ins->prev = p->prev;
					p->prev->next = ins;
					ins->next = p;
					p->prev = ins;
				}
			}
			else if (direc == 'A' || direc == 'a') //在指定节点后插入
			{
				if (p->next == NULL)
				{
					p->next = ins;
					ins->next = NULL;
					ins->prev = p;
					return 1;
				}
				else {
					ins->next = p->next;
					p->next = ins;
					ins->prev = p;
				}
			}
		}
	}
	*stu = head;
	return 1;
}

void output(Student* stu)
{
	Student* p;
	printf("学生资料如下：\n");
	for (p = stu; p != NULL; p = p->next)
	{
		printf("%d %-10s %.2f ", p->id, p->name,p->classnum);
		int i;
		for (i = 0; i < 5; i++)
		{
			printf("%.2f ", p->score[i]);
		}
		printf("\n");
	}		
}

void change(Student* stu,int n)
{
	int m;
	Student* p = stu;
	while (p->id != n)
	{
		p = p->next;
		while (p->next == NULL)
			printf("查无此人。");
	}
	printf("该学生的信息：\n");
	printf("%d %s %.2f ", p->id, p->name, p->classnum);
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%.2f ", p->score[i]);
	}
	printf("\n");
    while(1)
    {
	    printf("请选择需要修改的项目\n1.姓名\n2.班级\n3.成绩\n0.退出\n");
	    scanf_s("%d", &m);
		if (m == 1) {
			char n[30]; int i; printf("请输入修改后的姓名：");
			scanf_s("%s", n, 30); for (i = 0; i < 30; i++)p->name[i] = n[i]; continue;
		}
		else if (m == 2) {
			float n; printf("请输入修改后的班级：");
			scanf_s("%f", &n); p->classnum = n; continue;
		}
		else if (m == 3) {
			float n[5]; int i; printf("请输入修改后的成绩：");
			for (i = 0; i < 5; i++)scanf_s("%f", &n[i]);
			for (i = 0; i < 5; i++)p->score[i] = n[i]; continue;
		}
		else if (m == 0)return;
    }
}

void aver(Student* head)
{
	double avg[5] = { 0 };
	double count = 0;
	while (head != nullptr)
	{
		for (int j = 0; j < 5; j++)
		{
			avg[j] += head->score[j];
		}
		head = head->next;
		count++;
	}
	for (int j = 0; j < 5; j++)
	{
		avg[j] = avg[j] / count;
		printf("第%d章的平均成绩为:%.2f\n", j + 1, avg[j]);
	}
}
int cmp(const void* a, const void* b)
{
	return *(int*)a < *(int*)b;
}
void median(Student* head)
{
	int num = 0;
	Student* p = head;
	Student* q = head;
	while (head != nullptr)
	{
		num++;
		head = head->next;
	}
	double result;
	int s = 0;
	for (s = 0; s < 5; s++)
	{
		float target[200] = { 0 };
		p = q;
		for (int j = 0; j < num; j++)
		{
			target[j] = p->score[s];
			p = p->next;
		}
		int m, n;
		float t;
		for (m = 0; m < num; m++)
		{
			for (n = m + 1; n < num; n++)
			{
				if (target[m] > target[n])
				{

					t = target[m];
					target[m] = target[n];
					target[n] = t;
				}

			}
		}
		if (num % 2 != 0)
		{
			result = target[(num - 1) / 2];
		}
		else
		{
			int x, y;
			x = num / 2 - 1;
			y = num / 2;
			result = (target[x] + target[y]) / 2;
		}
		printf("第%d章的中位数是%.2f\n", s + 1, result);
	}
}
void distribute(Student* head)
{
	int num = 0;
	Student* p = head;
	Student* q = head;
	while (head != nullptr)
	{
		num++;
		head = head->next;
	}
	for (int i = 0; i < 5; i++)
	{
		int pass = 0, common = 0, liang = 0, excllent = 0, best = 0;
		p = q;
		float target[200];
		for (int j = 0; j < num; j++)
		{
			target[j] = p->score[i];
			p = p->next;
		}
		for (int j = 0; j < num; j++)
		{
			if (target[j] < 60)
			{
				pass++;
			}
			else if (target[j] < 70)
			{
				common++;
			}
			else if (target[j] < 80)
			{
				liang++;
			}
			else if (target[j] < 90)
			{
				excllent++;
			}
			else
			{
				best++;
			}
		}
		printf("第%d次测验中,不及格%d人,普通(60-70)%d人,中上(70-80)%d人,良好(80-90)%d人,优秀(90-100)%d人\n",
			(i + 1), pass, common, liang, excllent, best);
	}
}

void chaxunid(Student* chaxun,int id)
{ 
	int i = 0;
	while (chaxun != NULL)
	{
		if (chaxun->id != id)
		{
			chaxun = chaxun->next;
		}
		else
		{
			printf("学号：%d\n", chaxun->id);
			printf("姓名：%s\n", chaxun->name);
			printf("班级：%.2f\n", chaxun->classnum);
			printf("五次测验的成绩：");
			for (i = 0; i < 5; i++)
			{
				printf("%.2f ", chaxun->score[i]);
				printf("\0");
			}
			printf("\n");
			return;
		}
	}
	printf("查无此人。\n");
}

void chaxunname(Student* chaxun, char* name)
{
	int i;
	int count = 0;
	while (chaxun != NULL)
	{
		if (strcmp(chaxun->name,name)!= 0)
		{
			chaxun = chaxun->next;
		}
		else
		{
			printf("学号：%d\n", chaxun->id);
			printf("姓名：%s\n", chaxun->name);
			printf("班级：%.2f\n", chaxun->classnum);
			printf("五次测验的成绩：");
			for (i = 0; i < 5; i++)
			{
				printf("%.2f ", chaxun->score[i]);
				printf("\0");
			}
			printf("\n");
			chaxun = chaxun->next;
			count++;
		}
	}
	if(count==0) printf("查无此人。\n");
}

void chaxunclass(Student* chaxun, float classnum)
{
	int i ;
	int count = 0;
	while (chaxun != NULL)
	{
		if (chaxun->classnum != classnum)
		{
			chaxun = chaxun->next;
		}
			else
			{
				printf("学号：%d\n", chaxun->id);
				printf("姓名：%s\n", chaxun->name);
				printf("班级：%.2f\n", chaxun->classnum);
				printf("五门课的成绩：");
				for (i = 0; i < 5; i++)
				{
					printf("%.2f ", chaxun->score[i]);
					printf("\0");
				}
				printf("\n");
				chaxun = chaxun->next;
				count++;
			}
		}
	if (count == 0) printf("查无此人。\n");
}