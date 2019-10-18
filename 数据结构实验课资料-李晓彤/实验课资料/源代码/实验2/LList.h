#include <iostream>
static int defaultSize=100;
using namespace std;
struct Link{
		int element;
		int cishu;
		Link *next;
		Link(const int& elemval,const int& cs, Link* nextval = NULL)
		{element = elemval;cishu=cs;next = nextval;}
		Link(Link* nextval = NULL){next = nextval;}
};
class LList{
private:
	Link* head;
	Link* tail;
	Link* curr;
	int cnt;//链表长度 
	
	void init();
	
	void removeall();
	
	public:
		int havecnt();
		LList(int);
		~LList();
		bool havenext();
		void next();
		void print() const;
		void clear();
		
		void insert(const int& it,const int& cs);
		void print();
		
		void append(const int& it,const int& cs);//尾端插入 
		const int& geteleValue() const;
		const int& getcsValue() const;
};
