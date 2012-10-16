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

#include "ArrayStack.h"
#include "LinkedStack.h"
#include <fstream>

void fillAll(Stack &A, char *file)		//O(N)
{
	ifstream in;
	in.open(file);
	string word;
	while(in>>word)
	{
		A.push(word);
	}
	in.close();
}

void emptyAll(Stack &A, char *file)		//O(N)
{
	ofstream out;
	out.open(file);
	string word;
	while(!(A.isEmpty()))
	{
		word=A.pop();
		out<<word<<endl;
	}
	out.close();
}

bool isBalanced(string brackets)		//O(N)
{
	LinkedStack bal = LinkedStack();
	int c1=0, c2=0, c3=0;
	string check;
	for(int i=0; i< brackets.size(); i++)
	{
		bal.push(brackets.substr(i,1));
	}
	
	for(int j=0; j<brackets.size(); j++)
	{
		check=bal.pop();
		if(check=="(") --c1;
		else if(check==")") ++c1;
		else if(check=="{") --c2;
		else if(check=="}") ++c2;
		else if(check=="[") --c3;
		else if(check=="]") ++c3;

		if(c1<0||c2<0||c3<0) return false;
	}
	//cout<<"c1: "<<c1<<" c2: "<<c2<<" c3: "<<c3<<endl;
	return (c1==0&&c2==0&&c3==0); 
}
	

int main()
{
	try{
	LinkedStack stk1=LinkedStack();
	ArrayStack stk2=ArrayStack(45500);
	fillAll(stk1,"random.txt");
	emptyAll(stk1,"LSoutput.txt");
	fillAll(stk2,"random.txt");
	emptyAll(stk2,"ASoutput.txt");
	string test="({(())})((([({})])))(((((()([{()}])(()))))))()";
	if(isBalanced(test))
		cout<<"It is balanced"<<endl;
	else
		cout<<"It is not balanced"<<endl;
	}
	catch(string error)
	{
		cout<<"Error: "<< error<<endl;
	}
}
