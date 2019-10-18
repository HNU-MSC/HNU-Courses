#include <iostream>
using namespace std;

int main()
{
	int n=0;
	const int N = 1000;
	int stu[N];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		stu[i]=i+1;
	}
	int m=0,p=0,q=0,student=0,local=0,ylocal=0;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>p>>q;
		for(int i=0;i<n;i++)
		{
			if(stu[i]==p)
			{
				local=i+1;
				break;
			}
		}
		ylocal=local;
		if(q>0)
		{
			student=p;
			for(int j=1;j<=q;j++)
			{
				stu[local-1]=stu[local];
				local++;
			}
			stu[ylocal+q-1]=student;
		}
		else
		{
			student=p;
			for(int j=-1;j>=q;j--)
			{
				stu[local-1]=stu[local-2];
				local--;
			}
			stu[ylocal+q-1]=student;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<stu[i]<<' ';
	}
	return 0;
}
