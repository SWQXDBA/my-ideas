#include<stdio.h>
#define A 100
int main()
{
   int nowschool=0,nowfleet=0,nowpeople=0;
   int num;
   int i,j,k;
   int arr[A][A][10]={0};
   int allschoolcouont;
   int fleetcount[A];
   int all=0;//������
   int maxfleet=0;
	scanf("%d",&allschoolcouont);
	
for(i=0;i<allschoolcouont;i++)
{

scanf("%d",&fleetcount[i]);//��¼ÿ��ѧУ�ж���֧����
all+=fleetcount[i]*10;
if(fleetcount[i]>=maxfleet)
maxfleet=fleetcount[i];
}

////////////////////////////////////////////////////////
for(num=1;num<=all+10;num++)//���Ƶ�ǰ���
{
//getchar();

///////////////////////////////////////////////////////////////////////////////////





if(num!=1&&0==nowschool%allschoolcouont)//������ǰ����ѧУ
{
nowpeople++;
nowpeople%=10;
}
if(num!=1&&0==nowpeople%10&&0==nowschool)//������ǰ���ж���
{
nowfleet++;
}




	if(nowfleet<fleetcount[nowschool])
	{
		  if(nowfleet==maxfleet-1)
	   num++;
arr[nowschool][nowfleet][nowpeople]=num;
 
	}
	else if(num!=1)//���統ǰѧУû��������飬num���䣬��������һ��ѧУ��
	{
	num--;

	}


nowschool++;
nowschool%=allschoolcouont;





}









//printf("nowschool%d nowfleet%d nowpeople%d num%d\n",nowschool,nowfleet,nowpeople,num);
for( i=0;i<allschoolcouont;i++)
{
printf("#%d\n",i+1);
for(j=0;j<fleetcount[i];j++)
{
   for(k=0;k<10;k++)
   {
    printf("%d ",arr[i][j][k]);
   
   }
   printf("\n");

}
}








}