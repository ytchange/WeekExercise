//在二叉树中查找子树

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
		bool check(treeNode *root1,treeNode *root2)
		{
			if(root2==NULL)
			{
				return true;
			}
			if(root1==NULL)
			{
				return false;
			}
			if(root1->value!=root2->value)
			{
				return false;
			}
			return check(root1->left,root2->left)&&check(root1->right,root2->right);
		}
		bool hasSubtree(treeNode *root1,treeNode *root2)
		{
			bool result=false;
			if(root1!=NULL&&root2!=NULL)
			{
				if(root1->value==root2->value)
				{
					result=check(root1,root2);
				}
				if(result==false)
				{
					result=hasSubtree(root1->left,root2);
				}
				if(result==false)
				{
					result=hasSubtree(root1->right,root2);
				}
			}
		}
		treeNode* retRoot(char *str)
		{
			if(*str!='#'&&*str!='\0')
			{
				root=new treeNode(*str);
			}
			return root;
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

int main()
{
	char *str1="123##4##56###";
	char *str2="123##4##56###";
	tree t1(str1);
	tree t2(str2);
	treeNode *root1=t1.retRoot(str1);
	treeNode *root2=t2.retRoot(str2);
	bool result;
	result=t1.hasSubtree(root1,root2);
	if(result==true)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;
}
