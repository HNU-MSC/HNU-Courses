#ifndef LCRBBINTREE_H
#define LCRBBINTREE_H
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
typedef char E;
struct ValNode {
	private:
		E val;
	public:
		ValNode();
		
		//���ؽڵ�Ԫ��
		E element();
		
		//���ýڵ�Ԫ��
		void setElement(E);
};
struct PNode {
	private:
		int p;// Index of father
	public:
		PNode();
			
		int parent();//���ظ����±�
		
		void setparent(int);//���ø����±�
		
};
struct LNode {
	private:
		int lc;// Index of leftchild
	public:
		LNode();	
			
		//���������±�
		int left();

		//��������
		void setLeft(int,int);
};
struct RbNode {
	private:
		int rb;// Index of rightsibling
	public:
		RbNode();
		
		//�������ֵ��±�
		int rightsibling();

		//�����Һ���
		void setRightsibling(int,int);
};
class LcRbBinTree
{
private:
	int root;                //Root of the BinTree BinTree���ĸ����
public:
	vector<LNode> leftArray;         //��left����洢���ӽڵ�
	vector<ValNode> valArray;         //��val����洢�ڵ�ֵ
	vector<PNode> parArray;         //��par����洢���׽ڵ� 
	vector<RbNode> rightArray;         //��right����洢���ֵܽڵ�
	int Root();
	
	void setroot(int);

	//�Ƿ�Ϊ����
	bool BiTreeEmpty(int);

	//��α���
	void LevelOrderTraverse(string,int);
	
	//�������
	int BiTreeDepth(int);
	
	//������
	int count(string,int);
	
	//�������
	void PrintParent(int);
	
	//�������
	void PrintLeft(int);
	 
	//������ֵ�
	void PrintRight(int); 
};
 

#endif
