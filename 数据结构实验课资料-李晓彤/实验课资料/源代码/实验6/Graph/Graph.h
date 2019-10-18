#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include<stack>
#include <cstdlib>

#include<cstring>

using namespace std;

//邻接矩阵实现图

class Graph {
	private:
		void operator=(const Graph&) {} // Protect assignment
		Graph(const Graph&) {}         // Protect copy constructor
	public:
		Graph() {}         // Default constructor默认构造函数
		virtual ~Graph() {} // Basedestructor 析构函数

		// Initialize a graph of nvertices 初始化一有n个顶点的图
		virtual void Init(int n) =0;

		// Return: the number of verticesand edges 返回图的顶点数、边数
		virtual int n() =0;//图的顶点个数
		virtual int e() =0;//图的边的个数

		// Return v's first neighbor 返回顶点v的第一个邻居
		virtual int first(int v) =0;

		// Return v's next neighbor 返回在w点之后的邻居（与物理存储中的存放位置有关）
		virtual int next(int v, int w) =0;


		// Set the weight for an edge 为边(v1,v2)设置权值
		virtual void setEdge(int v1, int v2, int wght) =0;

		// Delete an edge删除边(v1,v2)
		virtual void delEdge(int v1, int v2) =0;

		// Determine if an edge is in the graph 判断边(i,j)是否在图中
		virtual bool isEdge(int i, int j) =0;

		// Return an edge's weight 返回边的权值
		virtual int weight(int v1, int v2) =0;

		// Get and Set the mark value fora vertex 取得和设置顶点的标志位
		virtual int getMark(int v) =0;
		virtual void setMark(int v, int val) =0;

		//返回某个顶点的值(实际信息)
		//virtual int getVex(int v)=0;

		//给某个顶点赋值
		virtual void putVex(int v,int value) =0;
};
#define MAX_VERTEX_NUM 40

#define UNVISITED 0

#define VISITED 1

class Graphm: public Graph {

	private:

		int numVertex,numEdge; //顶点数和边数

		int vexs[MAX_VERTEX_NUM];//存储顶点信息

		int** matrix;           //Pointer to adjacency matrix 指向邻接矩阵matrix

		int* mark;              // Pointer to mark array 指向mark数组
		
		int **connect;         //每个点和其他点的联系关系数组 
	public:
		// Constructor 构造函数
		Graphm();

		// Destructor 析构函数
		~Graphm();

		// Initialize the graph初始化图
		void Init(int n);

		int n();
		int e();


		// Return first neighbor of"v" 返回v的第一个邻居

		int first(int v);


		// Return v's next neighbor after w 返回v的在w后的邻居

		int next(int v, int w);
		

		/**返回某个顶点的值(实际信息) **/
		//int getVex(int v);
		
		/**给某个顶点赋值**/
		void putVex(int v,int value);

		// Set edge (v1, v2) to"wt" 设置边(v1,v2)的权值为wt
		void setEdge(int v1, int v2, int wt);

      	//Delete edge (v1, v2) 删除边(v1,v2)
		void delEdge(int v1, int v2);

		// Is(i, j) an edge? 判断边(i,j)是图中的一条边吗？
		bool isEdge(int i, int j);

		int weight(int v1, int v2);
		int getMark(int v);
		void setMark(int v, int val);
		void clearMark();//清空标志数组 
		
		void printvexs(int n);//输出邻接矩阵 
		
		//bool find(int start,int end);//寻找函数 
	    void DFS(int start,int curr);//深度优先遍历
		void printcon(int n);//输出每个点的联系矩阵 
		bool searchcon(int start);//检查这个点和其他顶点的联系情况 
};
#endif
