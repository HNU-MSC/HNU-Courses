#ifndef BINTREE_H
#define BINTREE_H
#include<iostream>
using namespace std;
class BiNode {
	private:
		char it;             // The node's value
		BiNode* lc;       //Pointer to left child
		BiNode* rc;      // Pointer to right child
	public:
		
		BiNode();//构造函数 

		BiNode(char e,BiNode* l,BiNode* r);//含参构造函数 
		char& element();//得到结点的值 

		void setElement(char& e); //构建结点的值 
		
		
		BiNode* left();//返回左孩子的地址 
		void setLeft(BiNode* b); //返回左孩子的值 
		
		
		BiNode* right(); //返回右孩子
		void setRight(BiNode* b);//返回右孩子的值 
		
		//判断是否为叶子节点
		bool isLeaf();
};

class BinTree:public BiNode {
private:
	char c;
	BiNode* root;   // Root of the BinTree BinTree树的根结点
public:

	BiNode* Root();//BiNode指针类的返回根结点 
	void setroot(BiNode* n);//设置根结点 

	//判断二叉树是否为空
	bool BiTreeEmpty(BiNode* rt);


	//中序遍历
	void Inorder(BiNode* rt);

	//二叉树深度
	int BiTreeDepth(BiNode* rt);

	//节点数统计
	int count(BiNode* rt);
};

#endif
