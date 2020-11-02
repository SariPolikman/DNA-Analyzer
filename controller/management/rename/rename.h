#ifndef __RENAME_H__
#define __RENAME_H__

#include "../../Icomand.h"
#include "rename_params.h"



class Rename : public Exec
{
public:
    void set(std::string parameters);
    /*virtual*/std::string execute(Data*);
    Exec* clone() const { return new Rename(*this); }
    std::string get_type() const { return "rename";}

};


#endif
