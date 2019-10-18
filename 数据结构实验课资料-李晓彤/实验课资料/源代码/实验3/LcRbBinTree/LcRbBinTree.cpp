#include "LcRbBinTree.h"
#include<vector>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
typedef char E;
	ValNode::ValNode() {
			val= 0;
		}

		//返回节点元素
	E ValNode::element() {
			return val;
		}

		//设置节点元素
		void ValNode::setElement(E e) {
			val = e;
		}
		
		PNode::PNode()
		{
			p=-1;
		}
		//返回父亲下标
		int PNode::parent()
		{
			return p;
		}
		
		
		//设置父亲下标
		void PNode::setparent(int i)
		{
			if(i==-1)
			p=-1;
			else p=(i-1)/2;
		}	
		
		LNode::LNode()
		{
			lc=-1;
		}
		//返回左结点下标
		int LNode::left(){
			return lc;
		}

		//设置左孩子
		void LNode::setLeft(int i,int n) {
			if(2*i+1<n)
			lc = 2*i+1;
			else lc=-1;
		}
		
		RbNode::RbNode()
		{
			rb=-1;
		}
		//返回右兄弟下标
		int RbNode::rightsibling() {
			return rb;
		}

		//设置右兄弟 
		void RbNode::setRightsibling(int i,int n) {
			if(i==-1)
			{
				rb =-1;
			}
			else if(i+1<n)
			rb = i+1;
			else rb=-1;
		}

	  
	int LcRbBinTree::Root() {
		return 0;
	}
	
	void LcRbBinTree::setroot(int n) {
		root=n;
	}

	//是否为空树
	bool LcRbBinTree::BiTreeEmpty(int rt)
	{
		if(valArray[rt].element()=='/')
			return true; //是一棵空树
		else
			return false;//不是空树
	}

	//层次遍历
	void LcRbBinTree::LevelOrderTraverse(string rt,int n)
	{
		for(int i=0;i<n;i++)
		{
			if(rt[i]=='/')
			continue;
			else cout<<rt[i]<<' ';
		}
	}

	
	//树的深度
	int LcRbBinTree::BiTreeDepth(int rt)
	{
		int num=1;
		if(parArray.size()==1)
		return 0;
		if(parArray.size()<=3)
		return 1;
		if(valArray[rt].element()!='/')
		{
			for(int i=0;i<parArray.size();i++)
			{
				if(parArray[i].parent()==-1)
				{
					continue;
				}
				else num=parArray[i].parent();
			}
			if(num%2!=0)
			return ++num;
			else if(num%2==0)
			return num;
		}
		else return 0 ;
	}

	//结点个数
	int LcRbBinTree::count(string s,int n)
	{
		int count=0;
		if(s[0]!='/') 
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='/')
				continue; 
				else count++;
			}
			return count;
		}
		else return 0;
	}
	
	//输出父亲
	void LcRbBinTree::PrintParent(int rt)
	{
		for(int i=rt;i<parArray.size();i++)
		{
			if(valArray[i].element()=='/')
			continue;
			if(parArray[i].parent()==-1)
			cout<<'/'<<' ';
			else 
			cout<<valArray[parArray[i].parent()].element()<<' ';
		}
		cout<<endl;
	}
	
	//输出左孩子
	void LcRbBinTree::PrintLeft(int rt)
	{
		for(int i=rt;i<leftArray.size();i++)
		{
			if(valArray[i].element()=='/')
			continue;
			if(leftArray[i].left()==-1)
			cout<<'/'<<' ';
			else 
			cout<<valArray[leftArray[i].left()].element()<<' ';
		}
		cout<<endl;
	}
	 
	//输出右兄弟
	void LcRbBinTree::PrintRight(int rt)
	{
		for(int i=rt;i<rightArray.size();i++)
		{
			if(valArray[i].element()=='/')
			continue;
			if(rightArray[i].rightsibling()==-1)
			cout<<'/'<<' ';
			else 
			cout<<valArray[rightArray[i].rightsibling()].element()<<' ';
		}
		cout<<endl;
	}
