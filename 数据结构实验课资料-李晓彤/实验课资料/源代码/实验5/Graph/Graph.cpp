#include "Graph.h"
#include<iomanip>
#include <iostream>
using namespace std;
Graphm::Graphm() {   // Constructor ���캯��
	Init(1000);
}

Graphm::~Graphm() {     // Destructor ��������
	cout<<"ɾ��ͼ��...";

	delete []mark; // Return dynamicallyallocated memory���ն�̬�����ڴ�

	for (int i=0; i<numVertex; i++)

		delete []matrix[i];

	delete []matrix;

}



void Graphm::Init(int n) { // Initialize the graph��ʼ��ͼ

	int i;

	numVertex =n;

	numEdge = 0;

	mark = new int[n];     // Initialize mark array ��ʼ��mark����

	for(i=0; i<MAX_VERTEX_NUM; i++) { //��ʼ���������飬/��ʾ��
		vexs[i]='/';
	}
	for (i=0; i<numVertex; i++)

		mark[i] =UNVISITED;

	matrix =(int**) new int*[numVertex]; //Make matrix ��ʼ���ڽӾ���

	for (i=0; i<numVertex; i++)

		matrix[i]= new int[numVertex];

	for (i=0; i< numVertex; i++) //Initialize to 0 weights ��ʼ��ȨֵΪ0

		for (int j=0; j<numVertex; j++)

			matrix[i][j] = 0;

}

int Graphm::n() {
	return numVertex;    //Number of vertices ���ؽڵ���
}

int Graphm::e() {
	return numEdge;    // Number of edges ���ر���
}

// Return first neighbor of"v" ����v�ĵ�һ���ھ�
int Graphm::first(int v) {

	for (int i=0; i<numVertex; i++)

		if(matrix[v][i] != 0) return i;

	return numVertex;           // Return n if none ���û���ھӷ��ؽڵ���

}

// Return v's next neighbor after w ����v����w����ھ�
int Graphm::next(int v, int w) {

	for(int i=w+1; i<numVertex; i++)

		if(matrix[v][i] != 0)

			return i;

	return numVertex;           // Return n if none���û���ھӷ��ؽڵ���

}

/**����ĳ�������ֵ(ʵ����Ϣ) **/

char Graphm::getVex(int v) {

	return vexs[v];
}

/**��ĳ�����㸳ֵ**/

void Graphm::putVex(int v,char value) {
	vexs[v]=value;
}

// Set edge (v1, v2) to"wt" ���ñ�(v1,v2)��ȨֵΪwt
void Graphm::setEdge(int v1, int v2, int wt) {

	try {
		if(wt<=0) {
			throw "Illegal weight value";
		}
		
		if(matrix[v1][v2] == 0)
			numEdge++;
		matrix[v1][v2] = wt;
		matrix[v2][v1]=wt;
	} catch(const char* str) {
		cout<<str<<endl;
	}
}
void Graphm::DFS(int start)//������ȱ���
{
	cout<<vexs[start]<<' ';
	mark[start]=1;
	for(int i=0;i<numVertex;i++)
        if( mark[i] == 0 && matrix[start][i] !=0)
            DFS(i);
}
void Graphm::delEdge(int v1, int v2) { //Delete edge (v1, v2) ɾ����(v1,v2)

	if(matrix[v1][v2] != 0) {

		numEdge--;

		matrix[v1][v2] = 0;
		matrix[v2][v1]=0;
	}
	else cout<<"�ñ߲����ڣ�ɾ��ʧ�ܣ�"<<endl;
}

bool Graphm::isEdge(int i, int j) // Is(i, j) an edge? �жϱ�(i,j)��ͼ�е�һ������
{
	return matrix[i][j] != 0;
}

int Graphm::weight(int v1, int v2) {
	return matrix[v1][v2]||matrix[v2][v1];
}

int Graphm::getMark(int v) {
	return mark[v];
}

void Graphm::setMark(int v, int val) {
	mark[v] = val;
}
void Graphm::printvexs(int n)//����ڽӾ��� 
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
}
