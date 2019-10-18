#include <iostream>
#define MAX 1000
using namespace std;
struct Vertex {
	char data;
};
class Edge {
	public:
		int vert,wt;//�洢����ָ��Ķ���ı�źͱ�����Ӧ��Ȩ 
		Edge* next = NULL;//ָ����һ���� 
		Edge(int v,int w) {
			vert=v;
			wt=w; 
			next = NULL;
		}
		void setver(int v){
			vert = v;
		}
		void setwt(int w){
			wt = w;
		}
		//�õ���� 
		int vertex() {
			return vert;
		}
		
		//�õ�Ȩֵ 
		int weight() {
			return wt;
		}
};
//ÿһ����������� 
struct graphlist {
	Vertex ver;
	Edge* head;
	Edge* curr;
};
class Graphl {
	private:
		int numVertex,numEdge;//������  ���� 
		int *mark;//���Ƿ񱻷��ʹ��� 
		graphlist gl[MAX];//������� 
		void Init(int n);//��ʼ�� 
	public:
		Graphl() {}
		Graphl(int numVert);
		~Graphl();

		int n();//������ 
		int e();//���� 
		int locateVex(char u);
		Vertex getVex(int v);
		void putVex(int v,char value);
		int first(int v);
		int next(int v,int w);
		int weight(int v1,int v2);

		bool isEdge(int i,int j);
		void setEdge(int v1,int v2,int wgt);
		void delEdge(int v1,int v2);

		int getMark(int v);
		void setMark(int v, int val);

		void DFS(int v);
		void show();
};
