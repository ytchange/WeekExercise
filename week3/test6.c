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
void printCircle(int  **arr,int m,int n,int start)
{
	int endx=n-1-start;
	int endy=m-1-start;
	int i=0;
	for(i=start;i<=endx;i++)
	{
		int num=arr[start][i];
		printf("%d ",num);
	}
	if(start<endy)
	{
		for(i=start+1;i<=endy;i++)
		{
			int num=arr[i][endx];
			printf("%d ",num);
		}
	}
	if(start<endx&&start<endy)
	{
		for(i=endx-1;i>=start;i--)
		{
			int num=arr[endy][i];
			printf("%d ",num);
		}
	}
	if(start<endx&&start<endy-1)
	{
		for(i=endy-1;i>=start+1;i--)
		{
			int num=arr[i][start];
			printf("%d ",num);
		}
	}
}
void printMatrix(int **arr,int m,int n)
{
	if(arr==NULL||m<=0||n<=0)
	{
		return;
	}
	int start=0;
	while(m>start*2&&n>start*2)
	{
		printCircle(arr,m,n,start);
		start++;
	}
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
	printMatrix(arr,m,n);
	return 0;
}
