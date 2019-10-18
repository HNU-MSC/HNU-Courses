#include "List.h"
#include <iostream>
using namespace std;
template <typename E>//基于数组的线性表实现 
class Alist: public List<E>{
	private:
		int maxSize;//顺序表容量 
		int listSize;//目前的大小 
		int curr;//当前元素的位置 
		E* listArray;//列表元素将存放在该元素中 
		
	public:
	explicit Alist(int size=defaultSize){
			maxSize = size;
			listSize = curr = 0;
			listArray = new E[maxSize];
		}
		~Alist() {delete [] listArray;}//析构函数 
	
	void clear(){//初始化顺序表 
		delete [] listArray;//删除原有数组 
		listSize = curr = 0;
		listArray = new E[maxSize];
	}
	void print()
	{
		cout<<"当前顺序表为："<<endl;
		for(int i=0;i<listSize-1;i++)
		{
			cout<<listArray[i]<<',';
		} 
		cout<<listArray[listSize-1]<<endl;
	}
	void insert(const E&it){//在当前位置插入it 
		try{
			if (listSize >= maxSize)
			{
				throw "List capacity exceeded";
			} 
			for(int i=listSize; i>curr; i--)//右移 
			{
				listArray[i] = listArray[i-1];
			}
			listArray[curr] = it;
			listSize++;
		}
		catch(const char* str)
		{
			cout<<str<<endl;
		}
	}
	void append(const E& it){//在顺序表末尾追加it 
		//Assert(listSize < maxSize);
		try{
			if(listSize >=maxSize)
			{
				throw "List capacity exceeded";
			}
			listArray[listSize++] = it;	
		}
		catch(const char* str)
		{
			cout<<str<<endl;
		}
	}
	
	E remove(){//删除并返回当前元素 
		try{
			if(curr < 0 || curr >= listSize)
			{
				throw "No element";
			}
			E it = listArray[curr];
			for(int i=curr; i<listSize-1; i++)//左移元素 
			{	listArray[i] = listArray[i+1];} 
			listSize--;
			return it;
		}
		catch(const char* str)
		{
			cout<<str<<endl;
		}
	}
	void moveToStart(){curr = 0;}//将curr当前位置设为开头 
	void moveToEnd(){curr = listSize-1;}//将curr设置为末尾 
	void prev(){if(curr != 0)curr--;}//将curr前移一位 
	void next(){if (curr <listSize)curr++;}//将curr后移一位 
	
	int length() const{return listSize;}//返回顺序表长度 
	int currPos() const{return curr;}//返回当前位置 
	
	void moveToPos(int pos){//将当前位置设为pos 
		//Assert ((pos>=0)&&(pos<=listSize));
		try{
			if(pos<0||pos>listSize)
			{
				throw "Pos out of range";
			}
			curr = pos;
		}
		catch(const char* str)
		{
			cout<<str<<endl;
		}
	}
	
	const E& getValue() const{//返回值是当前元素 
		//Assert((curr>=0)&&(curr<listSize));
		try{
			if(curr<0||curr>=listSize)
			{
				throw "No current element";
			}
			return listArray[curr];
		}
		catch (const char* str)
		{
			cout<<str<<endl;
		}
	}
};

