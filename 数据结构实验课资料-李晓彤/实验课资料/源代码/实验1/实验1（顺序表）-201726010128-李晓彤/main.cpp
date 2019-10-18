//顺序表实现的主函数
#include "Alist.cpp"
#include <iostream>
using namespace std;
template <typename T>
void function(int);

int main() {
	void test(int);
	int size=0;
	cout<<"======欢迎来到基于顺序表实现的线性表测试======\n";
	cout<<"请输入测试规模：例如'10'\n";
	cin>>size;
	test(size);
}
void test(int size) {
	int a=0;
	cout<<"======请选择要测试的数据类型==================\n";
	cout<<"====== 1.int      ============================\n";
	cout<<"====== 2.char     ============================\n";
	cout<<"====== 3.double   ============================\n";
	cout<<"====== 4.float    ============================\n";
	cout<<"====== 5.bool     ============================\n";
	cout<<"====== 6.string   ============================\n";
	cout<<"====== 0.退出程序 ============================\n";
	cin>>a;
	if(a>6) {
		cout<<"输入错误，程序结束\n";
	} else {
		switch(a) {
			case 0: {
				cout<<"欢迎您再次使用程序，我们下次再见\n";
				break;
			}
			case 1: {
				cout<<"您接下来的测试数据类型为int\n";
				function<int>(size);
				break;
			}
			case 2: {
				cout<<"您接下来的测试数据类型为char\n";
				function<char>(size);
				break;
			}
			case 3: {
				cout<<"您接下来的测试数据类型为double\n";
				function<double>(size);
				break;
			}
			case 4: {
				cout<<"您接下来的测试数据类型为float\n";
				function<float>(size);
				break;
			}
			case 5: {
				cout<<"您接下来的测试数据类型为bool\n";
				function<bool>(size);
				break;
			}
			case 6: {
				cout<<"您接下来的测试数据类型为string\n";
				function<string>(size);
				break;
			}
			default: {
				cout<<"输入命令错误，程序结束\n";
				break;
			}
		}
	}
	system("pause");
}
template <typename T>
void function(int a) {
	int m=0;
	Alist<T> list(a);
	cout<<"现已生成一个规模为"<<a<<"的顺序表\n";
	while(1) {
		cout<<"======请选择要执行的功能================\n";
		cout<<"======1.顺序表末尾加入元素==============\n";
		cout<<"======2.在当前位置插入元素==============\n";
		cout<<"======3.删除并返回当前元素值============\n";
		cout<<"======4.移动至开头      ================\n";
		cout<<"======5.移动至表尾      ================\n";
		cout<<"======6.前移一位        ================\n";
		cout<<"======7.后移一位        ================\n";
		cout<<"======8.返回顺序表长度  ================\n";
		cout<<"======9.返回当前位置    ================\n";
		cout<<"======10.移动到指定位置 ================\n";
		cout<<"======11.返回当前元素值 ================\n";
		cout<<"======0.结束程序        ================\n";
		cin>>m;
		switch(m) {
			case 0: {
				cout<<"欢迎您再次使用程序，我们下次再见\n";
				break;
			}
			case 1: {
				cout<<"请输入要添加的元素个数:"<<endl;
				int s=0;
				cin>>s;
				cout<<"请输入要添加的元素：（用空格隔开）"<<endl;
				T yuansu;
				for(int i=0; i<s; i++) {
					cin>>yuansu;
					list.append(yuansu);
				}
				list.print();
				break;
			}
			case 2: {
				cout<<"输入要插入的元素: ";
				T yuansu;
				cin>>yuansu;
				list.insert(yuansu);
				list.print();
				break;
			}
			case 3: {
				cout<<"删除元素为： "<<list.remove()<<endl;
				list.print();
				break;
			}
			case 4: {
				list.moveToStart();
				cout<<"移动后的位置为： "<<list.currPos()<<endl;
				break;
			}
			case 5: {
				list.moveToEnd();
				cout<<"移动后的位置为： "<<list.currPos()<<endl;
				break;
			}
			case 6: {
				list.prev();
				cout<<"移动后的位置为： "<<list.currPos()<<endl;
				break;
			}
			case 7: {
				list.next();
				cout<<"移动后的位置为： "<<list.currPos()<<endl;
				break;
			}
			case 8: {
				cout<<"该顺序表长度为： "<<list.length()<<endl;
				break;
			}
			case 9: {
				cout<<"当前位置为： "<<list.currPos()<<endl;
				break;
			}
			case 10: {
				cout<<"请输入位置，例如'6'"<<endl;
				int p=0;
				cin>>p;
				list.moveToPos(p);
				cout<<"移动后的位置为： "<<list.currPos()<<endl;
				break;
			}
			case 11: {
				cout<<"当前元素值为： "<<list.getValue()<<endl;
				break;
			}
			default: {
				cout<<"输入命令有误，程序结束"<<endl;
				break;
			}
		}
		if(m==0)
		break;
	}
	system("pause");
}
