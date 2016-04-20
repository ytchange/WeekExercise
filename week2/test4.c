//婓波拉切数列

#include <stdio.h>

//long long feb(unsigned int num)
//{
//	if(num==1||num==0)
//	{
//		return num;
//	}
//	return feb(num-1)+feb(num-2);
//}
//非递归解法
long long feb(unsigned int num)
{
	if(num<2)
	{
		return num;
	}
	int i;
	long long one=0;
	long long two=1;
	long long target=0;
	for(i=2;i<=num;i++)
	{
		target=one+two;
		one=two;
		two=target;
	}
	return target;
}
int main()
{
	unsigned int num=0;
	scanf("%ud",&num);
	long long ret=feb(num);
	printf("%ld\n",ret);
	return 0;
}
