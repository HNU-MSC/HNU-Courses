#ifndef SOList_H
#define SOList_H
#include <iostream>
#include <string>
using namespace std; 
static int defaultSize=1000;

class SOList//SOList ADT 抽象数据类型定义 
{
	private:
		int maxSize;//顺序表容量 
		int listSize;//目前的大小 
		int curr;//当前元素的位置
		char* listArray;//列表元素将存放在该元素中 
	void operator =(const SOList&) {}
	public:
	SOList(int size=defaultSize){
	maxSize = size;listSize = curr = 0;listArray = new char[maxSize];}
	~SOList() ;//析构函数 

	void print();//打印线性表 

	void append(char,char);//末尾插入线性表值 
	
	int find(char a,char b);//查找+转换 
	int length() const;//返回顺序表长度 
	char getValue(int) const;//返回值是当前元素 	
};

#endif
