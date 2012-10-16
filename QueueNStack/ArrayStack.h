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

#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include "Stack.h"
#include <iostream>

using namespace std;

class ArrayStack: public Stack {
	
	int capacity, topIndex;
	string *stk;
	
	public:
	
	ArrayStack(int cap)		//O(1)
		:stk(new string[cap]), capacity(cap), topIndex(0) {}
		
	void push(string s)		//O(1)
	{
		if(isFull()) ContainerOverflow("Stack is full");
		stk[topIndex++]=s;
	}
	
	string pop()			//O(1)
	{
		if(isEmpty()) ContainerUnderflow("Stack is empty");
		return stk[--topIndex];
	}
	
	string top()		//O(1)
	{
		return stk[topIndex-1];
	}
	
	bool isFull()		//O(1)
	{
		return topIndex >= capacity;
	}
	
	bool isEmpty()		//O(1)
	{
		return topIndex <= 0;
	}
	
	~ArrayStack()		//O(N)
	{
		delete []stk;
	}
	
};

#endif	
