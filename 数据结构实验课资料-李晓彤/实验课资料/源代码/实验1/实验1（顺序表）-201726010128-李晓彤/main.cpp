//˳���ʵ�ֵ�������
#include "Alist.cpp"
#include <iostream>
using namespace std;
template <typename T>
void function(int);

int main() {
	void test(int);
	int size=0;
	cout<<"======��ӭ��������˳���ʵ�ֵ����Ա����======\n";
	cout<<"��������Թ�ģ������'10'\n";
	cin>>size;
	test(size);
}
void test(int size) {
	int a=0;
	cout<<"======��ѡ��Ҫ���Ե���������==================\n";
	cout<<"====== 1.int      ============================\n";
	cout<<"====== 2.char     ============================\n";
	cout<<"====== 3.double   ============================\n";
	cout<<"====== 4.float    ============================\n";
	cout<<"====== 5.bool     ============================\n";
	cout<<"====== 6.string   ============================\n";
	cout<<"====== 0.�˳����� ============================\n";
	cin>>a;
	if(a>6) {
		cout<<"������󣬳������\n";
	} else {
		switch(a) {
			case 0: {
				cout<<"��ӭ���ٴ�ʹ�ó��������´��ټ�\n";
				break;
			}
			case 1: {
				cout<<"���������Ĳ�����������Ϊint\n";
				function<int>(size);
				break;
			}
			case 2: {
				cout<<"���������Ĳ�����������Ϊchar\n";
				function<char>(size);
				break;
			}
			case 3: {
				cout<<"���������Ĳ�����������Ϊdouble\n";
				function<double>(size);
				break;
			}
			case 4: {
				cout<<"���������Ĳ�����������Ϊfloat\n";
				function<float>(size);
				break;
			}
			case 5: {
				cout<<"���������Ĳ�����������Ϊbool\n";
				function<bool>(size);
				break;
			}
			case 6: {
				cout<<"���������Ĳ�����������Ϊstring\n";
				function<string>(size);
				break;
			}
			default: {
				cout<<"����������󣬳������\n";
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
	cout<<"��������һ����ģΪ"<<a<<"��˳���\n";
	while(1) {
		cout<<"======��ѡ��Ҫִ�еĹ���================\n";
		cout<<"======1.˳���ĩβ����Ԫ��==============\n";
		cout<<"======2.�ڵ�ǰλ�ò���Ԫ��==============\n";
		cout<<"======3.ɾ�������ص�ǰԪ��ֵ============\n";
		cout<<"======4.�ƶ�����ͷ      ================\n";
		cout<<"======5.�ƶ�����β      ================\n";
		cout<<"======6.ǰ��һλ        ================\n";
		cout<<"======7.����һλ        ================\n";
		cout<<"======8.����˳�����  ================\n";
		cout<<"======9.���ص�ǰλ��    ================\n";
		cout<<"======10.�ƶ���ָ��λ�� ================\n";
		cout<<"======11.���ص�ǰԪ��ֵ ================\n";
		cout<<"======0.��������        ================\n";
		cin>>m;
		switch(m) {
			case 0: {
				cout<<"��ӭ���ٴ�ʹ�ó��������´��ټ�\n";
				break;
			}
			case 1: {
				cout<<"������Ҫ��ӵ�Ԫ�ظ���:"<<endl;
				int s=0;
				cin>>s;
				cout<<"������Ҫ��ӵ�Ԫ�أ����ÿո������"<<endl;
				T yuansu;
				for(int i=0; i<s; i++) {
					cin>>yuansu;
					list.append(yuansu);
				}
				list.print();
				break;
			}
			case 2: {
				cout<<"����Ҫ�����Ԫ��: ";
				T yuansu;
				cin>>yuansu;
				list.insert(yuansu);
				list.print();
				break;
			}
			case 3: {
				cout<<"ɾ��Ԫ��Ϊ�� "<<list.remove()<<endl;
				list.print();
				break;
			}
			case 4: {
				list.moveToStart();
				cout<<"�ƶ����λ��Ϊ�� "<<list.currPos()<<endl;
				break;
			}
			case 5: {
				list.moveToEnd();
				cout<<"�ƶ����λ��Ϊ�� "<<list.currPos()<<endl;
				break;
			}
			case 6: {
				list.prev();
				cout<<"�ƶ����λ��Ϊ�� "<<list.currPos()<<endl;
				break;
			}
			case 7: {
				list.next();
				cout<<"�ƶ����λ��Ϊ�� "<<list.currPos()<<endl;
				break;
			}
			case 8: {
				cout<<"��˳�����Ϊ�� "<<list.length()<<endl;
				break;
			}
			case 9: {
				cout<<"��ǰλ��Ϊ�� "<<list.currPos()<<endl;
				break;
			}
			case 10: {
				cout<<"������λ�ã�����'6'"<<endl;
				int p=0;
				cin>>p;
				list.moveToPos(p);
				cout<<"�ƶ����λ��Ϊ�� "<<list.currPos()<<endl;
				break;
			}
			case 11: {
				cout<<"��ǰԪ��ֵΪ�� "<<list.getValue()<<endl;
				break;
			}
			default: {
				cout<<"�����������󣬳������"<<endl;
				break;
			}
		}
		if(m==0)
		break;
	}
	system("pause");
}
