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
		
		BiNode();//���캯�� 

		BiNode(char e,BiNode* l,BiNode* r);//���ι��캯�� 
		char& element();//�õ�����ֵ 

		void setElement(char& e); //��������ֵ 
		
		
		BiNode* left();//�������ӵĵ�ַ 
		void setLeft(BiNode* b); //�������ӵ�ֵ 
		
		
		BiNode* right(); //�����Һ���
		void setRight(BiNode* b);//�����Һ��ӵ�ֵ 
		
		//�ж��Ƿ�ΪҶ�ӽڵ�
		bool isLeaf();
};

class BinTree:public BiNode {
private:
	char c;
	BiNode* root;   // Root of the BinTree BinTree���ĸ����
public:

	BiNode* Root();//BiNodeָ����ķ��ظ���� 
	void setroot(BiNode* n);//���ø���� 

	//�ж϶������Ƿ�Ϊ��
	bool BiTreeEmpty(BiNode* rt);


	//�������
	void Inorder(BiNode* rt);

	//���������
	int BiTreeDepth(BiNode* rt);

	//�ڵ���ͳ��
	int count(BiNode* rt);
};

#endif
