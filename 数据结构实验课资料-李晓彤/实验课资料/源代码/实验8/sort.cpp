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
//比较预置 
class Comp
{
	public:
		static bool prior(int a,int b)
		{
			return a<b;
		}
};
//选择排序
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
//归并排序
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
	cout<<"接下来将展示两种不同的排序方式在面对100，1K，10K，100K和1M"<< 
	"的数据排序过程所花费时间：" <<endl;
	QueryPerformanceFrequency(&nf); //精确记录时间 
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	cout<<"数据规模为100时花费时间："<<endl;
	//100
	
	//选择排序 
	File.open("100.txt",ios::in);//open the file
	int i=0;
	while(!File.eof())// write the file
	{
		File>>A[i];
		i++;
	}
	File.close();
	QueryPerformanceCounter(&bt);//开始时间 
	selsort<int,Comp>(A,100);
	QueryPerformanceCounter(&et);//结束时间 
	cout<<"选择排序："<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100_selsort_result.txt",ios::out); 
	for(i=0;i<100;i++) File<<A[i]<<"\t";//输出排序结果 
	File.close();
	
	//归并排序 
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
	cout<<"归并排序：" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100_mergesort_result.txt",ios::out);
	for(i=0;i<100;i++) File<<A[i]<<"\t";
	File.close();
	
	cout<<"------------------------------------"<<endl;
	cout<<"数据规模为1K时花费时间："<<endl;
	
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
	cout<<"选择排序: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1K_selsort_result.txt",ios::out); 
	for(i=0;i<1000;i++) File<<A[i]<<"\t";
	File.close();
	
	//归并排序 
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
	cout<<"归并排序：" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1K_mergesort_result.txt",ios::out);
	for(i=0;i<1000;i++) File<<A[i]<<"\t";
	File.close();
	
	cout<<"------------------------------------"<<endl;
	cout<<"数据规模为10K时花费时间："<<endl;
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
	cout<<"选择排序: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("10K_selsort_result.txt",ios::out); 
	for(i=0;i<10000;i++) File<<A[i]<<"\t";
	File.close();
	
	//归并排序 
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
	cout<<"归并排序：" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("10K_mergesort_result.txt",ios::out);
	for(i=0;i<10000;i++) File<<A[i]<<"\t";
	File.close();
	
	cout<<"------------------------------------"<<endl;
	//100K
	cout<<"数据规模为100K时花费时间："<<endl;
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
	cout<<"选择排序: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100K_selsort_result.txt",ios::out); 
	for(i=0;i<100000;i++) File<<A[i]<<"\t";
	File.close();
	
	//归并排序 
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
	cout<<"归并排序：" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("100K_mergesort_result.txt",ios::out);
	for(i=0;i<100000;i++) File<<A[i]<<"\t";
	File.close(); 
	
	cout<<"------------------------------------"<<endl;
	//1M
	cout<<"数据规模为1M时花费时间："<<endl;
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
	cout<<"选择排序: "<<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1M_selsort_result.txt",ios::out); 
	for(i=0;i<1000000;i++) File<<A[i]<<"\t";
	File.close();
	
	//归并排序 
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
	cout<<"归并排序：" <<1000.0*(et.QuadPart-bt.QuadPart)/nf.QuadPart<<"ms"<<endl;
	File.open("1M_mergesort_result.txt",ios::out);
	for(i=0;i<1000000;i++) File<<A[i]<<"\t";
	File.close(); 
	//cout<<"end"<<endl;
	cout<<"end---------------------------------end-----------------------------------------end"<<endl;
	system("pause"); 
	return 0;
 } 
