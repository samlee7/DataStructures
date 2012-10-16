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

#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

#include "Stack.h"
#include <iostream>

using namespace std;

struct ListNode
{
	string info;
	ListNode *next;
		
	ListNode(string s, ListNode *n)		//O(1)
		: info(s), next(n)
	{}
};

class LinkedStack: public Stack {
	
	ListNode *head;
	
	public:
	
	LinkedStack()		//O(1)
		:head(NULL) {}
		
	void push(string s)		//O(1)
	{
		head=new ListNode(s,head);
	}
	
	string pop()		//O(1)
	{
		if(isEmpty()) ContainerUnderflow("Stack is empty");
		ListNode *temp=head;
		string ret=head->info;
		head=head->next;
		delete temp;
		return ret;
	}
	
	string top()		//O(1)
	{
		if(!isEmpty()) return head->info;
		else return "Empty";
	}
	
	bool isFull()		//O(1)
	{
		return false;
	}
	
	bool isEmpty()		//O(1)
	{
		return head==NULL;
	}
	
	~LinkedStack()		//O(N)
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

#endif
