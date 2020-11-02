#ifndef __DUP_H__
#define __DUP_H__

#include "../../Icomand.h"


class Dup : public Exec
{
public:
	void set(std::string parameters);
	/*virtual*/ std::string execute(Data*);
	Exec* clone() const { return new Dup(*this); }
	std::string get_type() const { return "dup";}


};


#endif
