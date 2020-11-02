#ifndef ANALYZE_NEW_PARAMS_H
#define ANALYZE_NEW_PARAMS_H

#include "../../Iparams.h"

class NewParams : public IParams {
public:
    explicit NewParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/
    std::string m_name;
    std::string m_seq;


};

inline NewParams::NewParams(std::string parameters)
{

    m_seq = popFirstWord(parameters);
    static size_t nextDefaultName = 1;

    if(parameters.empty())
    {
        m_name = ("seq" + std::to_string(nextDefaultName++));
    }
    else m_name = popFirstWord(parameters);

}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}


#endif //ANALYZE_NEW_PARAMS_H
