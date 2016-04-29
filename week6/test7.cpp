//在第一个字符串中删除第二个字符串出现的所有字符

#include <iostream>
#include <stdio.h>
using namespace std;
void deleteCh(char *buf1,char *buf2)
{
	char arr[256];
	for(int i=0;i<256;i++)
	{
		arr[i]=0;
	}
	while(*buf2!='\0')
	{
		arr[*buf2]++;
		buf2++;
	}
	
	char *buf=buf1;
	int cur=0;	
	int back=0;
	while(buf[back]='\0')
	{
		if(arr[buf[back]]==0)
		{
			buf1[cur]=buf1[back];
			cur++;
			back++;
		}
		else
		{
			back++;
		}
	}
	buf1[cur]='\0';
}
int main()
{
	char buf1[1000];
	gets(buf1);
	char buf2[1000];
	gets(buf2);
	deleteCh(buf1,buf2);
	puts(buf1);
	return 0;
}
