#include "List.h"
#include <iostream>
using namespace std;
template <typename E>//������������Ա�ʵ�� 
class Alist: public List<E>{
	private:
		int maxSize;//˳������� 
		int listSize;//Ŀǰ�Ĵ�С 
		int curr;//��ǰԪ�ص�λ�� 
		E* listArray;//�б�Ԫ�ؽ�����ڸ�Ԫ���� 
		
	public:
	explicit Alist(int size=defaultSize){
			maxSize = size;
			listSize = curr = 0;
			listArray = new E[maxSize];
		}
		~Alist() {delete [] listArray;}//�������� 
	
	void clear(){//��ʼ��˳��� 
		delete [] listArray;//ɾ��ԭ������ 
		listSize = curr = 0;
		listArray = new E[maxSize];
	}
	void print()
	{
		cout<<"��ǰ˳���Ϊ��"<<endl;
		for(int i=0;i<listSize-1;i++)
		{
			cout<<listArray[i]<<',';
		} 
		cout<<listArray[listSize-1]<<endl;
	}
	void insert(const E&it){//�ڵ�ǰλ�ò���it 
		try{
			if (listSize >= maxSize)
			{
				throw "List capacity exceeded";
			} 
			for(int i=listSize; i>curr; i--)//���� 
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
	void append(const E& it){//��˳���ĩβ׷��it 
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
	
	E remove(){//ɾ�������ص�ǰԪ�� 
		try{
			if(curr < 0 || curr >= listSize)
			{
				throw "No element";
			}
			E it = listArray[curr];
			for(int i=curr; i<listSize-1; i++)//����Ԫ�� 
			{	listArray[i] = listArray[i+1];} 
			listSize--;
			return it;
		}
		catch(const char* str)
		{
			cout<<str<<endl;
		}
	}
	void moveToStart(){curr = 0;}//��curr��ǰλ����Ϊ��ͷ 
	void moveToEnd(){curr = listSize-1;}//��curr����Ϊĩβ 
	void prev(){if(curr != 0)curr--;}//��currǰ��һλ 
	void next(){if (curr <listSize)curr++;}//��curr����һλ 
	
	int length() const{return listSize;}//����˳����� 
	int currPos() const{return curr;}//���ص�ǰλ�� 
	
	void moveToPos(int pos){//����ǰλ����Ϊpos 
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
	
	const E& getValue() const{//����ֵ�ǵ�ǰԪ�� 
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

