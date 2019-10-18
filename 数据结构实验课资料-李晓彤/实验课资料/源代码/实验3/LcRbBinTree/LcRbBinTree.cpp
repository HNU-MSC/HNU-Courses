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

		//���ؽڵ�Ԫ��
	E ValNode::element() {
			return val;
		}

		//���ýڵ�Ԫ��
		void ValNode::setElement(E e) {
			val = e;
		}
		
		PNode::PNode()
		{
			p=-1;
		}
		//���ظ����±�
		int PNode::parent()
		{
			return p;
		}
		
		
		//���ø����±�
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
		//���������±�
		int LNode::left(){
			return lc;
		}

		//��������
		void LNode::setLeft(int i,int n) {
			if(2*i+1<n)
			lc = 2*i+1;
			else lc=-1;
		}
		
		RbNode::RbNode()
		{
			rb=-1;
		}
		//�������ֵ��±�
		int RbNode::rightsibling() {
			return rb;
		}

		//�������ֵ� 
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

	//�Ƿ�Ϊ����
	bool LcRbBinTree::BiTreeEmpty(int rt)
	{
		if(valArray[rt].element()=='/')
			return true; //��һ�ÿ���
		else
			return false;//���ǿ���
	}

	//��α���
	void LcRbBinTree::LevelOrderTraverse(string rt,int n)
	{
		for(int i=0;i<n;i++)
		{
			if(rt[i]=='/')
			continue;
			else cout<<rt[i]<<' ';
		}
	}

	
	//�������
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

	//������
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
	
	//�������
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
	
	//�������
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
	 
	//������ֵ�
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
