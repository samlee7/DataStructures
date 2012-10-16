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
// Assignment: HW5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// =================================================================
#include "BinarySearchTree.h"
#include "Timer.h"
#include <fstream>
	
	
	void insertAllWords(BinarySearchTree &A,  char *file)	//O(n^2)
	{
		ifstream in; 
		in.open(file);
		Timer t;
		string word;
		double etime;
		t.start();
		while(in>>word)
		{
			A.insert(word,1);
		}
		t.elapsedUserTime(etime);
		cout<<etime<<endl;
	
		
	}
	
	void findAllWords(BinarySearchTree &A, char *file)	//O(nlog(n))
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
	
	void removeAllWords(BinarySearchTree &A, char *file)		//O(n^2)
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
	BinarySearchTree lol=BinarySearchTree();
	insertAllWords(lol, "random.txt");
	//lol.print();
	//findAllWords(lol,"test.txt");
	//removeAllWords(lol, "test.txt");
	
	
	
}
