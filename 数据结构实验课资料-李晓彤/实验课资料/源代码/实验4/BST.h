#ifndef BINTREE_H
#define BINTREE_H
#include<iostream>
using namespace std;
class BiNode {
	private:
		int it;
		BiNode* lc;
		BiNode* rc;
	public:
		BiNode(){lc = rc = NULL;}
		BiNode(int i,BiNode* l,BiNode* r){it=i;lc=l; rc=r;}
		void setelement(int i){	it=i;}
		int getelement(){return it;	}
		void setleft(BiNode* l){lc=l;}
		BiNode* getleft(){	return lc;}
		void setright(BiNode* r){	rc=r;}
		BiNode* getright(){	return rc;}
		
};
class BST:public BiNode {
	private:
		BiNode* root;   // Root of the BinTree BinTree树的根结点
		int nodeCount;
	public:
		BST();
		~BST();
		void clear(BiNode* node);
		
		BiNode* getRoot();//BiNode指针类的返回根结点
		
		//插入+创建 
		void insert(const int ); 
		BiNode* inserthelp(BiNode* root,const int);

		int find(BiNode*,const int);//查找

		//中序遍历
		void Inorder(BiNode* rt);

		//二叉树深度
		int BiTreeDepth(BiNode* rt);

		//节点数统计
		int count(BiNode* rt);
};

#endif
