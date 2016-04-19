
//给定一个前序中序遍历的顺序，构造该二叉树

#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int  value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

BinaryTreeNode* creat(int *beginPre,int *endPre,int *beginIn,int *endIn)
{
	int rootValue=beginPre[0];
	BinaryTreeNode* root=new BinaryTreeNode();
	root->value=rootValue;
	root->left=root->right=NULL;
	int rootIn=beginIn;
	while(rootIn<=endIn&&*rootIn!=rootValue)
	{
		rootIn++;
	}
	int leftLength=rootIn-beginIn;
	int *leftPreEnd=beginPre+leftLength;
	if(leftLength>0)
	{
		root->left=creat(beginPre+1,leftPreEnd,beginIn,rootIn-1);
	}
	if(leftLength<endPre-beginPre)
	{
		root->right=creat(leftPreEnd+1,endPre,rootIn+1,endIn);
	}
	return root;

}
