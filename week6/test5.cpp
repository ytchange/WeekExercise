//查找第num个丑数是多少
//
//普通解法就是从1开始每个数都判断一下，直到查找到第num个丑数
//此办法判断的效率非常低，所以不是好的解法
//#include <iostream>
//using namespace std;
//bool isUgly(int target)
//{
//	while(target%2==0)
//	{
//		target/=2;
//	}
//	while(target%3==0)
//	{
//		target/=3;
//	}
//	while(target%5==0)
//	{
//		target/=5;
//	}
//	if(target==1)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int getTargetNum(int num)
//{
//	if(num<=0)
//	{
//		return 0;
//	}
//	int index=0;//计数到目标个数
//	int target=0;//目标个数个丑数
//	while(index<num)
//	{
//		target++;
//		if(isUgly(target))
//		{
//			index++;
//		}
//	}
//	return target;
//}
//int main()
//{
//	int num=0;
//	cin>>num;
//	int ret=getTargetNum(num);
//	cout<<ret<<endl;
//
//	return 0;
//}


//第二种办法，就是每一个丑数都是通过其他丑数*2，*3，*5得到的
//因此可以创建一个num大小的数组，按照大小顺序将丑数存储起来，则最后一个数则为目标丑数
#include<iostream>
using namespace std;
int Min(int a,int b,int c)
{
	int tmp=(a<b?a:b);
	return (tmp<c?tmp:c);
}

int getTargetNum(int num)
{
	int *p=new int[num];
	p[0]=1;
	int index1=0;
	int index2=0;
	int index3=0;
	int index=1;
	while(index<num)
	{
		int val=Min(p[index1]*2,p[index2]*3,p[index3]*5);//每次得到三个数中最小的，并将其index++；直到找到第num个丑数
		if(val==p[index1]*2)
		{
			index1++;
		}
		if(val==p[index2]*3)
		{
			index2++;
		}
		if(val==p[index3]*5)
		{
			index3++;
		}
		p[index]=val;
		index++;
	}

	int result=p[num-1];
	delete []p;
	return result;
}
int main()
{
	int num=0;
	cin>>num;
	int ret=getTargetNum(num);
	cout<<ret<<endl;
	return 0;
}
