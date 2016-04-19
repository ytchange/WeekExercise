
//将字符串中的空格替换成20%

#include <stdio.h>
#include <string.h>
void replace(char buf[],int size)
{
	int count=0,i=0;
	while(buf[i]!='\0')
	{
		if(buf[i]==' ')
		{
			count++;
		}
		i++;
	}
	int index1=size-1;
	int index2=(size+count*2)-1;
	while(index1>=0)
	{
		if(buf[index1]==' ')
		{
			buf[index2]='%';
			buf[--index2]='0';
			buf[--index2]='2';
			index1--;
			index2--;
		}
		else
		{
			buf[index2]=buf[index1];
			index1--;
			index2--;
		}
	}

	//printf("%s,%d,%d\n",buf,count,size);
}
int main()
{
	char buf[100];
	memset(buf,'\0',sizeof(buf));
	gets(buf);
	int len=strlen(buf);
	replace(buf,len);
	printf("%s\n",buf);
	return 0;
}
