#include <iostream>
#include "Graph.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"------欢迎来到由邻接矩阵实现的通信网络------"<<endl;
	int n=0;
	cout<<"请输入部门数量N: "<<endl;
	cin>>n;
	cout<<"请输入单向通路的数量M："<<endl;
	int num=0;
	cin>>num; 
	//cout<<"请输入这"<<n<<"个顶点,顶点之间用空格隔开，例如构造一个5个顶点的图，则输入A B C D E"<<endl;
	Graphm G;
	G.Init(n);
	for(int i=0;i<n;i++)
	{
		G.putVex(i,i+1);
	}
	cout<<"接下来请输入"<<num<<"条单向通路：譬如说1 2有一条，则输入 1 2 ，顶点与顶点中间用空格隔开"<<endl;
	int a,b;
	int weight=1;
	while(num!=0)
	{
		cin>>a>>b;
		G.setEdge(a,b,weight);
		num=num-1;
	} 
	cout<<"接下来输出邻接矩阵： "<<endl;
	G.printvexs(n);
	cout<<"接下来判断有多少个部门知道所有N个部门的存在： "<<endl;
	//cout<<"请输入起始顶点： "<<endl;
	//cin>>a;
	int know=0;
	for(int i=0;i<n;i++)
	{
		G.DFS(i,i);
		G.clearMark(); 
	}
	cout<<"下图是每个点能知道的部门，为1是知道，0是不知道："<<endl;
	G.printcon(n);
	for(int i=0;i<n;i++)
	{
		if(G.searchcon(i)==true)
		know++;
	}
	cout<<"那么可以会有"<<know<<"个部门知道所有N个部门的存在！"<<endl; 
	system("pause");
	return 0;
}
