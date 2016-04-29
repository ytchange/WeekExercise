
//输入一个整数，输出和等于该整数的所有连续的子序列
#include <iostream>

using namespace std;

void FindSom(int num)
{
	int little=1;
	int big=2;
	while(big<=num && little<=num)
	{
		int sum=0;
		for(int i=little;i<=big;i++)
		{
			sum+=i;
		}
		if(sum<num)
		{
			big++;
		}
		else if(sum>num)
		{
			little++;
		}
		else
		{
			if(little!=big)
			{
				for(int j=little;j<=big;j++)
				{
					cout<<j<<" ";
				}
				cout<<endl;
			}
			big++;
		}
	}
}

int main()
{
	int num;
	cin>>num;
	FindSom(num);
	return 0;
}
