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
		
		//返回节点元素
		E element();
		
		//设置节点元素
		void setElement(E);
};
struct PNode {
	private:
		int p;// Index of father
	public:
		PNode();
			
		int parent();//返回父亲下标
		
		void setparent(int);//设置父亲下标
		
};
struct LNode {
	private:
		int lc;// Index of leftchild
	public:
		LNode();	
			
		//返回左结点下标
		int left();

		//设置左孩子
		void setLeft(int,int);
};
struct RbNode {
	private:
		int rb;// Index of rightsibling
	public:
		RbNode();
		
		//返回右兄弟下标
		int rightsibling();

		//设置右孩子
		void setRightsibling(int,int);
};
class LcRbBinTree
{
private:
	int root;                //Root of the BinTree BinTree树的根结点
public:
	vector<LNode> leftArray;         //用left数组存储左孩子节点
	vector<ValNode> valArray;         //用val数组存储节点值
	vector<PNode> parArray;         //用par数组存储父亲节点 
	vector<RbNode> rightArray;         //用right数组存储右兄弟节点
	int Root();
	
	void setroot(int);

	//是否为空树
	bool BiTreeEmpty(int);

	//层次遍历
	void LevelOrderTraverse(string,int);
	
	//树的深度
	int BiTreeDepth(int);
	
	//结点个数
	int count(string,int);
	
	//输出父亲
	void PrintParent(int);
	
	//输出左孩子
	void PrintLeft(int);
	 
	//输出右兄弟
	void PrintRight(int); 
};
 

#endif
