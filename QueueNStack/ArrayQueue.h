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

#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include "Queue.h"


class ArrayQueue :public Queue
{
	int capacity, lead, rear;
	string *buf;
	
	public:
	
	ArrayQueue(int maxSize)		//O(1)
		: capacity(maxSize), lead(0), rear(0), buf(new string[maxSize]) {}
		
	void enq(string s)		//O(1)
	{
		if(isFull()) ContainerOverflow("Queue is full");
		buf[rear] = s;
		rear = (rear+1) % capacity;
	}
	
	string deq()		//O(1)
	{
		if(isEmpty()) ContainerUnderflow("Queue is empty");
		string ret = buf[lead];
		lead = (lead+1) % capacity;
		return ret;
	}
	
	string front()		//O(1)
	{
		return buf[lead];
	}
	
	bool isEmpty()		//O(1)
	{
		return lead==rear;
	}
	
	bool isFull()		//O(1)
	{
		return (rear+1) % capacity == lead; 
	}
	
};

#endif
