//求两个链表的第一个公共节点
//采用长链表减短链表，先让短链表走差的长度，然后两者同步走，当两个节点相等时即为第一个公共节点

#include <iostream>
#include <assert.h>
using namespace std;
struct ListNode
{
	int value;
	ListNode* next;
	ListNode(int x)
		:value(x)
		,next(NULL)
	{}
};
class List
{
	public:
	List()
		:head(NULL)
	{}

	void pushback(int x)
	{
		if(head==NULL)
		{
			head=new ListNode(x);
		}
		else
		{
			ListNode *begin=head;
			while(begin->next!=NULL)
			{
				begin=begin->next;
			}
			ListNode *tmp=new ListNode(x);
			begin->next=tmp;
		}
	}

	ListNode* FindSameNode(ListNode *head1,ListNode *head2)
	{
		assert(head1&&head2);
		int len1=0,len2=0;
		ListNode *begin1=head1;
		ListNode *begin2=head2;
		//统计head1的长度len1
		while(begin1)
		{
			len1++;
			begin1=begin1->next;
		}
		//统计head2的长度len2
		while(begin2)
		{
			len2++;
			begin2=begin2->next;
		}
		if(len1>len2)
		{
			int mov1=len1-len2;
			while(mov1)
			{
				head1=head1->next;
				mov1--;
			}
		}
		if(len1<len2)
		{
			int mov2=len2-len1;
			while(mov2)
			{
				head2=head2->next;
				mov2--;
			}
		}
		while(head1!=NULL&&head2!=NULL&&head1!=head2)
		{
			head1=head1->next;
			head2=head2->next;
		}
		return head1;
	}

	void combine(ListNode *head1,ListNode *head2,ListNode* head3)
	{
		ListNode *begin1=head1;
		ListNode *begin2=head2;
		while(begin1->next)
		{
			begin1=begin1->next;
		}
		while(begin2->next)
		{
			begin2=begin2->next;
		}
		begin1->next=head3;
		begin2->next=head3;
	}
	void print()
	{
		ListNode *begin=head;
		while(begin)
		{
			cout<<begin->value<<"->"; 
			begin=begin->next;
		}
		cout<<"NULL"<<endl;
	}
	ListNode* retHead()
	{
		return head;
	}
	private:
		ListNode *head;
};

void test1()
{
	List l1,l2,l3;
	l1.pushback(1);
	l1.pushback(2);
	l1.pushback(3);
	l1.pushback(4);
	l1.pushback(5);
	l2.pushback(3);
	l2.pushback(2);
	l2.pushback(1);
	l3.pushback(6);
	l3.pushback(7);
	l3.pushback(8);
	l3.pushback(9);
	l1.print();
	l2.print();
	l3.print();
	ListNode* head1=l1.retHead();
	ListNode* head2=l2.retHead();
	ListNode* head3=l3.retHead();
//	cout<<head1->value<<endl;
//	cout<<head2->value<<endl;
//	cout<<head3->value<<endl;

	l1.combine(head1,head2,head3);
	l1.print();
	l2.print();
	l3.print();

	ListNode*ret=l1.FindSameNode(head1,head2);
	cout<<"find:"<<ret->value<<endl;
}

int main()
{
	test1();
	return 0;
}














