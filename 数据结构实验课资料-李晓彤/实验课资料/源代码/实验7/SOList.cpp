#include "SOList.h"
#include <string>
	SOList::~SOList() {delete [] listArray;}//�������� 
	
	void SOList::print()//��ӡ���� 
	{
		string str;
		cout<<"��ǰ˳���洢�ĺ���Ϊ��"<<endl;
		for(int i=0;i<listSize;i+=2)
		{
			cout<<listArray[i]<<listArray[i+1];
			str[i]=listArray[i];
			str[i+1]=listArray[i+1];
		} 
		cout<<endl;
		//return str;
	}
	
	void SOList::append(char a,char b){//��˳���ĩβ׷�Ӻ��� 
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
	
	int SOList::length() const{return listSize;}//����˳����� 
	
	int SOList::find(char a,char b)
	{
		char temp1,temp2;
		int flag=0;
		for(int i=0;i<listSize;i++)
		{
			if(listArray[i]==a&&listArray[i+1]==b)//�ҵ��������
			{
				cout<<"���ҳɹ�������"<<"("<<listArray[i]<<listArray[i+1]<<")"<<"һ���Ƚ���"<<(i/2+1)<<"��"<<endl;
				flag=1; 
				//��������ʼ�滻
				if(i==0)//����Ǳ�ͷ��һ��Ԫ�أ����滻
				{print();return i;}//���ز��Ҵ��� 
				else{//���򣬽����滻 
					temp1=listArray[i-2];
					temp2=listArray[i-1];
					listArray[i-2]=a;
					listArray[i-1]=b;
					listArray[i]=temp1;
					listArray[i+1]=temp2;
				} 
				print(); 
				return i;//���ز��Ҵ��� 
			} 
		} 
		if(flag==0)//û�ҵ�
		{
			cout<<"����ʧ�ܣ�����"<<"("<<a<<b<<")"<<"һ���Ƚ���"<<listSize/2<<"��"<<endl;
			print(); 
			return -1;//����-1��ʾû�ҵ� 
		} 
	} 
	
	char SOList::getValue(int i) const{//����ֵ�ǵ�ǰԪ�� 
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
