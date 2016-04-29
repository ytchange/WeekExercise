
//在数组中查找所有的逆序数对
#include <iostream>

using namespace std;

int FindNum(int *arr,int len)
{
	int count=0;
	for(int i=0;i<len-1;i++)
	{
		int cur=arr[i];
		for(int j=i+1;j<len;j++)
		{
			if(cur>arr[j])
			{
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int arr[]={7,5,6,8};
	int len=sizeof(arr)/sizeof(arr[0]);
	int ret=FindNum(arr,len);
	cout<<ret<<endl;
	return 0;
}
