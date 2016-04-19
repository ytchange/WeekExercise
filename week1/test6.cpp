
//两栈实现一个队列，实现其添加和删除的函数

//#include <iostream>
//#include <stack>
//using namespace std;
//
//class MyQueue
//{
//	public:
//		void appendTail(int x);
//		void deleteHead();
//		void print();
//	private:
//		stack<int> s1;
//		stack<int> s2;
//};
//void MyQueue::print()
//{
//	int top1,top2;
//	while(!s1.empty())
//	{
//		top1=s1.top();
//		cout<<top1<<"->";
//		s1.pop();
//	}
//	while(!s2.empty())
//	{
//		top2=s2.top();
//		cout<<top2<<"->";
//		s2.pop();
//	}
//
//}
void MyQueue:: appendTail(int x)//插入时只在s1
{
	int tmp;
	if(s2.empty())
	{
		s1.push(x);
	}
	if(s1.empty() && !s2.empty())
	{
		while(!s2.empty())
		{
			tmp=s2.top();
			s1.push(tmp);
			s2.pop();
		}
		s1.push(x);
	}
}
void MyQueue:: deleteHead()//删除时只在s2
{
	int tmp;
	if(s1.empty() && s2.empty())
	{
		cout<<"it is empty!!!"<<endl;
	}
	if(s1.empty() && !s2.empty())
	{
		s2.pop();
	}
	if(!s1.empty() && s2.empty())
	{
		while(!s1.empty())
		{
			tmp=s1.top();
			s2.push(tmp);
			s1.pop();
		}
		s2.pop();
	}
}
//
//int main()
//{
//	MyQueue mq;
//	mq.appendTail(1);
//	mq.appendTail(2);
//	mq.appendTail(3);
//	mq.appendTail(4);
//	//amq.print();
//	mq.deleteHead();
//	mq.deleteHead();
//	mq.deleteHead();
//	mq.print();
//	cout<<endl;
//	return 0;
//}
