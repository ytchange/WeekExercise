//实现二叉树的影像

#include <iostream>

using namespace std;

struct treeNode
{
	char value;
	treeNode *left;
	treeNode *right;
	treeNode(char x)
		:value(x)
		 ,left(NULL)
		 ,right(NULL)
	{}
};
class tree
{
	public:
		tree(char *str)
			:root(NULL)
		{
			creatTree(root,str);
		}
		treeNode* retRoot(char *str)
		{
			if(*str!='#'&&*str!='\0')
			{
				root=new treeNode(*str);
			}
			return root;
		}
		void reverseTree(treeNode* root)
		{
			if((root==NULL)||(root->left==NULL)&&(root->right==NULL))
				return;
			treeNode *tmp=root->left;
			root->left=root->right;
			root->right=tmp;
			if(root->left)
			{
				reverseTree(root->left);
			}
			if(root->right)
			{
				reverseTree(root->right);

			}
		}
		void creatTree(treeNode *root,char *str)
		{
			if(*str!='#'&&*str!='\0')
			{
				root=new treeNode(*str);
				creatTree(root->left,str++);
				creatTree(root->right,str++);
			}
		}
	private:
		treeNode *root;
};

