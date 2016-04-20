//单链表o(1)的时间复杂度删除一个节点

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
//	node* find(int num)
//	{
//		node *begin=_head;
//		while(begin)
//		{
//			cout<<"find"<<endl;
//			if(begin->_num==num)
//			{
//				return begin;
//			}
//			begin=begin->_next;
//		}
//		return NULL;
//	}
//public:
//	void deleteNode(node* head,node *delnode);
//	node* ret_head()
//	{
//		return _head;
//	}
//private:
//	node *_head;
//};

void list::deleteNode(node* head,node *delnode)
{
	if(head==NULL || delnode==NULL)
	{
		return;
	}
	//1.只有一个节点2.删除的是尾节点3.是非尾节点
	if(head==delnode)
	{
		delete head;
		head=NULL;
		delnode=NULL;
	}
	else if(delnode->_next!=NULL)
	{
		node *tmp=delnode->_next;
		delnode->_num=tmp->_num;//不可用指向next的next，在delete时会将目标节点后面的后面全删完
		delnode->_next=tmp->_next;
		delete tmp;
		tmp=NULL;
	}
	else
	{
		node *begin=head;
		while(begin->_next!=delnode)
		{
			begin=begin->_next;
		}
		delete delnode;
		delnode=NULL;
		begin->_next=NULL;
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
//	int num=4;
//	node *ret=l1.find(num);
//	node *rethead=l1.ret_head();
//	l1.deleteNode(rethead,ret);
//	l1.print();
//	cout<<endl;
//	return 0;
//}
