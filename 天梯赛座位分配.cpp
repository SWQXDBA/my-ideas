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
   int all=0;//总人数
   int maxfleet=0;
	scanf("%d",&allschoolcouont);
	
for(i=0;i<allschoolcouont;i++)
{

scanf("%d",&fleetcount[i]);//记录每个学校有多少支队伍
all+=fleetcount[i]*10;
if(fleetcount[i]>=maxfleet)
maxfleet=fleetcount[i];
}

////////////////////////////////////////////////////////
for(num=1;num<=all+10;num++)//控制当前序号
{
//getchar();

///////////////////////////////////////////////////////////////////////////////////





if(num!=1&&0==nowschool%allschoolcouont)//结束当前所有学校
{
nowpeople++;
nowpeople%=10;
}
if(num!=1&&0==nowpeople%10&&0==nowschool)//结束当前所有队伍
{
nowfleet++;
}




	if(nowfleet<fleetcount[nowschool])
	{
		  if(nowfleet==maxfleet-1)
	   num++;
arr[nowschool][nowfleet][nowpeople]=num;
 
	}
	else if(num!=1)//假如当前学校没有这个队伍，num不变，继续找下一个学校。
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