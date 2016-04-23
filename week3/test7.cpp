//返回占中最小元素，时间复杂度为O(1)

#include <iostream>
#include <stack>
using namespace std;

class stackRetMin
{
	public:
		stackRetMin()
			:min(0)
		{}
		void Push(const int &x)
		{
			if(s1.empty()&&s2.empty())
			{
				s1.push(x);
				s2.push(x);
			}
			else
			{
				min=s2.top();
				s1.push(x);
				if(min<=x)
				{
					s2.push(min);
				}
				else
				{
					s2.push(x);
				}
			}
		}
		void Pop()
		{
			s1.pop();
			s2.pop();
		}
		const int& Min()
		{
			return s2.top();
		}
	private:
		stack<int> s1;
		stack<int> s2;
		int min;
};

int main()
{
	stackRetMin srm1;
	srm1.Push(1);
	srm1.Push(2);
	srm1.Push(4);
	srm1.Push(3);
	srm1.Push(0);
	srm1.Push(8);
	srm1.Pop();
	srm1.Pop();

	int ret=srm1.Min();
	cout<<ret<<endl;
	return 0;
}
