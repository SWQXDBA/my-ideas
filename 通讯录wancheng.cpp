#include<stdio.h>
#include<string.h>
#define name_max 15
#define sex_max 15
#define number_max 15
#define address_max 15
void inputtel(struct teles *ps);
void delet(struct teles *ps);
void srch(struct teles *ps);
void printtel(struct teles *ps,int n);//��ӡ�����˵�����
void showtel(struct teles *ps);//��ӡ������Ϣ
void modtel(struct teles *ps);//�޸�
void savetel(struct teles *ps);//���浽txt�ļ�
int option(struct teles *ps);
struct telephone
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char number[number_max];
	char address[address_max];

};
struct teles
{
struct telephone tele[1000];
int telesize;
};
enum
{
   add=1,
   del,
   search,
   modify,
   show,
   save,
   exit
};
int main()
{
	struct teles tpne={0};
    struct teles *ps=&tpne;
	ps->telesize=0;
	while(option(ps))
	{
		getchar();
	}


return 0;
}








void inputtel(struct teles *ps)
{
	int n=ps->telesize;
struct telephone *ps2=&ps->tele[n];
	puts("���������֣�");

    scanf("%s",&ps2->name);
	puts("���������䣺");
    scanf("%d",&ps2->age);
	puts("�������Ա�");
    scanf("%s",&ps2->sex);
	puts("������绰���룺");
	
    scanf("%s",&ps2->number);
	puts("�������ַ��");

    scanf("%s",&ps2->address);
    ps->telesize++;
}
void delet(struct teles *ps)
{
	int flag=0;
	struct telephone *ps2;
	char name[name_max]={0};
	printf("������Ҫɾ�������֣�\n");
	scanf("%s",name);

for(int n=0;n<ps->telesize;n++)
{
	   ps2=&ps->tele[n];
     if(0==strcmp(ps2->name,name))
	 {
		 flag=1;
	   for(int i=n;i<ps->telesize;i++)
	   {
	   ps->tele[i]=ps->tele[i+1];
	   }
	 }
}
ps->telesize--;

if(flag==0)
printf("δ��ѯ��ָ��������,ɾ��ʧ�ܣ�\n");
}



void srch(struct teles *ps)
{
	int flag=0;
struct telephone *ps2;
	char name[name_max]={0};
	printf("������Ҫ���ҵ����֣�\n");
	scanf("%s",name);
for(int n=0;n<ps->telesize;n++)
{
	   ps2=&ps->tele[n];
     if(0==strcmp(ps2->name,name))
	 {
       printf("���֣�\t���䣺\t�Ա�\t�绰��\t\t��ַ��\t\n");
	   printtel(ps,n);
	   flag=1;  
	 }
}
if(flag==0)
printf("δ��ѯ��ָ��������\n");
}



void printtel(struct teles *ps,int n)
{
	struct telephone *ps2=&ps->tele[n];
	printf("%-s\t%-d\t%-s%\t%-s\t\t%-s\t\n",ps2->name,ps2->age,ps2->sex,ps2->number,ps2->address);

}



void showtel(struct teles *ps)
{
printf("���֣�\t���䣺\t�Ա�\t�绰��\t\t��ַ��\t\n");
for(int i=0;i<ps->telesize;i++)
{
printtel(ps,i);
}
}



void modtel(struct teles *ps)
{

	int flag=0;
struct telephone *ps2;
	char name[name_max]={0};
	 printf("������Ҫ�޸ĵ�������Ϣ\n");
	scanf("%s",name);
for(int n=0;n<ps->telesize;n++)
{
	   ps2=&ps->tele[n];
     if(0==strcmp(ps2->name,name))
	 {
	printf("�Ѳ�ѯ��Ŀ�꣬�������µ���Ϣ\n");
	  printf("���֣�\t���䣺\t�Ա�\t�绰��\t\t��ַ��\t\n");
	 printtel(ps,n);
	 	printf("�������µ���Ϣ\n");

	puts("���������֣�");
    scanf("%s",&ps2->name);
	puts("���������䣺");
    scanf("%d",&ps2->age);
	puts("�������Ա�");
    scanf("%s",&ps2->sex);
	puts("������绰���룺");
    scanf("%s",&ps2->number);
	puts("�������ַ��");
    scanf("%s",&ps2->address);

	   flag=1;  
	 }
}
if(flag==0)


printf("δ��ѯ��ָ��������\n");
}

void savetel(struct teles *ps)
{
	struct telephone *ps2;
	FILE *FP1;
	char name[name_max];
printf("�����뱣����ļ���\n");
	scanf("%s",name);
FP1=fopen(name,"w");
if(FP1!=NULL)
{
fprintf(FP1,"���֣�\t���䣺\t�Ա�\t�绰��\t\t��ַ��\t\n");
for(int i=0;i<ps->telesize;i++)
{
	ps2=&ps->tele[i];
	fprintf(FP1,"%-s\t%-d\t%-s%\t%-s\t\t%-s\t\n",ps2->name,ps2->age,ps2->sex,ps2->number,ps2->address);
}
printf("�������\n");
}
else printf("error,�޷������ļ�������\n");

}

int option(struct teles *ps)
{
	int n;
printf("�����������\n");
printf("1:add     2:del   3:search\n"
	   "4:modify  5:show  6:save\n"
	   "7:exit\n");
scanf("%d",&n);
switch(n)
{
case add: inputtel(ps);break;
case del: delet(ps);break;
case search: srch(ps);break;
case modify: modtel(ps);break;
case show: showtel(ps);break;
case save: savetel(ps);break;
case exit: return 0;break;
default:printf("����ѡ������������\n");break;
}
return 1;
}
/*
1
name1
15
nan
1512341251231
add1
1
name2
17
nv
141231222
add2
*/
