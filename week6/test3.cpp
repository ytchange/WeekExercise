//数组中求取某一段和最大的值


#include <iostream>
#include <assert.h>

using namespace std;
int GetMaxSum(int *arr,int len)
{
	assert(arr&&len>0);
	int curSum=0;
	int maxSum=0;
	for(int i=0;i<len;i++)
	{
		curSum+=arr[i];
		if(curSum<arr[i])
		{
			curSum=arr[i];
		}
		if(curSum>maxSum)
		{
			maxSum=curSum;
		}
	}
	return maxSum;
}

int main()
{
	int arr[]={1,-2,3,10,-4,7,2,-5};
	int len=sizeof(arr)/sizeof(arr[0]);
	int ret=GetMaxSum(arr,len);
	cout<<ret<<endl;
	return 0;
}
