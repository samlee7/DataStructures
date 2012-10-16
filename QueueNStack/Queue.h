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

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <string>
#include "ContainerOverflow.h"
#include "ContainerUnderflow.h"

using namespace std;

class Queue
{
	public:
	
	virtual void enq(string s) = 0;
	virtual string deq() = 0;
	virtual string front() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;

	
	virtual ~Queue(){}
};

#endif
