
//单链表逆置

//#include <iostream>
//#include <malloc.h>
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
//	void reverseList(node* head);
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
//	node* ret_head()
//	{
//		return _head;
//	}
//private:
//	node *_head;
//};
void list::reverseList(node* head)
{
	if(head==NULL)
	{
		cout<<"error"<<endl;
		return;
	}
	node *begin=head;
	node *prev=head;
	node *newhead=NULL;
	begin=begin->_next;
	prev->_next=NULL;
	newhead=prev;
	while(begin!=NULL)
	{
		prev=begin;
		begin=begin->_next;
		prev->_next=newhead;
		newhead=prev;
	}
	_head= newhead;
}

int main()
{
	list l1;
	l1.pushback(1);
	l1.pushback(4);
	l1.pushback(2);
	l1.pushback(6);
	l1.pushback(3);
	l1.pushback(8);
	l1.print();
	node *head=l1.ret_head();
	l1.reverseList(head);
	l1.print();
	return 0;
}

