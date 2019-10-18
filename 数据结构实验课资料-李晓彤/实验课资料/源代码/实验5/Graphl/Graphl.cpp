#include "Graphl.h"
using namespace std;
Graphl::Graphl(int numVert) {
	Init(numVert);
}

//建造
void Graphl::Init(int n) {
	numVertex = n;
	numEdge = 0;
	mark = new int [n];
	for (int i=0; i<numVertex; i++)
		mark[i] = 0;//未被访问
	char c;
	for (int i=0; i<n; i++) {
		cin >> c;
		gl[i].ver.data = c;
	}
	for (int i=0; i<n; i++) {
		gl[i].head = new Edge(-1,-1);
		gl[i].head->next =NULL;
		gl[i].curr = NULL;
	}
}

Graphl::~Graphl() {
	delete[] mark;
	cout << "删除图完成！" << endl;
}

//顶点数
int Graphl::n() {
	return numVertex;
}

//边数
int Graphl::e() {
	return numEdge;
}

//得到对应的顶点编号
int Graphl::Graphl::locateVex(char u) {
	for (int i=0; i<numVertex; i++)
		if (u == gl[i].ver.data)
			return i;
	return -1;
}

//得到顶点
Vertex Graphl::getVex(int v) {
	return gl[v].ver;
}

//设置顶点
void Graphl::putVex(int v,char value) {
	gl[v].ver.data = value;
}


int Graphl::first(int v) {
	if (gl[v].head->next == NULL)//没有邻居
		return numVertex;//返回顶点数
	gl[v].curr = gl[v].head->next;
	return gl[v].curr->vertex();
}


int Graphl::next(int v,int w) {
	if (w>=numVertex-1)//到头了
		return numVertex;
	for (int i=w+1; i<numVertex; i++) {
		if (isEdge(v,i)) {//边存在
			while(gl[v].curr->vertex() != i) {//移动到要插入的位置
				gl[v].curr = gl[v].curr->next;
			}
			return gl[v].curr->vertex();
		}
	}
	return n();//没邻居
}

void Graphl::setEdge(int v1,int v2,int wgt) {
	int i = v1,j = v2;
	if (wgt<=0) {
		cout << "输入权值错误，建立边失败！";
		return;
	}
	//接下来建立两条边
	Edge *newEdge = new Edge(v2,wgt);
	Edge *TwoEdge = new Edge(v1,wgt);
	if (isEdge(i,j)) {//如果之前存在这条边，则重新设置权值
		gl[v1].curr->setwt(wgt);
		gl[v2].curr->setwt(wgt);
	} else {//之前不存在这条边
		numEdge++;//边数++
		if (gl[i].head->next == NULL) {//之前没有邻居
			gl[i].head->next = newEdge;
			if (gl[j].head->next == NULL) {//如果之前J也没有邻居
				gl[j].head->next = TwoEdge;
				return;
			}
			gl[j].curr = gl[j].head->next;//否则目前指针向后移动
			while(true) {
				if (i<gl[j].curr->vertex()) {//编号小
					Edge* tmp=gl[j].head;
					while(tmp->next != gl[j].curr) {
						tmp = tmp->next;
					}
					TwoEdge->next = gl[j].curr;
					tmp->next = TwoEdge;
					return;
				} else if (gl[j].curr->next == NULL) {//编号大则开始建立
					gl[j].curr->next = TwoEdge;
					return;
				}
				gl[j].curr = gl[j].curr->next;
			}

		} else {//之前有邻居
			gl[i].curr = gl[i].head->next;//i的指针往后移动
			while (true) {
				if (j<gl[i].curr->vertex()) {
					Edge* tmp=gl[i].head;
					while(tmp->next != gl[i].curr) {
						tmp = tmp->next;
					}
					newEdge->next = gl[i].curr;
					tmp->next = newEdge;
					break;
				} else if (gl[i].curr->next == NULL) {
					gl[i].curr->next = newEdge;
					break;
				}
				gl[i].curr = gl[i].curr->next;
			}
			gl[j].curr = gl[j].head->next;
			if (gl[j].curr == NULL) {
				gl[j].head->next = TwoEdge;
				return;
			}
			while(true) {
				if (i<gl[j].curr->vertex()) {
					Edge* tmp=gl[j].head;
					while(tmp->next != gl[j].curr) {
						tmp = tmp->next;
					}
					TwoEdge->next = gl[j].curr;
					tmp->next = TwoEdge;
					return;
				} else if (gl[j].curr->next == NULL) {
					gl[j].curr->next = TwoEdge;
					return;
				}
				gl[j].curr = gl[j].curr->next;
			}
		}
	}
}

//删除边 
void Graphl::delEdge(int v1,int v2) {
	//两条边都删了 
	if (isEdge(v1,v2)) {//边存在 
		numEdge--;
		//先删除V1 
		Edge* tmp = gl[v1].head;
		gl[v1].curr = gl[v1].head->next;
		while (gl[v1].curr->vertex() != v2) {
			gl[v1].curr = gl[v1].curr->next;
			tmp = tmp->next;
		}
		tmp->next = gl[v1].curr->next;
	 	
		 //接下来删除V2 
		tmp = gl[v2].head;
		gl[v2].curr = gl[v2].head->next;
		while (gl[v2].curr->vertex() != v1) {
			gl[v2].curr = gl[v2].curr->next;
			tmp = tmp->next;
		}
		tmp->next = gl[v2].curr->next;
	}
	else cout<<"边不存在，删除失败！"<<endl; 
}

//判断是否是边 
bool Graphl::isEdge(int i,int j) {
	gl[i].curr = gl[i].head->next;
	while(gl[i].curr != NULL) {
		if (gl[i].curr->vertex() == j)
			return true;
		gl[i].curr = gl[i].curr->next;
	}
	return false;
}

int Graphl::weight(int v1,int v2) {
	if (isEdge(v1,v2))
		return gl[v1].curr->weight();
	return 0;
}

int Graphl::getMark(int v) {
	return mark[v];
}

void Graphl::setMark(int v, int val) {
	mark[v] = val;
}

//输出图
void Graphl::show() {
	for (int i=0; i<numVertex; i++) {
		cout << gl[i].ver.data;
		gl[i].curr = gl[i].head->next;
		while(gl[i].curr != NULL) {
			cout << "->" << gl[gl[i].curr->vertex()].ver.data << '(' << gl[i].curr->weight() << ')';
			gl[i].curr = gl[i].curr->next;
		}
		if (gl[i].curr == NULL) {
			cout << endl;
			continue;
		}
	}
}


void Graphl::DFS(int v) {
	cout << gl[v].ver.data << ' ';
	setMark(v,1);//被访问了
	int p = first(v);
	for(int p= first(v);p<n();p++) {
		if (getMark(p) == 0)
			DFS(p);
	}
}

