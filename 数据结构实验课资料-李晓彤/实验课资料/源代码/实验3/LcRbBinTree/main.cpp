#include<iostream>
#include<iomanip>
#include "LcRbBinTree.h"
using namespace std;
typedef char E;
char c[50];
string s;
ValNode v;
PNode p;
LNode lc;
RbNode rb;
LcRbBinTree T;

//建树操作以层次遍历输入
int CreateBinTree(string s) {
	strcpy(c,s.c_str());
	int n=s.length();
	for(int i=0; c[i]!='\0'; i++) {
		//设置左孩子 
		lc.setLeft(i,n);
		T.leftArray.push_back(lc);
	
		//设置元素值 
		v.setElement(c[i]);
		T.valArray.push_back(v);
		
		//设置父亲 
		if(i==0||c[i]=='/')
		{
			p.setparent(-1);
		}
		else p.setparent(i);
		T.parArray.push_back(p);
		
		//设置右兄弟 
		if(i%2!=0&&c[i]!='/')
		{
			rb.setRightsibling(i,n);
		}
		else rb.setRightsibling(-1,n);
		T.rightArray.push_back(rb);
	}
	return 0;//返回根节点下标
}

int main()
{
	int r;

	int depth;

	int num;
	
	cout<<"-----欢迎来到基于左孩子/右兄弟实现的二叉树-----"<<endl;
	cout<<"提示："<<endl

	    <<"以字符串形式输入要构建的二叉树时，按层次遍历的顺序输入，所有的空节点以/代替"<<endl

	    <<"注意！必须要输入左子树"<<endl

	    <<"例：ABCDEF"<<endl

	    <<"请输入：";

	cin>>s;

	//建树
	r=CreateBinTree(s);
	int i=s.length();

	cout<<"-----------------------------------"<<endl;

	cout<<"判断树是否是空树：";

	if(T.BiTreeEmpty(r))
		{
			cout<<"输入为一棵空树,程序结束"<<endl;
			return 0;
		}
	else cout<<"不是空树"<<endl;

	cout<<"层次遍历：";
	T.LevelOrderTraverse(s,i);

	cout<<endl;
	
	
	cout<<"层次遍历的结点对应的父亲结点为： \n";
	T.PrintParent(r);
	cout<<endl; 
	
	cout<<"层次遍历的结点对应的左孩子结点为： \n";
	T.PrintLeft(r);
	cout<<endl; 
	
	cout<<"层次遍历的结点对应的右兄弟结点为： \n";
	T.PrintRight(r);
	cout<<endl; 


	cout<<"树的深度：（层数从0开始算起）";
	depth=T.BiTreeDepth(r);
	cout<<depth<<endl;

	cout<<"树的结点个数：";
	num=T.count(s,i);
	cout<<num<<endl;
	system("pause");
	return 0;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

