#include "BST.h"
#include <iostream>
#include<queue>
using namespace std;
	BST::BST()
	{
		root = NULL;
		nodeCount = 0;
	}	
	BST::~BST()
	{	
		void clear();
	}
	
	void clear(BiNode* node)
	{
		if(node = NULL)
		return;
		else
		{
			if(node->getleft()!=NULL)
				clear(node->getleft());
			
			if(node->getright()!=NULL)
				clear(node->getright());
		}
		node = NULL;
		delete node;
		return;
	}
	BiNode*BST::getRoot() {
		return root;
	}
	//查找 
	int BST::find(BiNode*rt ,const int k)//查找
	{
		if(rt==NULL)return -1024;//未找到 
		if(k<rt->getelement()) 
		{
			return 1+find(rt->getleft(),k);//找左边 
		}
		else if(k>rt->getelement())
		{
			return 1+find(rt->getright(),k);//找右边 
		}
		else if(k==rt->getelement())
		{
			return 1;//找到 
		}
	} 
	//插入+创建
	void BST::insert(const int elem)
	{
		root=inserthelp(root,elem);
	} 
	BiNode*BST::inserthelp(BiNode* root,const int val)
	{
		if(root==NULL)
		{
			nodeCount++;
			return new BiNode(val,NULL,NULL);
		}
		if(val<root->getelement())
		root->setleft(inserthelp(root->getleft(),val));
		else if(val>=root->getelement())
		root->setright(inserthelp(root->getright(),val));
		return root;
	}
	
	//中序遍历
	void BST::Inorder(BiNode* rt)
	{
		if(rt!=NULL)
		{
			Inorder(rt->getleft());//先左后根再右 
			cout<<rt->getelement()<<" ";
			Inorder(rt->getright());
		}
	}

	//二叉树深度
	int BST::BiTreeDepth(BiNode* rt)
	{
		int lh=0,rh=0 ;
		if(rt!=NULL)
		{
			lh=BiTreeDepth(rt->getleft());
			rh=BiTreeDepth(rt->getright());
			return (lh>rh?lh:rh)+1;
		}
		
		else return 0 ;
	}

	//节点数统计
	int BST::count(BiNode* rt)
	{
		if(rt)  return count(rt->getleft())+count(rt->getright())+1;
		else return 0;
	}
