
//创建一个类只生成一个实例

#include <iostream>

using namespace std;

class A
{
public:
	static A* checkcase()
	{
		if(p==NULL)
		{
			p=new A();
		}
		return p;
	}
	int getret()
	{
		return ret;
	}
private:
	A()
	{
		ret=10;
	}
	static A *p;
	int ret;
};

A* A::p=NULL;

int main()
{
	A* tmp=A::checkcase();
	cout<<tmp->getret()<<endl;
	A* tmp2=A::checkcase();
	cout<<tmp2->getret()<<endl;
	//A* tmp3=new A();
	//cout<<tmp3->getret()<<endl;
	
	return 0;
}
