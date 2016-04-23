//单链表查找倒数第NUM个节点

//#include <iostream>
//#include <malloc.h>
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
//	node* findNumNode(node* head,int num);
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
//要注意一些边界条件，特别重要
node* list::findNumNode(node* head,int num)
{
	if(head==NULL||num==0)//对参数判空处理
	{
		return NULL;
	}
	node *slow=head;
	node *fast=head;
	int i=1;
	for(;i<num;i++)
	{
		if(fast->_next==NULL)//num的值大于链表的长度
		{
			return NULL;
		}
		fast=fast->_next;	
	}
	while(fast->_next!=NULL)
	{
		fast=fast->_next;
		slow=slow->_next;
	}
	return slow;
}

//int main()
//{
//	list l1;
//	l1.pushback(1);
//	l1.pushback(3);
//	l1.pushback(7);
//	l1.pushback(2);
//	l1.pushback(4);
//	l1.pushback(8);
//	l1.print();
//	node* head=l1.ret_head();
//	int num=0;
//	cin>>num;
//	node* det=l1.findNumNode(head,num);
//	if(det==NULL)
//	{
//		cout<<"error"<<endl;
//	}
//	else
//	{
//		cout<<det->_num<<endl;
//	}
//	return 0;
//}
