#ifndef __LEN_H__
#define __LEN_H__

#include "../../Icomand.h"
#include "len_params.h"

class Len : public Exec
{
public:

    void set(std::string parameters);
    /*virtual*/std::string execute(Data*);
    Exec* clone() const { return new Len(*this); }
    std::string get_type() const { return "len";}

};


#endif
