#ifndef __CONTAINEROVERFLOW_H__
#define __CONTAINEROVERFLOW_H__

#include <string>
#include <exception>

using namespace std;

class ContainerOverflow
{
	string message;
	
	public:
	
	ContainerOverflow(string s)
	{
		message=s;
		throw(s);
	}
		
		
	
};

#endif
