#include <iostream>
#include "SOList.h"
#include <string>
#include <fstream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	const char* FileIn[5] = {//线性表文档 
		"text1.txt",
		"text2.txt",
		"text3.txt",
		"text4.txt",
		"text5.txt"
	};
	const char* Fileresult[5] = {//结果文档 
		"result1.txt",
		"result2.txt",
		"result3.txt",
		"result4.txt",
		"result5.txt"
	};
	
	cout<<"---欢迎来到自组织线性表的文件内容查找---"<<endl;
	cout<<"请输入要打开的文件（这里只有5个）：例如打开text1则输入1，结果在result1中显示"<<endl;
	int name;
	cin>>name;
	ifstream infile,in;
	ofstream outfile;
	
	in.open(FileIn[name-1],ios::in);
	outfile.open(Fileresult[name-1],ios::out);//输出查找结果的文件
	string  temp,temp2;
	
	in>>temp2;//获取查找文件中原来线性表的长度 
	in.close();//关闭文件关联 
	infile.open(FileIn[name-1],ios::in);//查找内容的文件
	//in.open(Find[name-1],ios::in); 
	int n=0;
	n=temp2.length();
	SOList list(n);
	int flag=0;//插入回合
	while(!infile.eof()) {//到文件末尾则停止 
		infile>>temp;//把文件的一行字符串输出到temp里,遇到空格或者换行结束 
		for (int i = 0; i < temp.length(); i =i+2) {
			if (flag==0) {//插入回合 
				list.append(temp[i], temp[i + 1]);
			} else {//查找回合 
				int resul = list.find(temp[i],temp[i+1]);
				if (resul != -1) {//查找到了 
					outfile<<"查找成功!查找次数为:"<<resul/2+1;
					outfile<<endl;
					outfile<<"当前自组织线性表为：";
					for(int i=0;i<n;i+=2)
					{
						outfile<<list.getValue(i)<<list.getValue(i+1);	
					}
					outfile<<endl;
				} else {
					outfile<<"查找失败!查找次数为:"<<n/2;
					outfile<<endl;
					outfile<<"当前自组织线性表为：";
					for(int i=0;i<n;i+=2)
					{
						outfile<<list.getValue(i)<<list.getValue(i+1);	
					}
					outfile<<endl;
					//outfile<<list.print();
				}
			}
		}
		flag=1;//进入查找回合 	
	}
	infile.close(); 
    outfile.close();
    system("pause");
	return 0;
}
