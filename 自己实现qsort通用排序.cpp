#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student{
	char name[10];
	int age;
}stu;
void myqsort(void *arr,size_t size,int count,int (*p)(const void *,const void *))
{
	for (int i = 0; i < count-1; i++)
	{
		int flag = 0;
		for (int j = count-2; j >=i; j--)
		{
			if (p(((char*)arr + size*j), ((char*)arr + size*(j + 1))) < 0)
			{
				for (int k = 0; k < size; k++)
				{
					char temp = *((char*)arr + size*j + k);
					*((char*)arr + size*j + k) = *((char*)arr + size*(j + 1) + k);
					*((char*)arr + size*(j + 1) + k) = temp;
				}
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
int comparename(const void *a, const void *b)
{
	stu stu1 = *((stu*)a);
	stu stu2 = *((stu*)b);
	
	return -strcmp(stu1.name, stu2.name);

}
int compareage(const void *a, const void *b)
{
	stu stu1 = *((stu*)a);
	stu stu2 = *((stu*)b);
	return stu1.age >= stu2.age ? -1 : 1;

}
int main()
{
	stu students[4] = { { "diaoming", 15 }, { "baming", 5 }, { "cing", 20 }, { "aihua", 1 } };
	for (int i = 0; i < 4; i++)
	{
		printf("name %s,age %d\n", students[i].name, students[i].age);
	}
	myqsort(students, sizeof(student), 4, compareage);
	puts("进行年龄排序");
	for (int i = 0; i < 4; i++)
	{
		printf("name %s,age %d\n", students[i].name, students[i].age);
	}
	puts("进行姓名排序");
	myqsort(students, sizeof(student), 4, comparename);
	for (int i = 0; i < 4; i++)
	{
		printf("name %s,age %d\n", students[i].name, students[i].age);
	}
	system("pause");

	return 0;

}
