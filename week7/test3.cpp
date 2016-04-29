
//统计一个排序数组中某数字出现的次数
//运用二分查找的性质进行求解
#include <iostream>
#include <assert.h>
using namespace std;

//int CheckCount(int *arr,int len,int num)
//{
//	assert(arr!=NULL&&len>0&&arr[len-1]>=num&&arr[0]<=num);
//	int begin=0;
//	int end=len-1;
//	int mid=(begin+end)/2;
//	if(arr[mid]>num)
//	{
//		//num比中间值小则在左边
//		while(arr[mid]!=num)
//		{
//			mid--;
//		}
//		while(arr[begin]!=num)
//		{
//			begin++;
//		}
//		return mid-begin+1;
//	}
//	else if(arr[mid]<num)
//	{
//		//num比中间值大则在右边
//		while(arr[mid]!=num)
//		{
//			mid++;
//		}
//		while(arr[end]!=num)
//		{
//			end--;
//		}
//		return end-mid+1;
//	}
//	else
//	{
//		//num等于mid
//		int start=mid;
//		int over=mid;
//		while(arr[start]==num)
//		{
//			start--;
//		}
//		while(arr[over]==num)
//		{
//			over++;
//		}
//		return over-start-1;
//	}	
//}
//
//以上为最容易想到的办法，时间复杂度为O(n),效率不高，以下方法为二分递归，时间复杂度为Olog(n)
int getFirst(int *arr,int len,int num,int begin,int end)
{
	if(begin>end)
	{
		return -1;
	}
	int mid=(begin+end)/2;
	if(arr[mid]==num)
	{
		if(mid==begin || (mid>0 && arr[mid-1]!=num))
		{
			return mid;
		}
		else
		{
			end=mid-1;
		}
	}
	else if(arr[mid]>num)
	{
		end=mid-1;
	}
	else
	{
		begin=mid+1;
	}
	return getFirst(arr,len,num,begin,end);
}
int getLast(int *arr,int len,int num,int begin,int end)
{
	if(begin>end)
	{
		return -1;
	}
	int mid=(begin+end)/2;
	if(arr[mid]==num)
	{
		if(mid==end || (mid<len-1 && arr[mid+1]!=num))
		{
			return mid;
		}
		else
		{
			begin=mid+1;
		}
	}
	else if(arr[mid]>num)
	{
		end=mid-1;
	}
	else
	{
		begin=mid+1;
	}
	return getLast(arr,len,num,begin,end);

}
int getCount(int *arr,int len,int num)
{
	assert(arr!=NULL&&len>0&&arr[len-1]>=num&&arr[0]<=num);
	int begin=0;
	int end=len-1;
	int first=getFirst(arr,len,num,begin,end);
	//cout<<first<<endl;
	int last=getLast(arr,len,num,begin,end);
	//cout<<last<<endl;
	//if(first>-1&&last>-1)
	//{
		return last-first+1;
	//}
}
int main()
{
	//int arr[]={1,2,3,3,3,3,4,5};
	int arr[]={};
	int len=sizeof(arr)/sizeof(arr[0]);
	int num=5;
	int ret=getCount(arr,len,num);
	cout<<ret<<endl;
	return 0;
}
