#ifndef ANALYZE_LEN_PARAMS_H
#define ANALYZE_LEN_PARAMS_H



#include "../../Iparams.h"

class LenParams : public IParams {
public:
    explicit LenParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/


    std::string m_seq;

};

inline LenParams::LenParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);
}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}


#endif //ANALYZE_LEN_PARAMS_H
