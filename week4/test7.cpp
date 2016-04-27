
//输入一个字符串，打印出个字符的全排列

#include <iostream>
#include <stdio.h>
using namespace std;

void myAllPrint(char *ptr,char *begin)
{
	if(*begin=='\0')
	{
		cout<<ptr<<endl;
	}
	else
	{
		char *pmov=begin;
		for(;*pmov!='\0';pmov++)
		{
			char tmp=*pmov;
			*pmov=*begin;
			*begin=tmp;
			myAllPrint(ptr,begin+1);
			tmp=*pmov;
			*pmov=*begin;
			*begin=tmp;
		}
	}
}
void allPrint(char *arr)
{
	if(arr==NULL)
	{
		return;
	}
	myAllPrint(arr,arr);
}
int main()
{
	char arr[10]={'\0'};
	gets(arr);
	allPrint(arr);
	//arr[3]='v';
//	cout<<arr<<endl;
}
