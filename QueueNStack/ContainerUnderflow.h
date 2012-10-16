#ifndef __CONTAINERUNDERFLOW_H__
#define __CONTAINERUNDERFLOW_H__

#include <string>
#include <exception>

using namespace std;

class ContainerUnderflow
{
	string message;
	
	public:
	
	ContainerUnderflow(string s)
	{
		message=s;
		throw(s);
	}
		
		
	
};

#endif
