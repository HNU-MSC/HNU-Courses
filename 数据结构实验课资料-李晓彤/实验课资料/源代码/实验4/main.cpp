/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include<iostream>
#include<assert.h>
#include<string.h>
#include "BST.h"
using namespace std;
int c[50];
int count=0;

int main(int argc, char** argv) {
	int depth=0;
	int num=0;//���Ľ�����
	BST T;
	cout<<"------�������Ƕ����������BST��ʵ��һ����̬���ұ�------"<<endl;
	cout<<"�������������(����0)��"<<endl;
	cin>>num;
	while(num<=0)
	{
		cout<<"����������������룺"<<endl;
		cin>>num;
	}
	
	cout<<"������Ҫ�������:";
	cout<<"����"<<num<<"����㣬��������Ҫ����ĸ���㣬֮���˳�����⣬ÿ������ֵ�ÿո����"<<endl;
	cout<<"���磺31 17 42 16 24 28"<<endl;
	int temp=0;
	//����+���� 
	for(int i=0;i<num;i++)
	{
		cin>>temp;
		T.insert(temp);
	}

	cout<<"���������";
	T.Inorder(T.getRoot());
	cout<<endl;
	cout<<"������ȣ�(������0��ʼ)";
	depth=T.BiTreeDepth(T.getRoot());
	cout<<--depth<<endl;
	cout<<"���Ľ�������";
	num=T.count(T.getRoot());
	cout<<num<<endl;
	
	cout<<"���������в��Ҳ���:";
	cout<<"������Ҫ���ҵ�Ԫ�أ�ctrl+Z��������"<<endl;
	while(cin>>temp)
	{
		int bijiao=T.find(T.getRoot(),temp);
		if(bijiao<=0)
		{
			cout<<"��Ǹ����Ҫ���ҵ�"<<temp<<"���ڸ�����"<<",����һ�������ıȽϴ���Ϊ�� "<<bijiao+1024<<endl; 
		}
		if(bijiao>0)
		{
			cout<<"���ҳɹ�"<<",����һ�������ıȽϴ���Ϊ�� "<<bijiao<<endl;
		}
		cout<<"������Ҫ���ҵ�Ԫ�أ�ctrl+Z��������"<<endl;
	}
	system("pause");
	return 0;	
}
