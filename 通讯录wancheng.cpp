#include<stdio.h>
#include<string.h>
#include <cstdlib>

#define name_max 15
#define sex_max 15
#define number_max 15
#define address_max 15
void inputtel(struct teles *ps);
void delet(struct teles *ps);
void srch(struct teles *ps);
void printtel(struct teles *ps,int n);//打印单个人的数据
void showtel(struct teles *ps);//打印所有信息
void modtel(struct teles *ps);//修改
void savetel(struct teles *ps);//保存到txt文件
int option(struct teles *ps);
void load(struct teles *ps);
void expand(teles *pTeles);

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
    struct telephone *tele = (struct telephone* ) malloc(sizeof(struct telephone)*1);
    int telesize;
    int maxLength= 1;
};
enum
{
    add=1,
    del,
    search,
    modify,
    show,
    save,
    ex
};
int main()
{
    struct teles tpne;
    struct teles *ps=&tpne;
    ps->telesize=0;
    load(ps);
    while(option(ps))
    {
        getchar();
    }


    return 0;
}








void inputtel(struct teles *ps)
{
    if(ps->telesize==ps->maxLength){
        expand(ps);
    }
    int n=ps->telesize;
    struct telephone *ps2=&ps->tele[n];
    puts("请输入名字：");

    scanf("%s",&ps2->name);
    puts("请输入年龄：");
    scanf("%d",&ps2->age);
    puts("请输入性别：");
    scanf("%s",&ps2->sex);
    puts("请输入电话号码：");

    scanf("%s",&ps2->number);
    puts("请输入地址：");

    scanf("%s",&ps2->address);
    ps->telesize++;
}

void expand(teles *ps) {
    printf("触发扩容\n");
    telephone * temp = (telephone *)realloc(ps->tele,ps->maxLength*2*sizeof(telephone));
    if(temp!=NULL){
        ps->tele=temp;
        ps->maxLength*=2;
    }else{
        printf("扩容失败！程序结束");
        return;
    }


}

void delet(struct teles *ps)
{
    int flag=0;
    struct telephone *ps2;
    char name[name_max]={0};
    printf("请输入要删除的名字：\n");
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
        printf("未查询到指定的名称,删除失败！\n");
}



void srch(struct teles *ps)
{
    int flag=0;
    struct telephone *ps2;
    char name[name_max]={0};
    printf("请输入要查找的名字：\n");
    scanf("%s",name);
    for(int n=0;n<ps->telesize;n++)
    {
        ps2=&ps->tele[n];
        if(0==strcmp(ps2->name,name))
        {
            printf("名字：\t年龄：\t性别：\t电话：\t\t地址：\t\n");
            printtel(ps,n);
            flag=1;
        }
    }
    if(flag==0)
        printf("未查询到指定的名称\n");
}



void printtel(struct teles *ps,int n)
{
    struct telephone *ps2=&ps->tele[n];
    printf("%-s\t%-d\t%-s%\t%-s\t\t%-s\t\n",ps2->name,ps2->age,ps2->sex,ps2->number,ps2->address);

}



void showtel(struct teles *ps)
{
    printf("名字：\t年龄：\t性别：\t电话：\t\t地址：\t\n");
    for(int i=0;i<ps->telesize;i++)
    {
        printtel(ps,i);
    }
    printf("max = %d size = %d\n",ps->maxLength,ps->telesize);
}



void modtel(struct teles *ps)
{

    int flag=0;
    struct telephone *ps2;
    char name[name_max]={0};
    printf("请输入要修改的人名信息\n");
    scanf("%s",name);
    for(int n=0;n<ps->telesize;n++)
    {
        ps2=&ps->tele[n];
        if(0==strcmp(ps2->name,name))
        {
            printf("已查询到目标，请输入新的信息\n");
            printf("名字：\t年龄：\t性别：\t电话：\t\t地址：\t\n");
            printtel(ps,n);
            printf("请输入新的信息\n");

            puts("请输入名字：");
            scanf("%s",&ps2->name);
            puts("请输入年龄：");
            scanf("%d",&ps2->age);
            puts("请输入性别：");
            scanf("%s",&ps2->sex);
            puts("请输入电话号码：");
            scanf("%s",&ps2->number);
            puts("请输入地址：");
            scanf("%s",&ps2->address);

            flag=1;
        }
    }
    if(flag==0)


        printf("未查询到指定的名称\n");
}

void savetel(struct teles *ps)
{
    struct telephone *ps2;
    FILE *FP1;
    char name[name_max] = "DATA.txt";
    //printf("请输入保存的文件名\n");
   // scanf("%s",name);
    FP1=fopen(name,"w");
    if(FP1!=NULL)
    {
       // fprintf(FP1,"名字：\t年龄：\t性别：\t电话：\t\t地址：\t\n");
        for(int i=0;i<ps->telesize;i++)
        {
            ps2=&ps->tele[i];
            fprintf(FP1,"%s %d %s %s %s",ps2->name,ps2->age,ps2->sex,ps2->number,ps2->address);
        }
        printf("保存完成\n");
    }
    else printf("error,无法创建文件！！！\n");

}
void load(struct teles *ps){
    FILE *FP1;
    char name[name_max] = "DATA.txt";
    FP1 = fopen(name,"r");
    struct telephone ps2;
    if(FP1!=NULL){
        while(fscanf(FP1,"%s %d %s %s %s",&ps2.name,&ps2.age,&ps2.sex,&ps2.number,&ps2.address)!=EOF){
            (ps->tele[ps->telesize])=ps2;
            ps->telesize++;
        }

    }else printf("未找到文件");
}
int option(struct teles *ps)
{
    int n;

    printf("请输入操作：\n");
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
        case ex: return 0;break;
        default:printf("输入选项有误，请重输\n");break;
    }
    return 1;
}




