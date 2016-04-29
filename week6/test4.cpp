//查找1~num总共出现了多少次1

#include <iostream>
using namespace std;

int get(int num)
{
	int bit=0;
	int count=0;
	while(num)
	{
		bit=num%10;
		if(bit==1)
		{
			count++;
		}
		num=num/10;
	}
	return count;
}

int NumOf1(int n)
{
	int count=0;
	for(int i=1;i<=n;i++)
	{
		int ret=get(i);
		count+=ret;
	}
	return count;
}

int main()
{
	int num=0;
	cin>>num;
	int ret=NumOf1(num);
	cout<<ret<<endl;
	return 0;
}
