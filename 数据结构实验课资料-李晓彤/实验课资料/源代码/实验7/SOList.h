#ifndef SOList_H
#define SOList_H
#include <iostream>
#include <string>
using namespace std; 
static int defaultSize=1000;

class SOList//SOList ADT �����������Ͷ��� 
{
	private:
		int maxSize;//˳������� 
		int listSize;//Ŀǰ�Ĵ�С 
		int curr;//��ǰԪ�ص�λ��
		char* listArray;//�б�Ԫ�ؽ�����ڸ�Ԫ���� 
	void operator =(const SOList&) {}
	public:
	SOList(int size=defaultSize){
	maxSize = size;listSize = curr = 0;listArray = new char[maxSize];}
	~SOList() ;//�������� 

	void print();//��ӡ���Ա� 

	void append(char,char);//ĩβ�������Ա�ֵ 
	
	int find(char a,char b);//����+ת�� 
	int length() const;//����˳����� 
	char getValue(int) const;//����ֵ�ǵ�ǰԪ�� 	
};

#endif
