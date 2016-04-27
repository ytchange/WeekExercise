
//元素出入合法性检查

#include <iostream>
#include <stack>
using namespace std;

bool IsPoporder(int *pushOrder,int *popOrder,int length)
{
	if(pushOrder!=NULL&&popOrder!=NULL&&length>0)
	{
		stack<int> Stack;
		int *Ppush=pushOrder;
		int *Ppop=popOrder;
		while(Ppush-pushOrder<=length-1)
		{
			Stack.push(*Ppush);
			while(Stack.top()==*Ppop)
			{
				Stack.pop();
				if(Stack.empty()&&Ppop-popOrder==length-1)
				{
					return true;
				}
				Ppop++;
			}
			Ppush++;
		}
		return false;
	}
	return false;
}
int main()
{
	int num1=0;
	int num2=0;
	cout<<"please input the num of arr1:"<<endl;
	cin>>num1;
	cout<<"please input the num of arr2:"<<endl;
	cin>>num2;
	int *arr1=new int[num1];
	int *arr2=new int[num2];
	for(int i=0;i<num1;i++)
	{
		cin>>arr1[i];
	}
	for(int i=0;i<num2;i++)
	{
		cin>>arr2[i];
	}
	bool ret=IsPoporder(arr1,arr2,num1);
	for(int i=0;i<num1;i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<num2;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
	if(ret==true)
	{
		cout<<"合法"<<endl;
	}
	else
	{
		cout<<"不合法"<<endl;
	}
	return 0;
}
