#include "LList.h"
#include <iostream>
using namespace std;
	void LList::init(){
		curr = tail = head = new Link(0,0);
		cnt =0;
	}
	void LList::removeall(){
		while(head != NULL){
			curr = head;
			head = head->next;
			delete curr;
		}
	}
	int LList::havecnt(){
		return cnt;
	}
	bool LList::havenext(){
		if(curr==tail)
		return false;
		else return true;
	}
	void LList::next()
	{
		if(curr->next!=tail) 
		curr=curr->next;
		else curr = tail; 
	}
		LList::LList(int size=defaultSize){init();}
		LList::~LList(){removeall();}
		void LList::clear(){removeall();init();}
		void LList::insert(const int& it,const int& cs){
			curr->next = new Link(it,cs,curr->next);
			if(tail == curr) tail = curr->next;
			cnt++;
		}
		void LList::print()
		{
			cout<<"现在的一元n次多项式为： "<<endl;
			Link* p=head ->next;
			while(p!=tail)
			{
				if(p==head->next)
				{
					cout<<p->element<<'x'<<p->cishu;
					p=p->next;
				}
				else if(p->cishu>1)
				{
					if((p->element>=0&&p->element<=9))
					{
						cout<<'+'<<p->element<<'x'<<p->cishu;
						p=p->next;
					}
					else
					{
						cout<<p->element<<'x'<<p->cishu;
						p=p->next;
					}
				}
				else if(p->cishu==1)
				{
					if((p->element>=0&&p->element<=9))
					{
						cout<<'+'<<p->element<<'x';
						p=p->next;
					}
					else 
					{
						cout<<p->element<<'x';
						p=p->next;
					}
				}
			}
			if(p->cishu!=0)
			{
				if((p->element>=0&&p->element<=9))
				{
					cout<<'+'<<p->element<<'x'<<p->cishu;
				}
				else 
				{
					cout<<p->element<<'x'<<p->cishu;
				}
			}
			else if(p->element>=0)
			{
				cout<<'+'<<p->element;
			}
			else
			{
				cout<<p->element;
			}
			cout<<endl;
		}
		void LList::append(const int& it,const int& cs){//尾端插入 
			tail = tail -> next = new Link(it,cs);
			cnt++;
		}
		const int& LList::geteleValue() const{
			try{
				if(curr==tail)
				return curr->element;
				else if(curr->next==NULL)
				{
					throw "No elevalue";
				}
				else return curr->next->element;
			}
			catch (const char* str)
			{
				cout<<str<<endl;
			}
		}
		const int& LList::getcsValue() const{
			try{
				if(curr==tail)
				return curr->cishu;
				else if(curr->next==NULL)
				{
					throw "No cishuvalue";
				}
				else return curr->next->cishu;
			}
			catch (const char* str)
			{
				cout<<str<<endl;
			}
		}
