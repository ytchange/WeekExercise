//差别在于BST一定是二叉树，并且结点信息是关键码（可能还带有记录的索引），并且BST中关键码无重复，
//左子树如果存在，其所有的关键码一定小于根，右子树如果存在，其所有关键码一定大于根，左右子树自然也是BST，
//因此有特性中序遍历序列单调递增

//二叉线索树的中序遍历时按照递增顺序排列的

//题目是判断所给的一个数组是不是二叉搜索树后续遍历得到的
//顺便实现下二叉搜索树
#include <iostream>
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

		//函数实现,如果是后续遍历的顺序，则数组最后一个元素一定是根节点
		//左子树小于根节点，右子树大于根节点
		bool checkPostOrder(int *arr,int len)
		{
			if(arr==NULL&&len<0)
			{
				return false;
			}
			//查找左子树
			int rootValue=arr[len-1];
			int i=0;
			for(;i<len-1;i++)
			{
				if(rootValue<arr[i])
				{
					break;
				}
				//i的最终位置在右子树的第一个节点上
			}
			//查找右子树
			int j=i;
			for(;j<len-1;j++)
			{
				if(arr[j]<rootValue)
				{
					return false;
				}
			}
			//递归检查左子树
			bool left=true;
			if(i>0)
			{
				left=checkPostOrder(arr,i);
			}
			//递归检查右子树
			bool right=true;
			if(i<len-1)
			{
				right=checkPostOrder(arr+i,len-1-i);
			}
			return left&&right;
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
				deleteNode(root->left);
				deleteNode(root->right);
				delete root;
				root=NULL;
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
	SearchTreeNode*root=st.retRoot();
	//st.prevPrint(root);
	st.orderPrint(root);
	cout<<endl;
	st.postOrder(root);
	cout<<endl;
	bool tmp=st.checkPostOrder(arr,num);
	if(tmp==true)
	{
		cout<<"yes"<<endl;
	}
	else
	{
		cout<<"no"<<endl;
	}
//	for(i=0;i<num;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
	return 0;
}
