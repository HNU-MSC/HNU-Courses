#include "Graph.h"
#include<iomanip>
#include <iostream>
using namespace std;
Graphm::Graphm() {   // Constructor 构造函数
	Init(1000);
}

Graphm::~Graphm() {     // Destructor 析构函数
	cout<<"删除图中...";

	delete []mark; // Return dynamicallyallocated memory回收动态分配内存

	for (int i=0; i<numVertex; i++)

		{
			delete []matrix[i];
			delete []connect[i]; 
		} 

	
	delete []matrix;
	delete []connect;
}

void Graphm::Init(int n) { // Initialize the graph初始化图

	int i;

	numVertex =n;

	numEdge = 0;

	mark = new int[n];     // Initialize mark array 初始化mark数组

	for(i=0; i<MAX_VERTEX_NUM; i++) { //初始化顶点数组，/表示空
		vexs[i]='/';
	}
	for (i=0; i<numVertex; i++)

		mark[i] =UNVISITED;

	matrix =(int**) new int*[numVertex]; //Make matrix 初始化邻接矩阵
	connect=(int**) new int*[numVertex];
	for (i=0; i<numVertex; i++)
		{
			matrix[i]= new int[numVertex];
			connect[i]=new int[numVertex];
		}
	for (i=0; i< numVertex; i++) //Initialize to 0 weights 初始化权值为0

		for (int j=0; j<numVertex; j++)
			{
				matrix[i][j] = 0;
				connect[i][j]=0;
			}
}

int Graphm::n() {
	return numVertex;    //Number of vertices 返回节点数
}

int Graphm::e() {
	return numEdge;    // Number of edges 返回边数
}

// Return first neighbor of"v" 返回v的第一个邻居
int Graphm::first(int v) {

	for (int i=0; i<numVertex; i++)

		if(matrix[v][i] != 0) return i;

	return numVertex;           // Return n if none 如果没有邻居返回节点数

}

// Return v's next neighbor after w 返回v的在w后的邻居
int Graphm::next(int v, int w) {

	for(int i=w+1; i<numVertex; i++)

		if(matrix[v][i] != 0)

			return i;

	return numVertex;           // Return n if none如果没有邻居返回节点数

}

/**返回某个顶点的值(实际信息) **/

//char Graphm::getVex(int v) {

//	return vexs[v];
//}

/**给某个顶点赋值**/

void Graphm::putVex(int v,int value) {
	vexs[v]=value;
}
/*
bool Graphm::find(int start,int end)
{	
	if(matrix[start][end]==1)//有直达的
	return true;
	else{//没有直达的
		for(int i=0;i<numVertex;i++)//开始找间接的 
		{
			if(matrix[start][i]==1)
			{
				if(find(i,end))
				break;
				else continue;
			} 
		}
		return false;//没找到	
	} 
	
}
*/
// Set edge (v1, v2) to"wt" 设置边(v1,v2)的权值为wt
void Graphm::setEdge(int v1, int v2, int wt) {
	try {
		if(wt<=0) {
			throw "Illegal weight value";
		}
		
		if(matrix[v1-1][v2-1] == 0)
			numEdge++;
		matrix[v1-1][v2-1] = wt;
		//matrix[v2][v1]=wt;
	} catch(const char* str) {
		cout<<str<<endl;
	}
}
void Graphm::clearMark()
{
	for(int i=0;i<numVertex;i++)
	mark[i]=0;
} 
void Graphm::DFS(int start,int curr)//深度优先遍历
{
	connect[curr][start]=connect[start][curr]=1;
 	mark[curr]=1;
	for(int i=0;i<numVertex;i++)
        if(mark[i] == 0 && matrix[curr][i] !=0)//没有被遍历过的点 
            DFS(start,i);
}
void Graphm::delEdge(int v1, int v2) { //Delete edge (v1, v2) 删除边(v1,v2)

	if(matrix[v1][v2] != 0) {

		numEdge--;

		matrix[v1][v2] = 0;
		matrix[v2][v1]=0;
	}
	else cout<<"该边不存在，删除失败！"<<endl;
}

bool Graphm::isEdge(int i, int j) // Is(i, j) an edge? 判断边(i,j)是图中的一条边吗？
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
void Graphm::printvexs(int n)//输出邻接矩阵 
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
void Graphm::printcon(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<connect[i][j]<<' ';
		}
		cout<<endl;
	}
 } 
bool Graphm::searchcon(int start)
{
	for(int i=0;i<numVertex;i++)
	{
		if(connect[start][i]==0)
		return false;
		else continue;
	}
	return true;
} 
