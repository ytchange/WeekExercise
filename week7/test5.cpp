
//找出数组中只有两个出现一次的数字
//与在数组中只一个出现一次的数组解法相似

#include <iostream>
#include <assert.h>
using namespace std;

bool Check(int num,int index)
{
	num=num>>index;
	if((num&1)==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int FindIndex(int result)
{
	int count=0;
	//注意运算符的优先级，==高于&
	while((result&1)==0 && count<=32)
	{
		result=result>>1;
		count++;
	}
	return count;
}
//num1和num2是连个输出型参数
void FindTwoNum(int *arr,int len,int *num1,int *num2)
{
	assert(arr!=NULL&&len>0);
	int result=0;
	for(int i=0;i<len;i++)
	{
		result^=arr[i];
	}
	//cout<<result<<endl;
	//找到result右边为1是第几位
	int index=FindIndex(result);
	//将一个数组拆分为两个，一个是改位为1，一个是该位不为1
	//cout<<index<<endl;
	for(int i=0;i<len;i++)
	{
		if(Check(arr[i],index)==true)//是1
		{
			(*num1)^=arr[i];
		}
		else//不是1
		{
			(*num2)^=arr[i];
		}
	}
}

int main()
{
	int num1=0;
	int num2=0;
	int arr[]={2,4,3,6,3,2,5,5};
	int len=sizeof(arr)/sizeof(arr[0]);
	FindTwoNum(arr,len,&num1,&num2);
	cout<<num1<<","<<num2<<endl;
	return 0;
}
