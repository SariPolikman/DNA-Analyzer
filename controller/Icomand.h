#ifndef __EXEC_CMD_H__
#define __EXEC_CMD_H__

//#include <sstream>
#include <string>
#include "../model/dna_data.h"
#include "Iparams.h"


class Exec
{
public:
    Exec():m_params(NULL){}
	virtual std::string execute(Data*) = 0;
    virtual Exec* clone() const = 0;
    virtual std::string get_type() const = 0;
    virtual void set(std::string command) = 0;

protected:
    IParams *m_params;//TODO share pointer or "&" if constract only in first time-so we will implement c-ctor
};

#endif
