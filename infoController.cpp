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
		printf("*                             �����˵�                                    *\n");
		printf("*                         1.ѧ�����Ϲ���                                  *\n");
		printf("*                         2.ѧ���ɼ�����                                  *\n");
		printf("*                         3.ѧ����ѯϵͳ                                  *\n");
		printf("*                         4.����ϵͳ                                      *\n");
		printf("*                         0.�˳�ϵͳ                                      *\n");
		printf("*                                                                         *\n");
		printf("*                          ��Enter������                                  *\n");
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
			printf("����ϵͳ��\n");
			printf("������Ա�����߾�Ϊ�й������ѧ����ѧԺ�Զ���רҵѧ����\n");
			printf("��Щ���ݾ���JasonAllen621����ͬѧ������\n");;
			printf("��ɺ�Ļ������ϵͳ�϶��в���ȱ©��ԭ������һ����ͼ�ν���ĳ���������Ƶķ������ܣ����ǰ��ڼ�����ʱ��ԭ��\
				���ճ���ֻ����ǿʵ�ֻ������ܡ�\n����Powered by Visual Studio 2019\n");
			printf(" ��0���Է��ء������˵���ҳ�� || ����0����������ּ��Խ������� \n");
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
		printf("*                            ѧ�����Ϲ���                                 *\n");
		printf("*                         1.¼��ѧ������                                  *\n");
		printf("*                         2.ɾ��ѧ������                                  *\n");
		printf("*                         3.���ѧ������                                  *\n");
		printf("*                         4.�޸�ѧ������                                  *\n");
		printf("*                         5.��ȡѧ������                                  *\n");
		printf("*                         0.����                                          *\n");
		printf("*                                                                         *\n");
		printf("*                          ��Enter������                                  *\n");
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
			printf("������Ҫɾ����Ա��ѧ�ţ�");       //����Ҫɾ����ѧ��
			scanf_s("%d", &del_id);
			getchar();                        //�����������������scanf������������һ�����з�'\n'���˺���ָ����������ͬ
			delete0(head, del_id);         //����ɾ������
			save(head);
		}           continue;
		case 3: {
			Student* head = infoscanf();
			if (head == 0) break;
			Student in, * inser;
			int insert_num;                   //����Ҫ����Ľ��ѧ��
			char dir;
			int i = 0;//����ǰ����ķ������
			printf("������ѧ����Ϣ��");
			printf("ѧ�ţ�");
			scanf_s("%d", &in.id); getchar();
			printf("������");
			scanf_s("%s", in.name, 30); getchar();
			printf("�༶��");
			scanf_s("%f", &in.classnum); getchar();
			printf("�ֱ�������β���ɼ���\n");
			for (i = 0; i < 5; i++)
			{
				scanf_s("%f", &in.score[i]);
				printf("\0");
			}
			getchar();
			inser = &in;                        //�ṹ�����ָ��ָ��in
			printf("������Ҫ�����ĸ�ѧ�ţ�");               //����Ҫ�����ĸ�ѧ��
			scanf_s("%d", &insert_num);getchar();
			printf("�������Աǰ��B�����Ǻ�A����");                   //������Ҫ����ѧ��ǰ���Ǻ�B��ǰ�壬A�Ǻ�塣
			scanf_s("%c", &dir,1);getchar();
			int a = insert(&head, insert_num, dir, inser);          //���ò��뺯��
			if(a==1) save(head);
		}           continue;
		case 4: {
			Student* head = infoscanf();
			if (head == 0) break;
			int id;
			printf("������Ҫ�޸�ѧ����ѧ�ţ�");
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
		printf("*                            ѧ���ɼ�����                                 *\n");
		printf("*                         1.����Ŀ�ɼ�ƽ����                              *\n");
		printf("*                         2.����Ŀ�ɼ���λ��                              *\n");
		printf("*                         3.����Ŀ�ɼ��ֲ�                                *\n");
		printf("*                         0.����                                          *\n");
		printf("*                                                                         *\n");
		printf("*                          ��Enter������                                  *\n");
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
		printf("*                            ѧ����ѯϵͳ                                 *\n");
		printf("*                         1.��ѧ�Ų�ѯ                                    *\n");
		printf("*                         2.��������ѯ                                    *\n");
		printf("*                         3.�����ڰ༶��ѯ                                *\n");
		printf("*                         0.����                                          *\n");
		printf("*                                                                         *\n");
		printf("*                          ��Enter������                                  *\n");
		printf("***************************************************************************\n");
		int number;
		scanf_s("%d", &number);
		switch (number)
		{
		case 0: return;
		case 1: {
			int chaxun_id;
			printf("������Ҫ��ѯ��Ա��ѧ�ţ�");
			scanf_s("%d", &chaxun_id); getchar();
			chaxunid(chaxun, chaxun_id);
		}           continue;
		case 2: {
			char chaxun_name[30];
			printf("������Ҫ��ѯ��Ա��������");
			scanf_s("%s", chaxun_name, 30); getchar();
			chaxunname(chaxun, chaxun_name);
		}          continue;
		case 3: {
			float chaxun_class;
			printf("������Ҫ��ѯ��Ա�İ༶��");
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
		printf("�ļ���ʧ�ܡ�\n");
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
			printf("������ѧ����Ϣ����ִ�иò�����\n");
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
		printf("�ļ���ʧ�ܡ�\n");
		fclose(out);
		return NULL;
	}
}
