#include <iostream>
#include "Graphl.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv){
	cout<<"---欢迎来到邻接表实现的图中---"<<endl;
	cout << "请输入图的顶点数" << endl;
	int n=0;
	cin >> n;
	
	cout << "请输入"<<n<<"个顶点，例如5个顶点则输入 A B C D E，中间用逗号隔开！" << endl;
	
	Graphl G(n);
	
	cout<<"图构建完成！"<<endl;
	int Bnum=0;
	cout<<"请输入边数： "<<endl;
	cin>>Bnum;
	
	char v1,v2;
	int w,p;
	cout << "请输入"<<Bnum<<"条边" << endl;
	cout<<"例如A B 有一条权值为10的边，则输入 A B 10"<<endl;
	for(int i=0;i<Bnum;i++)
	{
		cin>>v1>>v2>>w;
		G.setEdge(G.locateVex(v1),G.locateVex(v2),w);
	}
	
	cout << "下表为图的邻接表，括号内为该边的权值" << endl;
	G.show();
    
    cout << "该图共有" << G.n() << "个顶点" << endl;
	cout << "该图共有" << G.e() << "条边" << endl; 
	
	cout<<"接下来是判断边是否存在："<<endl;
	cout<<"请输入想判断的边，例如 输入 A B"<<endl; 
	cin>>v1>>v2;
	if(G.isEdge(G.locateVex(v1),G.locateVex(v2)))
	cout<<"边存在！"<<endl;
	else cout<<"该边不存在！"<<endl;
	
	cout<<"接下来进行深度遍历："<<endl; 
	cout << "输入起始顶点名称进行遍历" << endl;
	cin>>v1;
	cout<<"接下来是深度遍历的结果！"<<endl;
	G.DFS(G.locateVex(v1));
	
	cout << "接下来是删除边操作，请输入想删除的边，例如想删除 A B边，则输入 A B" << endl;
	cin>>v1>>v2; 
	G.delEdge(G.locateVex(v1),G.locateVex(v2));
	
	cout << "下表为删除过边的图的邻接表，括号内为该边的权值" << endl;
	G.show();
	
	cout << "该图共有" << G.n() << "个顶点" << endl;
	cout << "该图共有" << G.e() << "条边" << endl; 
	system("pause");
	return 0;
}
