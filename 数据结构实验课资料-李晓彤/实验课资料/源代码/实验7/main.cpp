#include <iostream>
#include "SOList.h"
#include <string>
#include <fstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	const char* FileIn[5] = {//���Ա��ĵ� 
		"text1.txt",
		"text2.txt",
		"text3.txt",
		"text4.txt",
		"text5.txt"
	};
	const char* Fileresult[5] = {//����ĵ� 
		"result1.txt",
		"result2.txt",
		"result3.txt",
		"result4.txt",
		"result5.txt"
	};
	
	cout<<"---��ӭ��������֯���Ա���ļ����ݲ���---"<<endl;
	cout<<"������Ҫ�򿪵��ļ�������ֻ��5�����������text1������1�������result1����ʾ"<<endl;
	int name;
	cin>>name;
	ifstream infile,in;
	ofstream outfile;
	
	in.open(FileIn[name-1],ios::in);
	outfile.open(Fileresult[name-1],ios::out);//������ҽ�����ļ�
	string  temp,temp2;
	
	in>>temp2;//��ȡ�����ļ���ԭ�����Ա�ĳ��� 
	in.close();//�ر��ļ����� 
	infile.open(FileIn[name-1],ios::in);//�������ݵ��ļ�
	//in.open(Find[name-1],ios::in); 
	int n=0;
	n=temp2.length();
	SOList list(n);
	int flag=0;//����غ�
	while(!infile.eof()) {//���ļ�ĩβ��ֹͣ 
		infile>>temp;//���ļ���һ���ַ��������temp��,�����ո���߻��н��� 
		for (int i = 0; i < temp.length(); i =i+2) {
			if (flag==0) {//����غ� 
				list.append(temp[i], temp[i + 1]);
			} else {//���һغ� 
				int resul = list.find(temp[i],temp[i+1]);
				if (resul != -1) {//���ҵ��� 
					outfile<<"���ҳɹ�!���Ҵ���Ϊ:"<<resul/2+1;
					outfile<<endl;
					outfile<<"��ǰ����֯���Ա�Ϊ��";
					for(int i=0;i<n;i+=2)
					{
						outfile<<list.getValue(i)<<list.getValue(i+1);	
					}
					outfile<<endl;
				} else {
					outfile<<"����ʧ��!���Ҵ���Ϊ:"<<n/2;
					outfile<<endl;
					outfile<<"��ǰ����֯���Ա�Ϊ��";
					for(int i=0;i<n;i+=2)
					{
						outfile<<list.getValue(i)<<list.getValue(i+1);	
					}
					outfile<<endl;
					//outfile<<list.print();
				}
			}
		}
		flag=1;//������һغ� 	
	}
	infile.close(); 
    outfile.close();
    system("pause");
	return 0;
}
