//题目为复杂链表的拷贝


#include <iostream>

using namespace std;

struct ListNode
{
	ListNode(const int x)
		:value(x)
		 ,next(NULL)
		 ,sib(NULL)
	{}
	int value;
	ListNode *next;//指向下一个节点的指针
	ListNode *sib;//指向链表任意位置的指针
};
//分为三步
//1.克隆每一个节点并链在该节点后面 
//2.让克隆后的节点的sib指向源节点的next
//3.将链表拆分为原链表和克隆后的链表

void cloneNode(ListNode* head)
{
	if(head!=NULL)
	{
		ListNode* phead=head;
		while(phead!=NULL)
		{
			ListNode* cloNode=new ListNode(phead->value);
			cloNode->next=phead->next;
			cloNode->sib=NULL;
			phead->next=cloNode;
			phead=cloNode->next;
		}
	}
}
void changeSib(ListNode* head)
{
	ListNode* phead=head;
	while(phead!=NULL)
	{
		ListNode* pclone=phead->next;
		if(phead->sib!=NULL)//当sib不为空时，复制phead的sib给pclone；
		{
			pclone->sib=phead->sib->next;
		}
		phead=pclone->next;
	}
}
ListNode* apartList(ListNode* head)
{
	ListNode* phead=head;
	ListNode* pclone=head->next;
	phead=pclone->next;
	ListNode* pcloneHead=pclone;
	while(phead!=NULL)
	{
		pclone->next=phead->next;
		pclone=pclone->next;
		phead->next=pclone->next;
		phead=phead->next;
	}
	return pcloneHead;
}
ListNode* clone(ListNode* head)
{
	ListNode* newhead=NULL;;
	cloneNode(head);
	changeSib(head);
	newhead=apartList(head);
	return newhead;
}

void print(ListNode* head)
{
	while(head!=NULL)
	{
		cout<<head->value<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	ListNode *n1=new ListNode(1);
	ListNode *n2=new ListNode(2);
	ListNode *n3=new ListNode(3);
	ListNode *n4=new ListNode(4);
	ListNode *n5=new ListNode(5);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=NULL;
	n1->sib=n3;
	n2->sib=n5;
	n4->sib=n2;
	ListNode* head=n1;
	ListNode*newhead=clone(head);
	print(newhead);
}
