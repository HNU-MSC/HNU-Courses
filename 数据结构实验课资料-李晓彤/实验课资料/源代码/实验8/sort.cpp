#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<algorithm>
using namespace std;

int A[1000000];
int temp[1000000];
fstream File;
LARGE_INTEGER nf;
LARGE_INTEGER bt;
LARGE_INTEGER et;
//�Ƚ�Ԥ�� 
class Comp
{
	public:
		static bool prior(int a,int b)
		{
			return a<b;
		}
};
//ѡ������
template <typename E,typename Comp>
void selsort(E A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int lowindex = i;
		for(int j=n-1;j>i;j--)
		{
			if(Comp::prior(A[j],A[lowindex]))
			lowindex = j;
		}
		swap(A[i],A[lowindex]);
	}
} 
//�鲢����
template<typename E,typename Comp>
void mergesort(E A[],E temp[],int left,int right)
{
	if(left == right)return;
	int mid = (left+right)/2;
	mergesort<E,Comp>(A,temp,left,mid);
	mergesort<E,Comp>(A,temp,mid+1,right);
	for(int i=left;i<=right;i++)
	{temp[i]=A[i];}
	int i1 = left;
	int i2 = mid+1;
	for(int curr=left;curr<=right;curr++)
	{
		if(i1 == mid+1)
		A[curr]=temp[i2++];
		else if(i2>right)
		A[curr]=temp[i1++];
		else if(Comp::prior(temp[i1],temp[i2]))
		A[curr]=temp[i1++];
		else A[curr]=temp[i2++];
	}
} 

int main()
{
	cout<<"��������չʾ���ֲ�ͬ������ʽ�����100��1K��10K��100K��1M"<< 
	"�������������������ʱ�䣺" <<endl;
	QueryPerformanceFrequency(&nf); //��ȷ��¼ʱ�� 
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"���ݹ�ģΪ100ʱ����ʱ�䣺"<<endl;
	//100
	
	//ѡ������ 
	File.open("100.txt",ios::in);//open the file
	int i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);//��ʼʱ�� 
	selsort<int,Comp>(A,100);
	QueryPerformanceCounter(&et);//����ʱ�� 
	cout<<"ѡ������"<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100_selsort_result.txt",ios::out); 
	for(i=0;i<100;i++) File<<A[i]<<"\t";//��������� 
	File.close();
	
	//�鲢���� 
	File.open("100.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	mergesort<int,Comp>(A,temp,0,99);
	QueryPerformanceCounter(&et);
	cout<<"�鲢����" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100_mergesort_result.txt",ios::out);
	for(i=0;i<100;i++) File<<A[i]<<"\t";
	File.close();
	
	cout<<"------------------------------------"<<endl;
	cout<<"���ݹ�ģΪ1Kʱ����ʱ�䣺"<<endl;
	
	//1K
	File.open("1K.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	selsort<int,Comp>(A,1000);
	QueryPerformanceCounter(&et);
	cout<<"ѡ������: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1K_selsort_result.txt",ios::out); 
	for(i=0;i<1000;i++) File<<A[i]<<"\t";
	File.close();
	
	//�鲢���� 
	File.open("1K.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	mergesort<int,Comp>(A,temp,0,999);
	QueryPerformanceCounter(&et);
	cout<<"�鲢����" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1K_mergesort_result.txt",ios::out);
	for(i=0;i<1000;i++) File<<A[i]<<"\t";
	File.close();
	
	cout<<"------------------------------------"<<endl;
	cout<<"���ݹ�ģΪ10Kʱ����ʱ�䣺"<<endl;
	//10K
	File.open("10K.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	selsort<int,Comp>(A,10000);
	QueryPerformanceCounter(&et);
	cout<<"ѡ������: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("10K_selsort_result.txt",ios::out); 
	for(i=0;i<10000;i++) File<<A[i]<<"\t";
	File.close();
	
	//�鲢���� 
	File.open("10K.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	mergesort<int,Comp>(A,temp,0,9999);
	QueryPerformanceCounter(&et);
	cout<<"�鲢����" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("10K_mergesort_result.txt",ios::out);
	for(i=0;i<10000;i++) File<<A[i]<<"\t";
	File.close();
	
	cout<<"------------------------------------"<<endl;
	//100K
	cout<<"���ݹ�ģΪ100Kʱ����ʱ�䣺"<<endl;
	File.open("100K.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	selsort<int,Comp>(A,100000);
	QueryPerformanceCounter(&et);
	cout<<"ѡ������: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100K_selsort_result.txt",ios::out); 
	for(i=0;i<100000;i++) File<<A[i]<<"\t";
	File.close();
	
	//�鲢���� 
	File.open("100K.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	mergesort<int,Comp>(A,temp,0,99999);
	QueryPerformanceCounter(&et);
	cout<<"�鲢����" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100K_mergesort_result.txt",ios::out);
	for(i=0;i<100000;i++) File<<A[i]<<"\t";
	File.close(); 
	
	cout<<"------------------------------------"<<endl;
	//1M
	cout<<"���ݹ�ģΪ1Mʱ����ʱ�䣺"<<endl;
	File.open("1M.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	selsort<int,Comp>(A,1000000);
	QueryPerformanceCounter(&et);
	cout<<"ѡ������: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1M_selsort_result.txt",ios::out); 
	for(i=0;i<1000000;i++) File<<A[i]<<"\t";
	File.close();
	
	//�鲢���� 
	File.open("1M.txt",ios::in);//open the file
	i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);
	mergesort<int,Comp>(A,temp,0,999999);
	QueryPerformanceCounter(&et);
	cout<<"�鲢����" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1M_mergesort_result.txt",ios::out);
	for(i=0;i<1000000;i++) File<<A[i]<<"\t";
	File.close(); 
	//cout<<"end"<<endl;
	cout<<"end---------------------------------end-----------------------------------------end"<<endl;
	system("pause"); 
	return 0;
 } 
