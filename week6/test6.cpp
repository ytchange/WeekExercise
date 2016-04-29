//找出字符串中第一个只出现一次的字符

#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;


char getFistCh(char *buf)
{
	assert(buf);
	unsigned int arr[256];
	for(int i=0;i<256;i++)
	{
		arr[i]=0;
	}
	int index=0;
	while(buf[index]!='\0')
	{
		arr[buf[index]]++;
		index++;
	}
	index=0;
	while(buf[index]!='\0')
	{
		if(arr[buf[index]]==1)
		{
			return buf[index];
		}
		index++;
	}
	return '\0';
}
int main()
{
	char buf[100];
	gets(buf);
	char ch=getFistCh(buf);
	cout<<ch<<endl;
	return 0;
}
