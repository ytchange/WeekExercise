
//求二叉树中和为某一值的路径

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
	//问题函数实现
	
		void findPath(SearchTreeNode *root,int sum)
		{
			if(root==NULL)
			{
				return;
			}

			int curSum=0;//当前和
			vector<int> path;//用vector存储它的路径
			myFindPath(root,path,sum,curSum);
		}
		void myFindPath(SearchTreeNode* root,vector<int> &path,int sum,int &curSum)
		{
			curSum+=root->value;
			path.push_back(root->value);
			bool isleaf=(root->left==NULL)&&(root->right==NULL);
			if(sum==curSum && isleaf==true)//如果节点是叶子节点，并且值等于总和，则打印出路径
			{
				cout<<"find it "<<endl;
				vector<int>::iterator index=path.begin();
				for(;index<path.end();index++)
				{
					cout<<*index<<"->";
				}
				cout<<endl;
			}
			//如果不是叶子节点，则遍历左右子树
			if(root->left!=NULL)
			{
				myFindPath(root->left,path,sum,curSum);
			}
			if(root->right!=NULL)
			{
				myFindPath(root->right,path,sum,curSum);
			}
			//该路径没有找到，则回退，减值，删路径
			curSum-=root->value;
			path.pop_back();
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
	int sum;
	cout<<"please input the arr 0f size:"<<endl;
	cin>>num;
	int *arr=new int[num];
	cout<<"please input the arr of num:"<<endl;
	for(i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	cout<<"please intput the sum of check:"<<endl;
	cin>>sum;
//6 4 2 3 5 8 10 9 7 
//sum=15
//路径为 6->4->2->3  和  6->4->5  两条
	SearchTree st;
	st.buildTree(arr,num);
	SearchTreeNode*root=st.retRoot();
	//st.prevPrint(root);
	st.orderPrint(root);
	cout<<endl;
	st.postOrder(root);
	cout<endl;
	st.findPath(root,sum);
//	for(i=0;i<num;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
	cout<<endl;
	return 0;
}
