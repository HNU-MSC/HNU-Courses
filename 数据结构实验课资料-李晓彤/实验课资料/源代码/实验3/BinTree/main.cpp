/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<iostream>
#include<assert.h>
#include<string.h>
#include "BinTree.h"
using namespace std;
char c[50];
int count=0;
BinTree T;
//����
BiNode*CreateBinTree(char ch) {
	BiNode* rt;
	if(ch=='/')  rt=NULL;
	else {
		rt=new BiNode;
		rt->setElement(ch);//�������� 
		ch=c[++count];//������ɹ����������һ 
		rt->setLeft(CreateBinTree(ch));//�������� 
		ch=c[++count];
		rt->setRight(CreateBinTree(ch));//�����Һ��� 
	}
	//���ø��ڵ�
	T.setroot(rt);
	return rt;
}
int main(int argc, char** argv) {	
	char ch;
	int depth=0;
	int num=0;
	BiNode* r;
	string s;
	cout<<"------�������Ƕ���������ʵ�ֶ�����------"<<endl;
	cout<<"������Ҫ�������:"; 
	cout<<"��ǰ�������˳������(ҲҪ��Ҷ�ӽ�����������������)���սڵ���/����,��AB/D//CE//F//"<<endl;
	cin>>s;
	strcpy(c,s.c_str());
	r=CreateBinTree(c[0]);
	cout<<"�ж����Ƿ��ǿ�����";
		if(T.BiTreeEmpty(r))
			cout<<"No"<<endl;
		else 
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"���������";
		T.Inorder(r);
		cout<<endl;
	cout<<"������ȣ�(������0��ʼ)";
		depth=T.BiTreeDepth(r);
		cout<<--depth<<endl;
	cout<<"���Ľ�������";
		num=T.count(r);
		cout<<num<<endl;
	return 0;
	system("pause"); 
}
