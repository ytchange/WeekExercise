//查找一个数组中出现超过数组长度一半的数字
//可以设置一个times的变量初始值为1，当result得到的是相同的值则++，否则--；为0时result=arr[i],并且将times置1
#include <iostream>
#include <assert.h>
using namespace std;
bool checkMoreThanHalf(int *arr,int len,int result)//检测所得到的数是不是在数组中超过一半
{
	int times=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]==result)
		{
			times++;
		}
	}
	bool tmp=true;
	if((times*2)<=len)
	{
		tmp= false;
	}
	return tmp;
}

int MoreHalfNum(int *arr,int len)
{
	assert(arr);
	assert(len>0);
	int result=arr[0];
	int times=1;
	for(int i=1;i<len;i++)
	{
		if(times==0)
		{
			result=arr[i];
			times=1;
		}
		else if(result==arr[i])
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if(checkMoreThanHalf(arr,len,result)==true)
	{
		return result;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int arr[]={2,1,2,3,4,6,5,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	int ret=MoreHalfNum(arr,0);
	cout<<ret<<endl;
	return 0;
}
