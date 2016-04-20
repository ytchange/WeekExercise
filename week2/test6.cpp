//求base的expnent次方
#include <iostream>
#include <stdlib.h>
using namespace std;
//double getPower(double base,unsigned int expnent)
//{
//	double num=1.0;
//	int i=0;
//	for(;i<expnent;i++)
//	{
//		num*=base;
//	}
//	return num;
//}
double getPower(double base,unsigned int expnent)//n为偶数时，a的n次方等于a的n/2乘以a的n/2
{
	if(expnent==0)
	{
		return 1.0;
	}
	if(expnent==1)
	{
		return base;
	}
	double result=getPower(base,expnent>>1);
	result*=result;
	if(expnent&1==1)//当为奇数时要再乘一次base；
	{
		result*=base;
	}
	return result;
}
bool equal(double base1,double base2)//浮点数比较大小
{
	if((base1-base2)>-0.0000001 && (base1-base2)<0.0000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double Power(double base,int expnent)
{
	if(equal(base,0.0) && expnent<0)//当base为0时，0的负数次方便是错误的；
	{
		cout<<"base为0，expnent不能为负数"<<endl;
		exit(1);
	}
	unsigned int absexpnent=(unsigned int)expnent;
	if(expnent<0)
	{
		absexpnent=(unsigned int)(-expnent);
	}
	double result=getPower(base,absexpnent);
	if(expnent<0)
	{
		result=1.0/result;
	}
	return result;
}
//double Power(double base,int expnent)
//{
//	if(expnent==0)
//	{
//		return 1;
//	}
//	else if(expnent<0)
//	{
//		int num=1;
//		int i=0;
//		for(;i<expnent;i++)
//		{
//			num=num*base;
//		}
//		return 1.0/base;
//	}
//	else
//	{
//		double num=1.0;
//		int i=0;
//		for(;i<expnent;i++)
//		{
//			num=num*base;
//		}
//		return num;
//	}
//}
int main()
{
	double base;
	int expnent;
	cout<<"please input base and expnent:";
	cin>>base;
	cin>>expnent;
	double ret=Power(base,expnent);
	cout<<ret<<endl;
	return 0;
}

