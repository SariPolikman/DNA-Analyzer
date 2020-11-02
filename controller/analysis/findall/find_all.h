#ifndef __FIND_ALL_H__
#define __FIND_ALL_H__

#include "../../Icomand.h"

class FindAll : public Exec
{
public:
	void set(std::string parameters);
	/*virtual*/std::string execute(Data*);
	Exec* clone() const { return new FindAll(*this); }
	std::string get_type() const { return "findall";}

};


#endif
