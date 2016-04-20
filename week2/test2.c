//输出一个整数中二进制1的个数

#include <stdio.h>
//int retNum(int num)
//{
//	int count=0;
//	while(num)
//	{
//		int ret=num&1;
//		if(ret==1)
//		{
//			count++;
//		}
//		num>>=1;
//	}
//	return count;
//}
int retNum(int num)
{
	int count=0;
	while(num)
	{
		count++;
		n=(n-1)&n;
	}
	return count;
}
int main()
{
	int num=0;
	printf("please input:");
	scanf("%d",&num);
	int ret=retNum(num);
	printf("%d\n",ret);
	return 0;
}
