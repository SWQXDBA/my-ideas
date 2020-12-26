#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class myroom
{
	

public:
	void change();
	string findclassroom();
	string findstreat();
	string findbadroom();
	myroom();
public:
	string streat;
private:
	string badroom;
	string classroom;

};


class myfriend
{
	friend void test();
	friend void myroom::change();

public:
	myfriend();
	void changeroom();
	string showbadroom()
	{
		return room->findbadroom();
	}
	string showclassroom()
	{
		return room->findclassroom();
	}
	string showstreat()
	{
		return room->findstreat();
	}
private:
	myroom* room;
	
};
string myroom:: findclassroom()
{
	return classroom;
}
string myroom:: findstreat()
{
	return streat;

}
string myroom::findbadroom()
{
	return badroom;

}
myroom::myroom()
{

	streat = "街头 ";
	badroom = "卧室 ";
	classroom = "教室 ";
}
myfriend::myfriend()
{
	 room= new myroom;

}
void myroom::change()
{
   
	cout << "请输入streat" << endl;
	cin >> streat;
	cout << "请输入badroom" << endl;
	cin >> badroom;
	cout << "请输入classroom" << endl;
	cin >> classroom;


}
void myfriend::changeroom()
{
	room->change();

}
void test()
{
	myfriend xm;
	cout << xm.showbadroom() <<"\t"<< xm.showclassroom() << "\t" << xm.showstreat() << endl;

	cout << "现在进行修改" << endl;
	xm.changeroom();
	cout << xm.showbadroom() << "\t" << xm.showclassroom() << "\t" << xm.showstreat() << endl;



}

int main()
{
	test();
	getchar();
	getchar();

return 0;



}
