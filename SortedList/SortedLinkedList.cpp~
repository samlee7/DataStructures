// Course: CS 14 Winter 2012
//
// First Name: Sam
// Last Name: Lee
// Course username: slee103
// email address: slee103@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Lumasag
//
// Assignment: HW3
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#include <string>
#include <iostream>
#include "Timer.h"
#include <fstream>

using namespace std;

struct ListNode
{
	string info;
	ListNode *next;
		
	ListNode(string s, ListNode *n)		//O(1)
		: info(s), next(n)
	{}
};

class SortedLinkedList
{
	ListNode *head;
	
	public:
		SortedLinkedList(): head(NULL) {}		//O(1)
		
		ListNode* findSearch(string key)		//O(n)
		{										//This returns the node of 1 before the key node
			ListNode *temp=head;				
			ListNode *temp2=head;
			while(temp)
			{
				if(key == temp->info)
				{
					return temp2;
				}
				if(key < temp->info) 
				{
					return temp2;
				}
				temp2=temp;
				temp=temp->next;
			}
			return temp2;

		}
		

		void insert(string word)	//O(n)
		{
			if(head==NULL) 
			{
				head=new ListNode(word, NULL); 
				return;
			}
			ListNode *i=findSearch(word);
			if(i->next==NULL)
			{
				ListNode *ins = new ListNode(word, NULL);
				i->next=ins;
				return;
			}
				
			string save=(i->next)->info;
			(i->next)->info=word;
			ListNode *ins= new ListNode(save,i->next->next);
			i->next->next=ins;
		}
		
		bool find(string word)	//O(n)
		{
			ListNode *temp=head;
			while(temp)
			{
				if(temp->info == word) return true;
				temp=temp->next;
			}
			return false;
		}
		
		void remove(string word)		//O(n)
		{
			if(head->info==word)
			{
				ListNode *temp=head;
				head=head->next;
				delete temp;
				return;
			}	
			
			ListNode *temp=head;
			for(temp;temp->info!=word;temp=temp->next){} //This returns the node where data is located
				
			ListNode *del=temp->next;
			if(del==NULL){
				temp=NULL;
				return;
			}
			
			temp->info=del->info;
			temp->next=del->next;
			delete del;
			
			
		}
		void print()		//O(n)
		{
			ListNode *temp=head;
			while(temp)
			{
				cout<<temp->info<<endl;
				temp=temp->next;
			}
			delete temp;
		}
		
		int count()		//O(n)
		{
			int count=0;
			ListNode *temp=head;
			while(temp)
			{
				++count;
				temp=temp->next;
			}
			return count;
		}
		
		~SortedLinkedList()		//O(n)
		{
			ListNode* temp=head;
			ListNode* del;
			while(temp)
			{
				del=temp->next;
				delete temp;
				temp=del;
			}	
		}		
			
		

};

	void insertAllWords(SortedLinkedList &A,  char *file)	//O(n^2)
	{
		ifstream in; 
		in.open(file);
		Timer t;
		string word;
		double etime;
		t.start();
		while(in>>word)
		{
			A.insert(word);
		}
		t.elapsedUserTime(etime);
		cout<<etime<<endl;
	
		
	}
	
	void findAllWords(SortedLinkedList &A, char *file)	//O(n^2)
	{
		ifstream in; in.open(file);
		Timer t;
		string word;
		double etime;
		t.start();
		while(in>>word)
		{
			A.find(word);
		}
		t.elapsedUserTime(etime);
		cout<<etime<<endl;	
		
	}	
	
	void removeAllWords(SortedLinkedList &A, char *file)	//O(n^2)
	{
		ifstream in; in.open(file);
		Timer t;
		string word;
		double etime;
		t.start();
		while(in>>word)
		{
			A.remove(word);
		}
		t.elapsedUserTime(etime);
		cout<<etime<<endl;	
		
	}	

int main()
{
	SortedLinkedList list1=SortedLinkedList();
	insertAllWords(list1, "random.txt");	
	findAllWords(list1, "random.txt");
	removeAllWords(list1, "random.txt");

}
