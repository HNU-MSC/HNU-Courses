#include "Graphl.h"
using namespace std;
Graphl::Graphl(int numVert) {
	Init(numVert);
}

//����
void Graphl::Init(int n) {
	numVertex = n;
	numEdge = 0;
	mark = new int [n];
	for (int i=0; i<numVertex; i++)
		mark[i] = 0;//δ������
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
	cout << "ɾ��ͼ��ɣ�" << endl;
}

//������
int Graphl::n() {
	return numVertex;
}

//����
int Graphl::e() {
	return numEdge;
}

//�õ���Ӧ�Ķ�����
int Graphl::Graphl::locateVex(char u) {
	for (int i=0; i<numVertex; i++)
		if (u == gl[i].ver.data)
			return i;
	return -1;
}

//�õ�����
Vertex Graphl::getVex(int v) {
	return gl[v].ver;
}

//���ö���
void Graphl::putVex(int v,char value) {
	gl[v].ver.data = value;
}


int Graphl::first(int v) {
	if (gl[v].head->next == NULL)//û���ھ�
		return numVertex;//���ض�����
	gl[v].curr = gl[v].head->next;
	return gl[v].curr->vertex();
}


int Graphl::next(int v,int w) {
	if (w>=numVertex-1)//��ͷ��
		return numVertex;
	for (int i=w+1; i<numVertex; i++) {
		if (isEdge(v,i)) {//�ߴ���
			while(gl[v].curr->vertex() != i) {//�ƶ���Ҫ�����λ��
				gl[v].curr = gl[v].curr->next;
			}
			return gl[v].curr->vertex();
		}
	}
	return n();//û�ھ�
}

void Graphl::setEdge(int v1,int v2,int wgt) {
	int i = v1,j = v2;
	if (wgt<=0) {
		cout << "����Ȩֵ���󣬽�����ʧ�ܣ�";
		return;
	}
	//����������������
	Edge *newEdge = new Edge(v2,wgt);
	Edge *TwoEdge = new Edge(v1,wgt);
	if (isEdge(i,j)) {//���֮ǰ���������ߣ�����������Ȩֵ
		gl[v1].curr->setwt(wgt);
		gl[v2].curr->setwt(wgt);
	} else {//֮ǰ������������
		numEdge++;//����++
		if (gl[i].head->next == NULL) {//֮ǰû���ھ�
			gl[i].head->next = newEdge;
			if (gl[j].head->next == NULL) {//���֮ǰJҲû���ھ�
				gl[j].head->next = TwoEdge;
				return;
			}
			gl[j].curr = gl[j].head->next;//����Ŀǰָ������ƶ�
			while(true) {
				if (i<gl[j].curr->vertex()) {//���С
					Edge* tmp=gl[j].head;
					while(tmp->next != gl[j].curr) {
						tmp = tmp->next;
					}
					TwoEdge->next = gl[j].curr;
					tmp->next = TwoEdge;
					return;
				} else if (gl[j].curr->next == NULL) {//��Ŵ���ʼ����
					gl[j].curr->next = TwoEdge;
					return;
				}
				gl[j].curr = gl[j].curr->next;
			}

		} else {//֮ǰ���ھ�
			gl[i].curr = gl[i].head->next;//i��ָ�������ƶ�
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

//ɾ���� 
void Graphl::delEdge(int v1,int v2) {
	//�����߶�ɾ�� 
	if (isEdge(v1,v2)) {//�ߴ��� 
		numEdge--;
		//��ɾ��V1 
		Edge* tmp = gl[v1].head;
		gl[v1].curr = gl[v1].head->next;
		while (gl[v1].curr->vertex() != v2) {
			gl[v1].curr = gl[v1].curr->next;
			tmp = tmp->next;
		}
		tmp->next = gl[v1].curr->next;
	 	
		 //������ɾ��V2 
		tmp = gl[v2].head;
		gl[v2].curr = gl[v2].head->next;
		while (gl[v2].curr->vertex() != v1) {
			gl[v2].curr = gl[v2].curr->next;
			tmp = tmp->next;
		}
		tmp->next = gl[v2].curr->next;
	}
	else cout<<"�߲����ڣ�ɾ��ʧ�ܣ�"<<endl; 
}

//�ж��Ƿ��Ǳ� 
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

//���ͼ
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
	setMark(v,1);//��������
	int p = first(v);
	for(int p= first(v);p<n();p++) {
		if (getMark(p) == 0)
			DFS(p);
	}
}

