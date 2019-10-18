#include <iostream>
#include "Graph.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"------欢迎来到由邻接矩阵实现的图中------"<<endl;
	int n=0;
	cout<<"请输入要构造的图的顶点数: "<<endl;
	cin>>n;
	cout<<"请输入这"<<n<<"个顶点,顶点之间用空格隔开，例如构造一个5个顶点的图，则输入A B C D E"<<endl;
	char c[n];
	Graphm G;
	G.Init(n);
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		G.putVex(i,c[i]);
	}
	cout<<"请输入边数："<<endl;
	int num=0;
	cin>>num; 
	cout<<"接下来请输入"<<num<<"条边：譬如说A B有一条权值为20的边，则输入 A B 20，顶点与顶点和权值中间用空格隔开"<<endl;
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
	cout<<"接下来输出邻接矩阵： "<<endl;
	G.printvexs(n);
	cout<<"接下来进行图的遍历： "<<endl;
	cout<<"请输入起始顶点： "<<endl;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		if(a==c[i])
		{
			v1=i;
			break;	
		}
	}
	cout<<"接下来是深度遍历的结果： "<<endl;
	G.DFS(v1);
	cout<<endl; 
	cout<<"请输入想要删除的边：例如 A B "<<endl; 
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
	cout<<"删除边后的邻接矩阵为： "<<endl;
	G.printvexs(n);
	cout<<"接下来判断边(i,j)是否是图中的一条边"<<endl;
	cout<<"请输入想要判断的边，例如 A B"<<endl;
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
			cout<<a<<" "<<b<<"是图中的一条边！"<<endl; 
		}
	 	else cout<<a<<" "<<b<<"不是图中的一条边！"<<endl; 
	system("pause");
	return 0;
}
