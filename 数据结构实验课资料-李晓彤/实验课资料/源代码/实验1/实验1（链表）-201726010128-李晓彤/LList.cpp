#include "List.h"
#include <iostream>
using namespace std;
template <typename E> struct Link{
		E element;
		Link *next;
		Link(const E& elemval, Link* nextval = NULL)
		{element = elemval;next = nextval;}
		Link(Link* nextval = NULL){next = nextval;}
};

template <typename E> 
class LList:public List<E>{
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt;//链表长度 
	
	void init(){
		curr = tail = head = new Link<E>;
		cnt =0;
	}
	
	void removeall(){
		while(head != NULL){
			curr = head;
			head = head->next;
			delete curr;
		}
	}
	
	public:
		LList(int size=defaultSize){init();}
		~LList(){removeall();}
		void print() const;
		void clear(){removeall();init();}
		
		void insert(const E& it){
			curr->next = new Link<E>(it,curr->next);
			if(tail == curr) tail = curr->next;
			cnt++;
		}
		void print()
		{
			cout<<"现在的链表为： "<<endl;
			Link<E>* p=head ->next;
			while(p!=tail)
			{
				cout<<p->element<<',';
				p=p->next;
			}
			cout<<p->element<<endl;
		}
		void append(const E& it){
			tail = tail -> next = new Link<E>(it);
			cnt++;
		}
		
		E remove(){
			try{
				if(curr->next == NULL)
				{
					throw "No element";
				}
				E it = curr->next->element;
				Link<E>* ltemp = curr->next;
				if(tail == curr->next)tail = curr;
				curr->next = curr->next->next;
				delete ltemp;
				cnt--;
				return it;
			}
			catch(const char* str)
			{
				cout<<str<<endl;
			}
		}
		
		void moveToStart()
		{curr = head;}
		
		void moveToEnd()
		{curr = tail;}
		
		void prev(){
			if(curr==head)return;
			Link<E>* temp=head;
			
			while (temp->next!=curr)temp=temp->next;
			curr = temp;
		}
		
		void next()
		{if(curr != tail)curr = curr->next;}
		
		int length() const{return cnt;}
		
		int currPos() const
		{
			Link<E>* temp = head;
			int i;
			for(i=0; curr != temp; i++)
				temp = temp->next;
			return i;
		}
		
		void moveToPos(int pos){
			try{
				if(pos<0||pos>cnt)
				{
					throw "Position out of range";
				}
				curr = head;
				for(int i=0; i<pos; i++)curr = curr->next;
			}
			catch (const char* str)
			{
				cout<<str<<endl;
			}
		}
		
		const E& getValue() const{
			try{
				if(curr==tail)
				return curr->element;
				else if(curr->next==NULL)
				{
					throw "No value";
				}
				else return curr->next->element;
			}
			catch (const char* str)
			{
				cout<<str<<endl;
			}
		}
};
