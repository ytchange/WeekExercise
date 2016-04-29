
//在一个有序数组中找出和为目标值的两个数
#include <iostream>
using namespace std;


void FindNum(int *arr,int len,int num)
{
	int *begin=arr;
	int *end=arr+len-1;
	while(begin<end)
	{
		if(*begin+(*end)>num)
		{
			end--;
		}
		else if(*begin+(*end)<num)
		{
			begin++;
		}
		else
		{
			cout<<*begin<<" "<<*end<<endl;
			break;
		}
	}
}
int main()
{
	int arr[]={1,2,2,4,7,7,11,15};
	int len=sizeof(arr)/sizeof(arr[0]);
	int num=20;
	FindNum(arr,len,num);
	return 0;
}
