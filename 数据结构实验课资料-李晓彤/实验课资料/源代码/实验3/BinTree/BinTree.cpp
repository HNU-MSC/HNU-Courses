#include <iostream>
#include "BinTree.h"
#include<queue>
using namespace std;
	BiNode::BiNode() {//���Ĺ��캯�� 
			lc = rc = NULL;
		}

	BiNode::BiNode(char e,BiNode* l,BiNode* r) {//���ĺ��ι��캯�� 
			it = e;
			lc = l;
			rc = r;
		}

	char& BiNode::element() {//ȡ�ý��ֵ 
			return it;
		}

	void BiNode::setElement(char& e) {//���ý��ֵ 
			it = e;
		}

		//��������
	BiNode*BiNode::left() {
			return lc;
		}

	void BiNode::setLeft(BiNode* b) {
			lc = (BiNode*)b;//�������ӵ�ֵ 
		}

		//�����Һ���
	BiNode*BiNode::right(){
			return rc;
		}

	void BiNode::setRight(BiNode* b) {
			rc = (BiNode*)b;
		}

	//�ж��Ƿ�ΪҶ�ӽڵ�
	bool BiNode::isLeaf() {
			return (lc == NULL) && (rc == NULL);
		}

	BiNode*BinTree:: Root() {
		return root;
	}
	
	void BinTree::setroot(BiNode* n) {
		root=n;
	}

	//�ж϶������Ƿ�Ϊ��
	bool BinTree::BiTreeEmpty(BiNode* rt)
	{
		if(rt!=NULL) return true;
		else return false;
	}

	
	//�������
	void BinTree::Inorder(BiNode* rt)
	{
		if(rt!=NULL)
		{
			Inorder(rt->left());//���������� 
			cout<<rt->element()<<"";
			Inorder(rt->right());
		}
	}

	//���������
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

	//�ڵ���ͳ��
	int BinTree::count(BiNode* rt)
	{
		if(rt)  return count(rt->left())+count(rt->right())+1;
		else return 0;
	}


