//string类深拷贝问题

#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
	public:
	MyString();
	MyString(const char *str);
	~MyString();
	MyString(const MyString &s);
	//MyString& operator=(const MyString &s);
	MyString& operator=(MyString &s);
	void swap(MyString &s);
	void print()
	{
		cout<<ptr<<endl;
	}
	private:
	char* ptr;
};

//MyString::MyString()
//{
//	ptr=NULL;
//}
//MyString::MyString(const char *str)
//{
//	ptr=new char[sizeof(str)];
//	strcpy(ptr,str);
//}
//MyString::MyString(const MyString &s)
//{
//	ptr=new char[sizeof(s.ptr)];
//	strcpy(ptr,s.ptr);
//}
//MyString::~MyString()
//{
//	if(ptr)
//	{
//		delete[] ptr;
//		ptr=NULL;
//	}
//}
//MyString& MyString::operator=(const MyString &s)
//{
//	if(this!=&s)
//	{
//		delete[] ptr;
//		ptr=new char[sizeof(s.ptr)];
//		strcpy(ptr,s.ptr);
//		return *this;
//	}
//}

MyString::MyString()
{
	ptr=NULL;
}
MyString::MyString(const char *str)
{
	ptr=new char[sizeof(str)];
	strcpy(ptr,str);
}
void MyString::swap(MyString &s)
{
	char *tmp=s.ptr;
	s.ptr=ptr;
	ptr=tmp;
}
MyString::MyString(const MyString &s)
{
	ptr=NULL;
	MyString tmp(s.ptr);
	swap(tmp);
}
MyString::~MyString()
{
	if(ptr)
	{
		delete[] ptr;
		ptr=NULL;
	}
}

MyString& MyString::operator=(MyString &s)  //这种方法不会改变源拷贝者的内容
{
	if(this!=&s)
	{
		MyString tmp(s.ptr);
		swap(tmp);
		return *this;
	}
}
//MyString& MyString::operator=(MyString &s) //这种方法会将源拷贝者的内容发生改变；
//{
//	swap(s);
//	return *this;
//}
int main()
{
	MyString s1("hello");
	s1.print();
	MyString s2(s1);
	s2.print();
	s1.print();
	MyString s3("bit");
	s3=s1;
	s3.print();
	s1.print();
	return 0;
}
