//层序遍历二叉树，通过队列的先进先出特性，先存左子树，再右子树

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
	TreeNode(int &x)
		:value(x)
		 ,left(NULL)
		 ,right(NULL)
	{}
	int value;
	TreeNode *left;
	TreeNode *right;
};

class tree
{
	public:
		tree()
			:root(NULL)
		{}
		//函数实现

		void printTree(TreeNode* root)
		{
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty())
			{
				TreeNode* node;
				node=q.front();
				q.pop();
				cout<<node->value<<" ";
				if(node->left!=NULL)
				{
					q.push(node->left);
				}
				if(node->right!=NULL)
				{
					q.push(node->right);
				}
			}
		}
		TreeNode* retRoot()
		{
			return root;
		}
		void buildTree(int *arr,int len)
		{
			for(int i=0;i<len;i++)
			{
				//cout<<arr[i]<<endl;
				insert(arr[i]);
			}
		}
		void print()
		{
			TreeNode *myroot=root;
			myPrint(myroot);
		}

		void insert(int &data)
		{
			//cout<<data<<endl;
			myInsert(root,data);
		}
	protected:
		void myInsert(TreeNode* &root,int &data)
		{

			if(root==NULL)
			{
				root=new TreeNode(data);
			}
			else
			{
				if(data<=root->value)
				{
					myInsert(root->left,data);
				}
				else
				{
					myInsert(root->right,data);
				}
			}
		}
		void myPrint(TreeNode *myroot)
		{
			if(myroot==NULL)
			{
				return;
			}
			myPrint(myroot->left);
			cout<<myroot->value<<" ";
			myPrint(myroot->right);
		}
	private:
		TreeNode *root;
};

int main()
{
	tree t1;
	int arr[4]={2,8,7,4};
	t1.buildTree(arr,4);
	t1.print();
	cout<<endl;
	TreeNode* ret=t1.retRoot();
	t1.printTree(ret);
	cout<<endl;
	return 0;
}
