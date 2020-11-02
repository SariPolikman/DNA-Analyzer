#ifndef __COUNT_H__
#define __COUNT_H__

#include "../../Icomand.h"
#include "count_params.h"

class Count : public Exec
{
public:
	void set(std::string parameters);
	/*virtual*/std::string execute(Data*);
	Exec* clone() const { return new Count(*this); }
	std::string get_type() const { return "count";}

};


#endif
