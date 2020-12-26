#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class myint
{
public:
	myint() :a(0), b(0)
	{}
	myint(int num1, int num2) :a(0), b(0)
	{
		a = num1;
		b = num2;
	}
	~myint()
	{
		cout << "myint的析构调用" << endl;



	}
	int a;
	int b;
};
ostream& operator<<(ostream& ct,  myint &p)
//或者   ostream& operator<<(ostream& ct,  myint p)
//这里注意，ostream& operator<<(ostream& ct, myint &p)是不行的，因为myint++返回的是一个temp匿名变量，是一个“右值”，普通引用只能接收一个可修改的左值。
{
	ct << p.a << p.b << endl;
	return ct;
}


myint& operator++(myint& aint)
{
	aint.a++;
	aint.b++;
	return aint;

}
myint operator++(myint& aint, int)
{
	myint temp = aint;
	aint.a++;
	aint.b++;
	return temp;
}
void test()
{
	myint ps1(2, 5);
	cout << ps1;
	cout << ++ps1;

	cout << ps1;
	cout << "end" << endl;
}
int main()
{
	test();
	getchar();
	getchar();

}
