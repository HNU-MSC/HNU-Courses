#include <iostream>
#include "Graph.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"------��ӭ�������ڽӾ���ʵ�ֵ�ͼ��------"<<endl;
	int n=0;
	cout<<"������Ҫ�����ͼ�Ķ�����: "<<endl;
	cin>>n;
	cout<<"��������"<<n<<"������,����֮���ÿո���������繹��һ��5�������ͼ��������A B C D E"<<endl;
	char c[n];
	Graphm G;
	G.Init(n);
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		G.putVex(i,c[i]);
	}
	cout<<"�����������"<<endl;
	int num=0;
	cin>>num; 
	cout<<"������������"<<num<<"���ߣ�Ʃ��˵A B��һ��ȨֵΪ20�ıߣ������� A B 20�������붥���Ȩֵ�м��ÿո����"<<endl;
	char a,b;
	int weight=0,v1=0,v2=0;
	while(num!=0)
	{
		cin>>a>>b>>weight;
		for(int i=0;i<n;i++)
		{
			if(c[i]==a)
			{
				v1=i;
			}
			if(c[i]==b)
			{
				v2=i;
			}	
		}
		G.setEdge(v1,v2,weight);
		num=num-1;
	} 
	cout<<"����������ڽӾ��� "<<endl;
	G.printvexs(n);
	cout<<"����������ͼ�ı����� "<<endl;
	cout<<"��������ʼ���㣺 "<<endl;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		if(a==c[i])
		{
			v1=i;
			break;	
		}
	}
	cout<<"����������ȱ����Ľ���� "<<endl;
	G.DFS(v1);
	cout<<endl; 
	cout<<"��������Ҫɾ���ıߣ����� A B "<<endl; 
		cin>>a>>b;
		for(int i=0;i<n;i++)
		{
			if(c[i]==a)
			{
				v1=i;
			}
			if(c[i]==b)
			{
				v2=i;
			}	
		}
		G.delEdge(v1,v2);
	cout<<"ɾ���ߺ���ڽӾ���Ϊ�� "<<endl;
	G.printvexs(n);
	cout<<"�������жϱ�(i,j)�Ƿ���ͼ�е�һ����"<<endl;
	cout<<"��������Ҫ�жϵıߣ����� A B"<<endl;
	cin>>a>>b;
		for(int i=0;i<n;i++)
		{
			if(c[i]==a)
			{
				v1=i;
			}
			if(c[i]==b)
			{
				v2=i;
			}	
		}
		if(G.isEdge(v1,v2)==true)
		{
			cout<<a<<" "<<b<<"��ͼ�е�һ���ߣ�"<<endl; 
		}
	 	else cout<<a<<" "<<b<<"����ͼ�е�һ���ߣ�"<<endl; 
	system("pause");
	return 0;
}
