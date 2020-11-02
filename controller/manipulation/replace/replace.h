#ifndef __REPLACE_H__
#define __REPLACE_H__


#include "../../Icomand.h"


class Replace : public Exec
{
public:
    Replace() {}
    void set(std::string parameters);
    /*virtual*/ std::string execute(Data*);
    Exec* clone() const { return new Replace(*this); }
    std::string get_type() const { return "replace";}
    

};

#endif
