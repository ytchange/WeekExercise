//该矩阵行从左向右增长，列从上往下增长，在该矩阵中查找目标值是否存在

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void creat_arr(int **arr,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int count=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(count%n==0)
			{
				printf("\n");
			}
			printf("%d ",arr[i][j]);
			count++;
		}
	}
	printf("\n");
}
int find_num(int **arr,int num,int m,int n)
{
	//通过二维数组的特点可知，从右上角遍历效率最高
	int i=0;
	int j=n-1;
	while(j>=0 && i<=m-1)
	{
		//printf("%d->",arr[i][j]); //打印查找路径检测
		if(arr[i][j]<num)
		{
			i++;
		}
		else if(arr[i][j]>num)
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return -1;

}
int main()
{
	int m,n,i;
	int num=0;
	printf("input row and col:");
	scanf("%d %d",&m,&n);
	int **arr=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
	{
		arr[i]=(int *)malloc(sizeof(int)*n);		
	}
	printf("input arr num:\n");
	creat_arr(arr,m,n);
	printf("input find num:\n");
	scanf("%d",&num);
	int ret=find_num(arr,num,m,n);
	if(ret==1)
	{
		printf("yes\n");
	}
	else
		printf("no\n");
	return 0;
}
