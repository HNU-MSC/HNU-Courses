#include <iostream>
#include "Graphl.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv){
	cout<<"---��ӭ�����ڽӱ�ʵ�ֵ�ͼ��---"<<endl;
	cout << "������ͼ�Ķ�����" << endl;
	int n=0;
	cin >> n;
	
	cout << "������"<<n<<"�����㣬����5������������ A B C D E���м��ö��Ÿ�����" << endl;
	
	Graphl G(n);
	
	cout<<"ͼ������ɣ�"<<endl;
	int Bnum=0;
	cout<<"����������� "<<endl;
	cin>>Bnum;
	
	char v1,v2;
	int w,p;
	cout << "������"<<Bnum<<"����" << endl;
	cout<<"����A B ��һ��ȨֵΪ10�ıߣ������� A B 10"<<endl;
	for(int i=0;i<Bnum;i++)
	{
		cin>>v1>>v2>>w;
		G.setEdge(G.locateVex(v1),G.locateVex(v2),w);
	}
	
	cout << "�±�Ϊͼ���ڽӱ�������Ϊ�ñߵ�Ȩֵ" << endl;
	G.show();
    
    cout << "��ͼ����" << G.n() << "������" << endl;
	cout << "��ͼ����" << G.e() << "����" << endl; 
	
	cout<<"���������жϱ��Ƿ���ڣ�"<<endl;
	cout<<"���������жϵıߣ����� ���� A B"<<endl; 
	cin>>v1>>v2;
	if(G.isEdge(G.locateVex(v1),G.locateVex(v2)))
	cout<<"�ߴ��ڣ�"<<endl;
	else cout<<"�ñ߲����ڣ�"<<endl;
	
	cout<<"������������ȱ�����"<<endl; 
	cout << "������ʼ�������ƽ��б���" << endl;
	cin>>v1;
	cout<<"����������ȱ����Ľ����"<<endl;
	G.DFS(G.locateVex(v1));
	
	cout << "��������ɾ���߲�������������ɾ���ıߣ�������ɾ�� A B�ߣ������� A B" << endl;
	cin>>v1>>v2; 
	G.delEdge(G.locateVex(v1),G.locateVex(v2));
	
	cout << "�±�Ϊɾ�����ߵ�ͼ���ڽӱ�������Ϊ�ñߵ�Ȩֵ" << endl;
	G.show();
	
	cout << "��ͼ����" << G.n() << "������" << endl;
	cout << "��ͼ����" << G.e() << "����" << endl; 
	system("pause");
	return 0;
}
