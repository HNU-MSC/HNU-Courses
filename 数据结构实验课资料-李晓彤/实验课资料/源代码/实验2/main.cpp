//����ʵ�ֵ�������
#include "LList.cpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct DXS{
	int xs;//ϵ�� 
	int cshu;//���� 
};

int main() {
	void test();
	cout<<"======��ӭ������������ʵ�ֵļ���һԪ����ʽ��Ŀ======\n";
	test();
}
bool bj (DXS d1,DXS d2)  
{
	return d1.cshu>d2.cshu;
}
void test() 
{
	int a=0;
	LList list1;
	LList list2;
	LList list3;
	cout<<"������Ҫ��ӵĶ���ʽs1��"; 
	cout<<"�����һ������0��������ʾϵ����\n";
	cout<<"�ڶ�������0��������ʾ��������Ϊ���������������Ϊ0��������ϵ��Ϊ0ʱ��������������3 5 4 1 -2 4 5 0 0"<<endl;
	DXS d[100];
	int i;
	for(i=0;;i++)
	{
		cin>>d[i].xs;
		if(d[i].xs==0)
		{
			break;
		}
		else
		{
			cin>>d[i].cshu;
		}
	}
	sort(d,d+i,bj);
	for(int j=0;j<i;j++)
	{
		//cout<<d[j].xs<<' '<<d[j].cshu<<endl;
		list1.append(d[j].xs,d[j].cshu);
	}
	list1.print();
	
	cout<<"������Ҫ��ӵĶ���ʽs2��"; 
	cout<<"�����һ������0��������ʾϵ����\n";
	cout<<"�ڶ�������0��������ʾ��������Ϊ���������������Ϊ0��������ϵ��Ϊ0ʱ��������������3 5 4 1 -2 4 5 0 0"<<endl;
	DXS c[100];
	int k;
	for(k=0;;k++)
	{
		cin>>c[k].xs;
		if(c[k].xs==0)
		{
			break;
		}
		else
		{
			cin>>c[k].cshu;
		}
	}
	sort(c,c+k,bj);
	for(int j=0;j<k;j++)
	{
		//cout<<d[j].xs<<' '<<d[j].cshu<<endl;
		list2.append(c[j].xs,c[j].cshu);
	}
	list2.print();
	//��������ʼ����ʽ�ӷ�
	int xishu=0,cishu=0,l1=1,l2=1;
	while(list1.havenext()||list2.havenext())
	{
		if(list1.getcsValue()==list2.getcsValue())
		{
			xishu = list1.geteleValue()+list2.geteleValue();
			if(xishu!=0)
			{
				list3.append(xishu,list1.getcsValue());	
			}
			list1.next();
			l1++;
			list2.next();
			l2++;
			xishu=0;
		}
		else if(list2.getcsValue()>list1.getcsValue())
		{
			if(list2.havecnt()<l2)
			{
				list3.append(list1.geteleValue(),list1.getcsValue());
				list1.next();
			}
			else {
				list3.append(list2.geteleValue(),list2.getcsValue());
				list2.next();
				l2++;
			}
		}
		else
		{
			if(list1.havecnt()<l1)
			{
				list3.append(list2.geteleValue(),list2.getcsValue());
				list2.next();
			}
			else
			{
				list3.append(list1.geteleValue(),list1.getcsValue());
				list1.next();
				l1++;
			}
			
		}
	} 
	cout<<"�����Ķ���ʽΪ��"<<endl;
	list3.print();
	system("pause");
}

