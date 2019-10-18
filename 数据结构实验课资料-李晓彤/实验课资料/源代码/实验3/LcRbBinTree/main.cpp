#include<iostream>
#include<iomanip>
#include "LcRbBinTree.h"
using namespace std;
typedef char E;
char c[50];
string s;
ValNode v;
PNode p;
LNode lc;
RbNode rb;
LcRbBinTree T;

//���������Բ�α�������
int CreateBinTree(string s) {
	strcpy(c,s.c_str());
	int n=s.length();
	for(int i=0; c[i]!='\0'; i++) {
		//�������� 
		lc.setLeft(i,n);
		T.leftArray.push_back(lc);
	
		//����Ԫ��ֵ 
		v.setElement(c[i]);
		T.valArray.push_back(v);
		
		//���ø��� 
		if(i==0||c[i]=='/')
		{
			p.setparent(-1);
		}
		else p.setparent(i);
		T.parArray.push_back(p);
		
		//�������ֵ� 
		if(i%2!=0&&c[i]!='/')
		{
			rb.setRightsibling(i,n);
		}
		else rb.setRightsibling(-1,n);
		T.rightArray.push_back(rb);
	}
	return 0;//���ظ��ڵ��±�
}

int main()
{
	int r;

	int depth;

	int num;
	
	cout<<"-----��ӭ������������/���ֵ�ʵ�ֵĶ�����-----"<<endl;
	cout<<"��ʾ��"<<endl

	    <<"���ַ�����ʽ����Ҫ�����Ķ�����ʱ������α�����˳�����룬���еĿսڵ���/����"<<endl

	    <<"ע�⣡����Ҫ����������"<<endl

	    <<"����ABCDEF"<<endl

	    <<"�����룺";

	cin>>s;

	//����
	r=CreateBinTree(s);
	int i=s.length();

	cout<<"-----------------------------------"<<endl;

	cout<<"�ж����Ƿ��ǿ�����";

	if(T.BiTreeEmpty(r))
		{
			cout<<"����Ϊһ�ÿ���,�������"<<endl;
			return 0;
		}
	else cout<<"���ǿ���"<<endl;

	cout<<"��α�����";
	T.LevelOrderTraverse(s,i);

	cout<<endl;
	
	
	cout<<"��α����Ľ���Ӧ�ĸ��׽��Ϊ�� \n";
	T.PrintParent(r);
	cout<<endl; 
	
	cout<<"��α����Ľ���Ӧ�����ӽ��Ϊ�� \n";
	T.PrintLeft(r);
	cout<<endl; 
	
	cout<<"��α����Ľ���Ӧ�����ֵܽ��Ϊ�� \n";
	T.PrintRight(r);
	cout<<endl; 


	cout<<"������ȣ���������0��ʼ����";
	depth=T.BiTreeDepth(r);
	cout<<depth<<endl;

	cout<<"���Ľ�������";
	num=T.count(s,i);
	cout<<num<<endl;
	system("pause");
	return 0;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

