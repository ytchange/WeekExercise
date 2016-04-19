//单链表反向打印，不修改原链表

//#include <iostream>
//#include <malloc.h>
//#include<stack>
//
//using namespace std;
//struct node
//{
//	int _num;
//	node* _next;
//};
//node *creat(int num)
//{
//	node* tmp=(node*)malloc(sizeof(node));
//	if(tmp!=NULL)
//	{	
//		tmp->_num=num;
//		tmp->_next=NULL;
//	}
//	return tmp;
//}
//class list
//{
//public:
//	list()
//		:_head(NULL)
//	{}
//	void pushback(int x)
//	{
//		node *begin=_head;
//		if(begin==NULL)
//		{
//			node* tmp=creat(x);
//			begin=tmp;
//			_head=begin;
//		}
//		else
//		{
//			while(begin->_next!=NULL)
//			{
//				begin=begin->_next;
//			}
//			node* tmp=creat(x);
//			begin->_next=tmp;
//		}
//	}
//	void print()
//	{
//		node* begin=_head;
//		while(begin!=NULL)
//		{
//			cout<<begin->_num<<"->";
//			begin=begin->_next;
//		}
//		cout<<endl;
//	}
//public:
//	void reverse(node* head);
//	node* ret_head()
//	{
//		return _head;
//	}
//private:
//	node *_head;
//};

//两种方法都是不改变原链表，只是反向打印
//递归和栈类似，可以用栈来实现
void list::reverse(node* head)
{
	stack<node*> st;
	while(head!=NULL)
	{
		st.push(head);
		head=head->_next;
	}
	while(!st.empty())
	{
		node* tmp=st.top();
		cout<<tmp->_num<<"->";
		st.pop();
	}
}
//用递归来实现
void list::reverse(node* head)
{
	if(head!=NULL)
	{
		if(head->_next!=NULL)
		{
			reverse(head->_next);
		}
		cout<<head->_num<<"->";
	}
}


//int main()
//{
//	list l1;
//	l1.pushback(1);
//	l1.pushback(2);
//	l1.pushback(3);
//	l1.pushback(4);
//	l1.pushback(5);
//	l1.pushback(6);
//	l1.print();
//	node* ret=l1.ret_head();
//	l1.reverse(ret);
//	cout<<endl;
//	return 0;
//}
