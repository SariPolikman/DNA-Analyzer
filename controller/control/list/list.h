#ifndef __LIST_H__
#define __LIST_H__

#include "../../Icomand.h"

class List : public Exec
{
public:
	void set(std::string parameters){}
	/*virtual*/std::string execute(Data*);
	Exec* clone() const { return new List(*this); }
	std::string get_type() const { return "list";}
};


#endif
