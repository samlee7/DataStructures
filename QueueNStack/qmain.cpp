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

#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include <fstream>
#include <iostream>

void fillAll(Queue &A, char *file)		//O(N)
{
	ifstream in;
	in.open(file);
	string word;
	while(in>>word)
	{
		A.enq(word);
	}
	in.close();
}

void emptyAll(Queue &A, char *file)		//O(N)
{
	ofstream out;
	out.open(file);
	string word;
	while(!(A.isEmpty()))
	{
		word=A.deq();
		out<<word<<endl;
	}
	out.close();
}
	

int main()
{
	try{
	LinkedQueue stk1= LinkedQueue();
	ArrayQueue stk2= ArrayQueue(45500);
	fillAll(stk1,"random.txt");
	emptyAll(stk1,"LQoutput.txt");
	fillAll(stk2,"random.txt");
	emptyAll(stk2,"AQoutput.txt");	
	}
	catch(string error)
	{
		cout<<"Error: "<< error<<endl;
	}
}
