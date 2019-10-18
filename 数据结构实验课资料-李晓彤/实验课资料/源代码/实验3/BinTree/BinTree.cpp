#include <iostream>
#include "BinTree.h"
#include<queue>
using namespace std;
	BiNode::BiNode() {//结点的构造函数 
			lc = rc = NULL;
		}

	BiNode::BiNode(char e,BiNode* l,BiNode* r) {//结点的含参构造函数 
			it = e;
			lc = l;
			rc = r;
		}

	char& BiNode::element() {//取得结点值 
			return it;
		}

	void BiNode::setElement(char& e) {//设置结点值 
			it = e;
		}

		//返回左孩子
	BiNode*BiNode::left() {
			return lc;
		}

	void BiNode::setLeft(BiNode* b) {
			lc = (BiNode*)b;//设置左孩子的值 
		}

		//返回右孩子
	BiNode*BiNode::right(){
			return rc;
		}

	void BiNode::setRight(BiNode* b) {
			rc = (BiNode*)b;
		}

	//判断是否为叶子节点
	bool BiNode::isLeaf() {
			return (lc == NULL) && (rc == NULL);
		}

	BiNode*BinTree:: Root() {
		return root;
	}
	
	void BinTree::setroot(BiNode* n) {
		root=n;
	}

	//判断二叉树是否为空
	bool BinTree::BiTreeEmpty(BiNode* rt)
	{
		if(rt!=NULL) return true;
		else return false;
	}

	
	//中序遍历
	void BinTree::Inorder(BiNode* rt)
	{
		if(rt!=NULL)
		{
			Inorder(rt->left());//先左后根再右 
			cout<<rt->element()<<"";
			Inorder(rt->right());
		}
	}

	//二叉树深度
	int BinTree::BiTreeDepth(BiNode* rt)
	{
		int lh=0,rh=0 ;
		if(rt!=NULL)
		{
			lh=BiTreeDepth(rt->left());
			rh=BiTreeDepth(rt->right());
			return (lh>rh?lh:rh)+1;
		}
		
		else return 0 ;
	}

	//节点数统计
	int BinTree::count(BiNode* rt)
	{
		if(rt)  return count(rt->left())+count(rt->right())+1;
		else return 0;
	}


