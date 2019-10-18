#include <iostream>
#define MAX 1000
using namespace std;
struct Vertex {
	char data;
};
class Edge {
	public:
		int vert,wt;//存储边所指向的顶点的编号和边所对应的权 
		Edge* next = NULL;//指向下一个边 
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
		//得到编号 
		int vertex() {
			return vert;
		}
		
		//得到权值 
		int weight() {
			return wt;
		}
};
//每一个顶点的链表 
struct graphlist {
	Vertex ver;
	Edge* head;
	Edge* curr;
};
class Graphl {
	private:
		int numVertex,numEdge;//顶点数  边数 
		int *mark;//边是否被访问过了 
		graphlist gl[MAX];//最大链表 
		void Init(int n);//初始化 
	public:
		Graphl() {}
		Graphl(int numVert);
		~Graphl();

		int n();//顶点数 
		int e();//边数 
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
