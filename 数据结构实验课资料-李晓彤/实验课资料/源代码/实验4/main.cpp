/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<iostream>
#include<assert.h>
#include<string.h>
#include "BST.h"
using namespace std;
int c[50];
int count=0;

int main(int argc, char** argv) {
	int depth=0;
	int num=0;//树的结点个数
	BST T;
	cout<<"------接下来是二叉查找树（BST）实现一个静态查找表------"<<endl;
	cout<<"请先输入结点个数(大于0)："<<endl;
	cin>>num;
	while(num<=0)
	{
		cout<<"输入错误，请重新输入："<<endl;
		cin>>num;
	}
	
	cout<<"请输入要构造的树:";
	cout<<"输入"<<num<<"个结点，请先输入要构造的根结点，之后的顺序随意，每个结点的值用空格隔开"<<endl;
	cout<<"例如：31 17 42 16 24 28"<<endl;
	int temp=0;
	//输入+建树 
	for(int i=0;i<num;i++)
	{
		cin>>temp;
		T.insert(temp);
	}

	cout<<"中序遍历：";
	T.Inorder(T.getRoot());
	cout<<endl;
	cout<<"树的深度：(层数从0开始)";
	depth=T.BiTreeDepth(T.getRoot());
	cout<<--depth<<endl;
	cout<<"树的结点个数：";
	num=T.count(T.getRoot());
	cout<<num<<endl;
	
	cout<<"接下来进行查找操作:";
	cout<<"请输入要查找的元素，ctrl+Z结束程序"<<endl;
	while(cin>>temp)
	{
		int bijiao=T.find(T.getRoot(),temp);
		if(bijiao<=0)
		{
			cout<<"抱歉，您要查找的"<<temp<<"不在该树中"<<",查找一共经过的比较次数为： "<<bijiao+1024<<endl; 
		}
		if(bijiao>0)
		{
			cout<<"查找成功"<<",查找一共经过的比较次数为： "<<bijiao<<endl;
		}
		cout<<"请输入要查找的元素，ctrl+Z结束程序"<<endl;
	}
	system("pause");
	return 0;	
}
