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
// Assignment: HW4
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================

#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__

#include "Queue.h"

struct ListNode
{
	string info;
	ListNode *next;
		
	ListNode(string s, ListNode *n)		//O(1)
		: info(s), next(n)
	{}
};

class LinkedQueue :public Queue
{
	ListNode *head;
	ListNode *tail;
	
	public:
	
	LinkedQueue ()		//O(1)
		: head(NULL), tail(NULL) {}
		
	void enq(string s)		//O(1)
	{
		ListNode *temp=new ListNode(s,NULL);
		if(!tail) head=temp;
		else tail->next=temp;
		
		tail=temp;
	}
	
	string deq()		//O(1)
	{
		if(isEmpty()) ContainerUnderflow("Queue is empty");
		ListNode *temp=head;
		string ret=head->info;
		head=head->next;
		delete temp;
		return ret;		
	}
	
	string front()		//O(1)
	{
		return head->info;
	}
	
	bool isEmpty()		//O(1)
	{
		return head==NULL;
	}
	
	bool isFull()		//O(1)
	{
		return false;
	}
	
};

#endif
