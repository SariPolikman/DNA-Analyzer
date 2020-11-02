#ifndef __FIND_H__
#define __FIND_H__

#include "../../Icomand.h"

class Find : public Exec
{
public:
	void set(std::string parameters);
	/*virtual*/std::string execute(Data*);
	Exec* clone() const { return new Find(*this); }
	std::string get_type() const { return "find";}

};


#endif
