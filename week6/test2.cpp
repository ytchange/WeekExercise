//找出数组中最小的k个数，采用堆这个结构来解决
//建K大小的大堆，然后将数组中的元素和堆顶元素比较，
//小于则替换，到数组末尾，则堆中K个数为最小的K个数

#include <iostream>
using namespace std;

void adjustDown(int *p,int k,int root)
{
	int left=root*2+1;
	int right=left+1;
	while(left<k)
	{
		int max=left;
		if(right<k&&p[right]>p[left])
		{
			max=right;
		}
		if(p[root]<p[max])
		{
			swap(p[root],p[max]);
			root=max;
			left=root*2+1;
			right=left+1;
		}
		else
		{
			break;
		}
	}
}
void LessKNum(int *arr,int len,int k)
{
	if(arr==NULL||len<=0||k<=0)
	{
		return;
	}
	int *p=new int[k];
	for(int i=0;i<k;i++)
	{
		p[i]=arr[i];
	}
	int begin=(k-2)/2;
	for(;begin>=0;begin--)
	{
		adjustDown(p,k,begin);
	}
	for(int i=k;i<len;i++)
	{
		int tmp=arr[i];
		if(tmp<=p[0])
		{
			swap(tmp,p[0]);
			adjustDown(p,k,0);
		}
	}
	for(int j=0;j<k;j++)
	{
		cout<<p[j]<<" ";
	}
	cout<<endl;
	delete[] p;
}

int main()
{
	int arr[]={3,3,4,9,5,2,3};
	int len=sizeof(arr)/sizeof(arr[0]);
	LessKNum(arr,len,5);
	return 0;
}
