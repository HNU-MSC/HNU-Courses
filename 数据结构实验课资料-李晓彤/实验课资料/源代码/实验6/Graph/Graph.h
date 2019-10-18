#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include<stack>
#include <cstdlib>

#include<cstring>

using namespace std;

//�ڽӾ���ʵ��ͼ

class Graph {
	private:
		void operator=(const Graph&) {} // Protect assignment
		Graph(const Graph&) {}         // Protect copy constructor
	public:
		Graph() {}         // Default constructorĬ�Ϲ��캯��
		virtual ~Graph() {} // Basedestructor ��������

		// Initialize a graph of nvertices ��ʼ��һ��n�������ͼ
		virtual void Init(int n) =0;

		// Return: the number of verticesand edges ����ͼ�Ķ�����������
		virtual int n() =0;//ͼ�Ķ������
		virtual int e() =0;//ͼ�ıߵĸ���

		// Return v's first neighbor ���ض���v�ĵ�һ���ھ�
		virtual int first(int v) =0;

		// Return v's next neighbor ������w��֮����ھӣ�������洢�еĴ��λ���йأ�
		virtual int next(int v, int w) =0;


		// Set the weight for an edge Ϊ��(v1,v2)����Ȩֵ
		virtual void setEdge(int v1, int v2, int wght) =0;

		// Delete an edgeɾ����(v1,v2)
		virtual void delEdge(int v1, int v2) =0;

		// Determine if an edge is in the graph �жϱ�(i,j)�Ƿ���ͼ��
		virtual bool isEdge(int i, int j) =0;

		// Return an edge's weight ���رߵ�Ȩֵ
		virtual int weight(int v1, int v2) =0;

		// Get and Set the mark value fora vertex ȡ�ú����ö���ı�־λ
		virtual int getMark(int v) =0;
		virtual void setMark(int v, int val) =0;

		//����ĳ�������ֵ(ʵ����Ϣ)
		//virtual int getVex(int v)=0;

		//��ĳ�����㸳ֵ
		virtual void putVex(int v,int value) =0;
};
#define MAX_VERTEX_NUM 40

#define UNVISITED 0

#define VISITED 1

class Graphm: public Graph {

	private:

		int numVertex,numEdge; //�������ͱ���

		int vexs[MAX_VERTEX_NUM];//�洢������Ϣ

		int** matrix;           //Pointer to adjacency matrix ָ���ڽӾ���matrix

		int* mark;              // Pointer to mark array ָ��mark����
		
		int **connect;         //ÿ��������������ϵ��ϵ���� 
	public:
		// Constructor ���캯��
		Graphm();

		// Destructor ��������
		~Graphm();

		// Initialize the graph��ʼ��ͼ
		void Init(int n);

		int n();
		int e();


		// Return first neighbor of"v" ����v�ĵ�һ���ھ�

		int first(int v);


		// Return v's next neighbor after w ����v����w����ھ�

		int next(int v, int w);
		

		/**����ĳ�������ֵ(ʵ����Ϣ) **/
		//int getVex(int v);
		
		/**��ĳ�����㸳ֵ**/
		void putVex(int v,int value);

		// Set edge (v1, v2) to"wt" ���ñ�(v1,v2)��ȨֵΪwt
		void setEdge(int v1, int v2, int wt);

      	//Delete edge (v1, v2) ɾ����(v1,v2)
		void delEdge(int v1, int v2);

		// Is(i, j) an edge? �жϱ�(i,j)��ͼ�е�һ������
		bool isEdge(int i, int j);

		int weight(int v1, int v2);
		int getMark(int v);
		void setMark(int v, int val);
		void clearMark();//��ձ�־���� 
		
		void printvexs(int n);//����ڽӾ��� 
		
		//bool find(int start,int end);//Ѱ�Һ��� 
	    void DFS(int start,int curr);//������ȱ���
		void printcon(int n);//���ÿ�������ϵ���� 
		bool searchcon(int start);//��������������������ϵ��� 
};
#endif
