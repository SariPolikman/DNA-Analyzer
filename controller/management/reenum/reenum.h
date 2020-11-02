#ifndef __REENUM_H__
#define __REENUM_H__

#include "../../Icomand.h"

class Reenum : public Exec
{
public:
	void set(std::string parameters){}
	/*virtual*/std::string execute(Data*);
	Exec* clone() const { return new Reenum(*this); }
	std::string get_type() const { return "reenum";}
};


#endif
