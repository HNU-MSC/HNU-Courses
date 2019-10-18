#include "SOList.h"
#include <string>
	SOList::~SOList() {delete [] listArray;}//析构函数 
	
	void SOList::print()//打印汉字 
	{
		string str;
		cout<<"当前顺序表存储的汉字为："<<endl;
		for(int i=0;i<listSize;i+=2)
		{
			cout<<listArray[i]<<listArray[i+1];
			str[i]=listArray[i];
			str[i+1]=listArray[i+1];
		} 
		cout<<endl;
		//return str;
	}
	
	void SOList::append(char a,char b){//在顺序表末尾追加汉字 
		try{
			if(listSize >=maxSize)
			{
				throw "List capacity exceeded";
			}
			listArray[listSize++] = a;
			listArray[listSize++] = b;	
		}
		catch(const char* str)
		{
			cout<<str<<endl;
		}
	}
	
	int SOList::length() const{return listSize;}//返回顺序表长度 
	
	int SOList::find(char a,char b)
	{
		char temp1,temp2;
		int flag=0;
		for(int i=0;i<listSize;i++)
		{
			if(listArray[i]==a&&listArray[i+1]==b)//找到这个汉字
			{
				cout<<"查找成功！查找"<<"("<<listArray[i]<<listArray[i+1]<<")"<<"一共比较了"<<(i/2+1)<<"次"<<endl;
				flag=1; 
				//接下来开始替换
				if(i==0)//如果是表头第一个元素，则不替换
				{print();return i;}//返回查找次数 
				else{//否则，进行替换 
					temp1=listArray[i-2];
					temp2=listArray[i-1];
					listArray[i-2]=a;
					listArray[i-1]=b;
					listArray[i]=temp1;
					listArray[i+1]=temp2;
				} 
				print(); 
				return i;//返回查找次数 
			} 
		} 
		if(flag==0)//没找到
		{
			cout<<"查找失败！查找"<<"("<<a<<b<<")"<<"一共比较了"<<listSize/2<<"次"<<endl;
			print(); 
			return -1;//返回-1表示没找到 
		} 
	} 
	
	char SOList::getValue(int i) const{//返回值是当前元素 
		try{
			if(i<0||i>=listSize)
			{
				throw "No current element";
			}
			return listArray[i];
		}
		catch (const char* str)
		{
			cout<<str<<endl;
		}
	}
