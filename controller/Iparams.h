#ifndef ANALYZE_IPARAMS_H
#define ANALYZE_IPARAMS_H


#include <string>
#include <stdexcept>
#include "../pop_first_word.h"


class IParams {
public:
    virtual void valid(std::string parameters, size_t len = 0){ length(parameters, len);}

    struct InvalidParams: public std::runtime_error {
    public:
        InvalidParams(const char *what) : runtime_error(what) {}
    };


private:
    virtual void length(std::string params, size_t i ){if(params.length() == i) throw InvalidParams("exepted i parameters but params.length() given");}
//        virtual void spaces();
//        virtual void lack_of_names();
//        virtual void enter();

};



#endif //ANALYZE_IPARAMS_H
