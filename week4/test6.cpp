
//将二叉搜索树转化为双向链表

#include <iostream>
#include <vector>

using namespace std;

struct SearchTreeNode
{
	SearchTreeNode(const int &x)
		:value(x)
		 ,left(NULL)
		 ,right(NULL)
	{}

	int value;
	SearchTreeNode* left;
	SearchTreeNode* right;
};
class SearchTree
{
	public:
		SearchTree()
			:root(NULL)
		{}
		~SearchTree()
		{
			deleteNode(root);
		}
		void buildTree(int *arr,int len)
		{
			int i=0;
			for(;i<len;i++)
			{
				//cout<<arr[i]<<endl;
				root=insert(root,arr[i]);
			}
		}
		void prevPrint(SearchTreeNode *root)
		{
			if(root!=NULL)
			{
				cout<<root->value<<" ";
				prevPrint(root->left);
				prevPrint(root->right);
			}
		}
		void orderPrint(SearchTreeNode* root)
		{
			if(root!=NULL)
			{
				orderPrint(root->left);
				cout<<root->value<<" ";
				orderPrint(root->right);
			}
		}
		void postOrder(SearchTreeNode* root)
		{
			if(root!=NULL)
			{
				orderPrint(root->left);
				orderPrint(root->right);
				cout<<root->value<<" ";
			}
		}
		SearchTreeNode* retRoot()
		{
			return root;
		}
		//函数实现,通过递归来实现，left变为前驱，right变为后继
		SearchTreeNode* TreeToList(SearchTreeNode* root)
		{
			if(root==NULL)
			{
				return NULL;
			}
			SearchTreeNode* lastNode=NULL;
			myTreeToList(root,lastNode);
			SearchTreeNode* newhead=lastNode;
			while(newhead!=NULL && newhead->left!=NULL)
			{
				newhead=newhead->left;
			}
			root=newhead;
			return newhead;
		}
		void myTreeToList(SearchTreeNode* root,SearchTreeNode* &lastNode)
		{
			if(root==NULL)
			{
				return;
			}
			SearchTreeNode* cur=root;
			if(cur->left!=NULL)
			{
				myTreeToList(cur->left,lastNode);
			}
			cur->left=lastNode;
			if(lastNode!=NULL)
			{
				lastNode->right=cur;
			}
			lastNode=cur;
			if(cur->right!=NULL)
			{
				myTreeToList(cur->right,lastNode);
			}
		}
		void print(SearchTreeNode* head)
		{
			if(head==NULL)
			{
				return;
			}
			while(head!=NULL)
			{
				cout<<head->value<<"  ";
				head=head->right;
			}
		}
	protected:
		SearchTreeNode* insert(SearchTreeNode* &root,int num)
		{
			if(root==NULL)
			{
				root=new SearchTreeNode(num);
			}
			else if(root->value>num)
			{
				root->left=insert(root->left,num);
			}
			else if(root->value<num)
			{
				root->right=insert(root->right,num);
			}
			return root;
		}
		void deleteNode(SearchTreeNode* root)
		{
			if(root!=NULL)
			{
				SearchTreeNode* prev=NULL;
				while(root)
				{
					prev=root;
					root=root->right;
					delete prev;
					prev=NULL;
				}
			}
		}
	private:
		SearchTreeNode* root;
};

int main()
{
	int num;
	int i;
	cout<<"please input the arr 0f size:"<<endl;
	cin>>num;
	int *arr=new int[num];
	cout<<"please input the arr of num:"<<endl;
	for(i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	SearchTree st;
	st.buildTree(arr,num);
	//st.prevPrint(root);
	SearchTreeNode*root=st.retRoot();
	st.orderPrint(root);
	cout<<endl;
	st.postOrder(root);
	cout<<endl;
	SearchTreeNode* newhead=st.TreeToList(root);
	st.print(newhead);
	
//	for(i=0;i<num;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
	cout<<endl;
	return 0;
}
