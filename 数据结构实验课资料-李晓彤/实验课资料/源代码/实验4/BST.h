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
		BiNode* root;   // Root of the BinTree BinTree���ĸ����
		int nodeCount;
	public:
		BST();
		~BST();
		void clear(BiNode* node);
		
		BiNode* getRoot();//BiNodeָ����ķ��ظ����
		
		//����+���� 
		void insert(const int ); 
		BiNode* inserthelp(BiNode* root,const int);

		int find(BiNode*,const int);//����

		//�������
		void Inorder(BiNode* rt);

		//���������
		int BiTreeDepth(BiNode* rt);

		//�ڵ���ͳ��
		int count(BiNode* rt);
};

#endif
