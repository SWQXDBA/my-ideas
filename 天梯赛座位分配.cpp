//
#include<stdio.h>
#define A 100
int main()
{
   int nowschool=0,nowfleet=0,nowpeople=0;
   int num=1;;
   int i,j,k;
   int arr[A][A][10]={0};
   int allschoolcouont;
   int fleetcount[A];
   int all=0;//总人数
   int maxfleet=0;
   int maxcount=0;
   int count;
   int havefleet[100]={0};//用来记录队伍数为i的学校有几个。
	scanf("%d",&allschoolcouont);
for(i=0;i<allschoolcouont;i++)
{
scanf("%d",&fleetcount[i]);//记录每个学校有多少支队伍
all+=fleetcount[i]*10;
}

for(i=0;i<allschoolcouont;i++)
{
for(j=0;j<fleetcount[i];j++)
{
havefleet[j]++;
}//记录每个学校有多少支队伍

}


///////////////////////////以下为赋值/////////////////////////////

for( i=0;i<allschoolcouont;i++)
{
	num=i+1;
for(j=0;j<fleetcount[i];j++)
{
	count=0;
	if(j!=0&&havefleet[j-1]!=1&&havefleet[j]!=1)
	{
		
		for(k=i+1;k<allschoolcouont;k++)
		{
		   if(j-1<=fleetcount[k]-1)
			   count++;
		}
   		for(k=0;k<=i;k++)
		{
		   if(j<=fleetcount[k]-1)
			   count++;
		}
	num=num+count;
	}
	else if(j!=0)
     num=num+2;

   for(k=0;k<10;k++)
   {
    arr[i][j][k]=num;
	if(havefleet[j]!=1&&k!=9)
	num=num+havefleet[j];
	else if(k!=9)
     num=num+2;
   }


}
}









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

