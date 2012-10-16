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


class SortedArrayList{
	string *buf;
	int capacity;
	int size;
	
	public:
		SortedArrayList(int cap)	//O(n)
			:buf(new string[cap]), capacity(cap), size(0)
			{}
			
			
		int findSearch(string key, int low, int high) // Binary Search to find where key belongs
		{											  //O(log(n))	
			int mid;
			while(low<=high)
			{
				mid=(low+high)/2;
				
				if(key > buf[mid])
				{
					++mid;
					low=mid;
				}
				else if(key<buf[mid]) 
				{
					high=mid-1;
				}
				else return mid;
			}
			return mid;
		}	
		
		int copyup(int i)	//O(n)
		{
			for(i; i<size-1;++i)
			{
				buf[i]=buf[i+1];
			}
			--size;
		}
		
		int copydown(int i)		//O(n)
		{
			string save,save2;
			save=buf[i];
			for(i; i<size; ++i)
			{
				save2=buf[i+1];
				buf[i+1]=save;
				save=save2;
			}
			++size;
		}
		
		
		void insert(string word)	//O(n)
		{
			if(isFull())
			{
				cout<<"Array is full!"<<endl;
				return;
			}
			if(isEmpty())
			{
				buf[0]=word;
				++size;
				return;
			}
			int i=findSearch(word,0,size-1);
			copydown(i);
			buf[i]=word;
		}
		
		bool find(string word)	//O(log(n))
		{
			int i=findSearch(word,0,size-1);
			
			return (buf[i]==word);
		}
		
		void remove(string word)	//O(n)
		{
			
			int i=findSearch(word,0,size-1);
			copyup(i);
			
		}
		
		void print()	//O(n)
		{
			for(int i=0; i<size; ++i)
			{
				cout<<buf[i]<<endl;
			}
		}
		
		~SortedArrayList()	//O(n)
		{
			delete []buf;
		}
		
		bool isEmpty()	//O(1)
		{
			return (size==0);
		}
		bool isFull()	//O(1)
		{
			return (size==capacity-1);
		}

	};
	
	
	void insertAllWords(SortedArrayList &A,  char *file)	//O(n^2)
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
	
	void findAllWords(SortedArrayList &A, char *file)	//O(nlog(n))
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
	
	void removeAllWords(SortedArrayList &A, char *file)		//O(n^2)
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
		SortedArrayList list1=SortedArrayList(45500);
		insertAllWords(list1, "random.txt");
		findAllWords(list1, "random.txt");
		removeAllWords(list1, "random.txt");
		
	}



