//有序链表合并
#include <iostream>
#include <malloc.h>
using namespace std;
struct node
{
	int _num;
	node* _next;
};
node *creat(int num)
{
	node* tmp=(node*)malloc(sizeof(node));
	if(tmp!=NULL)
	{	
		tmp->_num=num;
		tmp->_next=NULL;
	}
	return tmp;
}
class list
{
public:
	list()
		:_head(NULL)
	{}
	void pushback(int x)
	{
		node *begin=_head;
		if(begin==NULL)
		{
			node* tmp=creat(x);
			begin=tmp;
			_head=begin;
		}
		else
		{
			while(begin->_next!=NULL)
			{
				begin=begin->_next;
			}
			node* tmp=creat(x);
			begin->_next=tmp;
		}
	}
	node* combineList(node *head1,node*head2);
	void print(node *head)
	{
		node* begin=head;
		while(begin!=NULL)
		{
			cout<<begin->_num<<"->";
			begin=begin->_next;
		}
		cout<<endl;
	}
public:
	node* ret_head()
	{
		return _head;
	}
private:
	node *_head;
};
//普通写法
//node* list::combineList(node *head1,node*head2)
//{
//	if(head1==NULL&&head2==NULL)
//	{
//		return NULL;
//	}
//	if(head1==NULL)
//	{
//		return head2;
//	}else if(head2==NULL)
//	{
//		return head1;
//	}
//
//	node *list=NULL;
//	node *newhead=NULL;
//	if(head1->_num<head2->_num)
//	{
//		list=head1;
//		head1=head1->_next;
//	}
//	else
//	{
//		list=head2;
//		head2=head2->_next;
//	}
//	newhead=list;
//	while(head1!=NULL&&head2!=NULL)
//	{
//		if(head1->_num < head2->_num)
//		{
//			list->_next=head1;
//			head1=head1->_next;
//		}
//		else
//		{
//			list->_next=head2;
//			head2=head2->_next;
//		}
//		list=list->_next;
//	}
//	if(head1!=NULL)
//	{
//		list->_next=head1;
//	}
//	if(head2!=NULL)
//	{
//		list->_next=head2;
//	}
//	return newhead;
//}
//递归写法
node* list::combineList(node *head1,node *head2)
{
	node *newhead=NULL;
	if(head1==NULL)
	{
		return head2;
	}
	else if(head2==NULL)
	{
		return head1;
	}
	if(head1->_num<head2->_num)
	{
		newhead=head1;
		newhead->_next=combineList(head1->_next,head2);
	}
	else
	{
		newhead=head2;
		newhead->_next=combineList(head1,head2->_next);
	}
	return newhead;
}
int main()
{
	list l1;
	list l2;
	l1.pushback(1);
	l1.pushback(3);
	l1.pushback(5);
	l1.pushback(7);
	l1.pushback(9);
	l2.pushback(0);
	l2.pushback(2);
	l2.pushback(4);
	l2.pushback(6);
	l2.pushback(8);
	l2.pushback(10);
	l2.pushback(12);
	node*head1=l1.ret_head();
	l1.print(head1);
	node*head2=l2.ret_head();
	l2.print(head2);
	node *newhead=l1.combineList(head1,head2);
	l1.print(newhead);
	return 0;
}
