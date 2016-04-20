//旋转数组最小数字

#include <stdio.h>
#include <malloc.h>

int getMin(int *arr,int num)
{
	int begin=0;
	int end=num-1;
	int mid=0;
	while(arr[begin]>=arr[end])
	{
		mid=(begin+end)/2;
		if(arr[mid]>=arr[begin])
		{
			begin=mid;
		}
		else if(arr[mid]<=arr[end])
		{
			end=mid;
		}
		if(end-begin==1)
		{
			mid=end;
			return arr[mid];
		}
	}
}
int main()
{
	int num;
	printf("input size:");
	scanf("%d",&num);
	int *arr=(int *)malloc(sizeof(int)*num);
	int i=0;
	printf("init arr:");
	for(;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	int ret=getMin(arr,num);
	printf("%d\n",ret);
	return 0;
}
