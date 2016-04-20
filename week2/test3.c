//1到最大的N位十进制

#include <stdio.h>
int getMax(int num)
{
	int i=0;
	int maxNum=0;
	for(;i<num;i++)
	{
		maxNum=maxNum*10+9;
	}
	return maxNum;
}
int main()
{
	int num=0;
	printf("input:");
	scanf("%d",&num);
	int ret=getMax(num);
	int i=1;
	for(;i<=ret;i++)
	{
		printf("%d、",i);
	}
	printf("\n");
	return 0;
}
