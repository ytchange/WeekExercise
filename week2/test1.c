//给一个数组，将所有的放在前面，将所有的偶数放在后面

#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void reverse(int *arr,int len)
{
	int *begin=arr;
	int *end=arr+len-1;
	while(begin<end)
	{
		while(begin<end && (*begin)%2!=0)
		{
			begin++;
		}
		while(begin<end && (*end)%2==0)
		{
			end--;
		}
		if(begin<end)
		{
			swap(begin,end);
		}
	}
}
int main()
{
	int num,i;
	printf("please input size: ");
	scanf("%d",&num);
	int *arr=(int *)malloc(sizeof(int)*num);
	//此处定义的arr是个指向num空间的指针,所后面求长度是不能用sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	int len=num;
	reverse(arr,len);
	for(i=0;i<num;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
