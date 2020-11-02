#ifndef __SHOW_H__
#define __SHOW_H__

#include "../../Icomand.h"


class Show : public Exec
{
public:
	void set(std::string parameters);
	/*virtual*/ std::string execute(Data*);
	Exec* clone() const { return new Show(*this); }
	std::string get_type() const { return "show";}


};


#endif
