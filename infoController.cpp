#include "studinfo.h"
int found = 0;
int found1 = 0;
int found2 = 0;
int found3 = 0;
void save(Student*);
Student* infoscanf();
int main(void)
{
	void step1(Student*);
	void step3(Student*);
	void step2(Student*);
	void step3(Student*);
	while (found==0)
	{
		printf("***************************************************************************\n");
		printf("*                             操作菜单                                    *\n");
		printf("*                         1.学生资料管理                                  *\n");
		printf("*                         2.学生成绩分析                                  *\n");
		printf("*                         3.学生查询系统                                  *\n");
		printf("*                         4.关于系统                                      *\n");
		printf("*                         0.退出系统                                      *\n");
		printf("*                                                                         *\n");
		printf("*                          按Enter键继续                                  *\n");
		printf("*                                                                         *\n");
		printf("***************************************************************************\n");
		int number;
		scanf_s("%d", &number);
		getchar();
		switch (number)
		{
		case 0:return 0;
		case 1:
		{Student* stud = NULL; step1(stud);} continue;
		case 2:
		{Student* score = infoscanf();
		if (score == 0) break;
		step2(score);}    continue;
		case 3:
		{Student* head = infoscanf();
		if (head == 0) break;
		step3(head); } continue;
		case 4:
		  {
			printf("关于系统：\n");
			printf("制作人员：作者均为中国海洋大学工程学院自动化专业学生：\n");
			printf("这些内容均由JasonAllen621及其同学所做。\n");;
			printf("完成后的话：这个系统肯定有不少缺漏。原本想做一个有图形界面的程序兼有完善的防爆功能，但是碍于技术和时间原因，\
				最终程序只能勉强实现基本功能。\n——Powered by Visual Studio 2019\n");
			printf(" 按0键以返回“操作菜单”页面 || 按除0外的任意数字键以结束程序 \n");
			scanf_s("%d", &found);
			getchar();
			if (found != 0) return 0;
		  }continue;
		}
	}
}

void step1(Student* stud)
{
	while (found1 == 0)
	{
		printf("***************************************************************************\n");
		printf("*                            学生资料管理                                 *\n");
		printf("*                         1.录入学生资料                                  *\n");
		printf("*                         2.删除学生资料                                  *\n");
		printf("*                         3.添加学生资料                                  *\n");
		printf("*                         4.修改学生资料                                  *\n");
		printf("*                         5.读取学生资料                                  *\n");
		printf("*                         0.返回                                          *\n");
		printf("*                                                                         *\n");
		printf("*                          按Enter键继续                                  *\n");
		printf("***************************************************************************\n");
		int number;
		scanf_s("%d", &number);
		switch (number)
		{
		case 0: return;
		case 1: {stud = input(); save(stud); }           continue;
		case 2: {
			Student* head = infoscanf();
			if (head == 0) break;
			int del_id;
			printf("请输入要删除成员的学号：");       //输入要删除的学号
			scanf_s("%d", &del_id);
			getchar();                        //此项是清除缓冲区内scanf函数输入的最后一个换行符'\n'，此后出现该语句作用相同
			delete0(head, del_id);         //调用删除函数
			save(head);
		}           continue;
		case 3: {
			Student* head = infoscanf();
			if (head == 0) break;
			Student in, * inser;
			int insert_num;                   //定义要插入的结点学号
			char dir;
			int i = 0;//定义前插后插的方向变量
			printf("请输入学生信息：");
			printf("学号：");
			scanf_s("%d", &in.id); getchar();
			printf("姓名：");
			scanf_s("%s", in.name, 30); getchar();
			printf("班级：");
			scanf_s("%f", &in.classnum); getchar();
			printf("分别输入五次测验成绩：\n");
			for (i = 0; i < 5; i++)
			{
				scanf_s("%f", &in.score[i]);
				printf("\0");
			}
			getchar();
			inser = &in;                        //结构体变量指针指向in
			printf("请输入要插入哪个学号：");               //输入要插入哪个学号
			scanf_s("%d", &insert_num);getchar();
			printf("在这个成员前（B）还是后（A）：");                   //输入是要插入学号前还是后，B是前插，A是后插。
			scanf_s("%c", &dir,1);getchar();
			int a = insert(&head, insert_num, dir, inser);          //调用插入函数
			if(a==1) save(head);
		}           continue;
		case 4: {
			Student* head = infoscanf();
			if (head == 0) break;
			int id;
			printf("请输入要修改学生的学号：");
			scanf_s("%d", &id); getchar();
			change(head, id); save(head); }           continue;
		case 5: {Student* head = infoscanf();
			if (head == 0) break;
			output(head); }           continue;
		}
	}
}

void step2(Student* score)
{

	while (found2 == 0)
	{
		printf("***************************************************************************\n");
		printf("*                            学生成绩分析                                 *\n");
		printf("*                         1.各科目成绩平均数                              *\n");
		printf("*                         2.各科目成绩中位数                              *\n");
		printf("*                         3.各科目成绩分布                                *\n");
		printf("*                         0.返回                                          *\n");
		printf("*                                                                         *\n");
		printf("*                          按Enter键继续                                  *\n");
		printf("***************************************************************************\n");
		int number;
		scanf_s("%d", &number);
		switch (number)
		{
		case 0: return;
		case 1: {
			aver(score);
		}           continue;
		case 2: {
			median(score);
		}          continue;
		case 3: {
			distribute(score);
		}          continue;
		}
	}
}

void step3(Student* head)
{
    Student* chaxun = head;
	while (found3 == 0)
	{
		printf("***************************************************************************\n");
		printf("*                            学生查询系统                                 *\n");
		printf("*                         1.按学号查询                                    *\n");
		printf("*                         2.按姓名查询                                    *\n");
		printf("*                         3.按所在班级查询                                *\n");
		printf("*                         0.返回                                          *\n");
		printf("*                                                                         *\n");
		printf("*                          按Enter键继续                                  *\n");
		printf("***************************************************************************\n");
		int number;
		scanf_s("%d", &number);
		switch (number)
		{
		case 0: return;
		case 1: {
			int chaxun_id;
			printf("请输入要查询成员的学号：");
			scanf_s("%d", &chaxun_id); getchar();
			chaxunid(chaxun, chaxun_id);
		}           continue;
		case 2: {
			char chaxun_name[30];
			printf("请输入要查询成员的姓名：");
			scanf_s("%s", chaxun_name, 30); getchar();
			chaxunname(chaxun, chaxun_name);
		}          continue;
		case 3: {
			float chaxun_class;
			printf("请输入要查询成员的班级：");
			scanf_s("%f", &chaxun_class); getchar();
			chaxunclass(chaxun,chaxun_class);
		}          continue;
		}
	}
}

void save(Student* stud)
{
	int i;
	FILE* in;errno_t err;
	err = fopen_s(&in, "studentinfo.txt", "w+");
	if(err>=0)
	{
		while (stud != NULL)
		{
			fprintf(in, "%d %-10s %.2f ", stud->id, stud->name, stud->classnum);
			for (i = 0; i < 5; i++) fprintf(in, " %.2f", stud->score[i]);
			fputs("\n", in);
			stud = stud->next;
		}
        fclose(in);
	}
	else
	{
		printf("文件打开失败。\n");
		return;
	}
}

Student* infoscanf()
{
	int n = 0, i;
	Student* p1, * p2, * head;
	p1 = p2 = (Student*)malloc(sizeof(Student));
	FILE* out; errno_t err;
	err = fopen_s(&out, "studentinfo.txt", "r");
	if (err == 0)
	{
		fscanf_s(out, "%d", &p1->id);
		if (p1->id <= 0)
		{
			printf("请输入学生信息后再执行该操作！\n");
			fclose(out);
			return 0;
		}
		fscanf_s(out, "%s", p1->name, 30);
		fscanf_s(out, "%f", &p1->classnum);
		for (i = 0; i < 5; i++)
			fscanf_s(out, "%f", &p1->score[i]);
         while (p1==NULL)
		{
			p1->next = NULL;
			return p1;
		}
	    head = NULL;
	    while (1)
	    {
		n++;
		if (n == 1) {
			head = p1;
			head->prev = NULL;
		}
		else
		{
			p2->next = p1;
			p1->prev = p2;
		}
		p2 = p1;
		p1 = (Student*)malloc(sizeof(Student));
		fscanf_s(out, "%d", &p1->id);
		fscanf_s(out, "%s", p1->name, 30);
		fscanf_s(out, "%f", &p1->classnum);
		for (i = 0; i < 5; i++)
			fscanf_s(out, "%f", &p1->score[i]);
           while (p1->id <= 0)
		   {
			  p2->next = NULL;
			  fclose(out);
			  return head;
		   }
	    }
	}
	else
	{
		printf("文件打开失败。\n");
		fclose(out);
		return NULL;
	}
}
