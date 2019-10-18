#include <iostream>
#include "Graph.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"------��ӭ�������ڽӾ���ʵ�ֵ�ͨ������------"<<endl;
	int n=0;
	cout<<"�����벿������N: "<<endl;
	cin>>n;
	cout<<"�����뵥��ͨ·������M��"<<endl;
	int num=0;
	cin>>num; 
	//cout<<"��������"<<n<<"������,����֮���ÿո���������繹��һ��5�������ͼ��������A B C D E"<<endl;
	Graphm G;
	G.Init(n);
	for(int i=0;i<n;i++)
	{
		G.putVex(i,i+1);
	}
	cout<<"������������"<<num<<"������ͨ·��Ʃ��˵1 2��һ���������� 1 2 �������붥���м��ÿո����"<<endl;
	int a,b;
	int weight=1;
	while(num!=0)
	{
		cin>>a>>b;
		G.setEdge(a,b,weight);
		num=num-1;
	} 
	cout<<"����������ڽӾ��� "<<endl;
	G.printvexs(n);
	cout<<"�������ж��ж��ٸ�����֪������N�����ŵĴ��ڣ� "<<endl;
	//cout<<"��������ʼ���㣺 "<<endl;
	//cin>>a;
	int know=0;
	for(int i=0;i<n;i++)
	{
		G.DFS(i,i);
		G.clearMark(); 
	}
	cout<<"��ͼ��ÿ������֪���Ĳ��ţ�Ϊ1��֪����0�ǲ�֪����"<<endl;
	G.printcon(n);
	for(int i=0;i<n;i++)
	{
		if(G.searchcon(i)==true)
		know++;
	}
	cout<<"��ô���Ի���"<<know<<"������֪������N�����ŵĴ��ڣ�"<<endl; 
	system("pause");
	return 0;
}
