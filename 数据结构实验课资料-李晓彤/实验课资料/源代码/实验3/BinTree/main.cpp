/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<iostream>
#include<assert.h>
#include<string.h>
#include "BinTree.h"
using namespace std;
char c[50];
int count=0;
BinTree T;
//建树
BiNode*CreateBinTree(char ch) {
	BiNode* rt;
	if(ch=='/')  rt=NULL;
	else {
		rt=new BiNode;
		rt->setElement(ch);//构造根结点 
		ch=c[++count];//构造结点成功，结点数加一 
		rt->setLeft(CreateBinTree(ch));//构造左孩子 
		ch=c[++count];
		rt->setRight(CreateBinTree(ch));//构造右孩子 
	}
	//设置根节点
	T.setroot(rt);
	return rt;
}
int main(int argc, char** argv) {	
	char ch;
	int depth=0;
	int num=0;
	BiNode* r;
	string s;
	cout<<"------接下来是二叉链表来实现二叉树------"<<endl;
	cout<<"请输入要构造的树:"; 
	cout<<"以前序遍历的顺序输入(也要把叶子结点的两个空子树输入)，空节点以/代替,例AB/D//CE//F//"<<endl;
	cin>>s;
	strcpy(c,s.c_str());
	r=CreateBinTree(c[0]);
	cout<<"判断树是否是空树：";
		if(T.BiTreeEmpty(r))
			cout<<"No"<<endl;
		else 
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"中序遍历：";
		T.Inorder(r);
		cout<<endl;
	cout<<"树的深度：(层数从0开始)";
		depth=T.BiTreeDepth(r);
		cout<<--depth<<endl;
	cout<<"树的结点个数：";
		num=T.count(r);
		cout<<num<<endl;
	return 0;
	system("pause"); 
}
