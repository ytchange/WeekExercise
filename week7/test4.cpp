//求二叉树的深度
//判断一棵树是不是平衡树
//采用递归方法求解，左右子树深度最深的那个
#include <iostream>

using namespace std;
struct TreeNode
{
	int value;
	TreeNode *left;
	TreeNode *right;
}
class Tree
{
	typedef TreeNode Node;
	public:
	int depth(Node *root)
	{
		if(root==NULL)
		{
			return 0;
		}
		int left=depth(root->left);
		int right=depth(root->right);
		return (left>right?left:right)+1;
	}
	private:
	Node *root;
}

//bool isBalance(Node *root)
//{
//	if(root==NULL)
//	{
//		return true;
//	}
//	int left=depth(root->left);
//	int right=depth(root->right);
//	int diff=left-right;
//	if(diff<-1&&dif>1)
//	{
//		return false;
//	}
//	return isBalance(root->left)&&isBalance(root->right);
//}
//后续遍历，一边遍历一边判断该节点是不是平衡，可以杜绝重复判断，效率更高
bool isBalanceR(Node *root,&depth)
{
	if(root==NULL)
	{
		depth=0;
		return true;
	}
	int left,right;
	if(isBalanceR(root->left,&left)&&isbalance(root->right,&right))
	{
		int diff=left-right;
		if(diff>=-1&&diff<=1)
		{
			depth=1+(left>right?left:right);
			return true;
		}
	}
	return false;
}
bool isBalance(Node *root)
{
	int depth=0;
	return isBalanceR(Node *root,&depth);
}
int main()
{
	return 0;
}
