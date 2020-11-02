#ifndef ANALYZE_FINDALL_PARAMS_H
#define ANALYZE_FINDALL_PARAMS_H

#include "../../Iparams.h"

class FindAllParams : public IParams {
public:
    explicit FindAllParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/
    std::string m_seq;
    std::string m_subSeq;

};

inline FindAllParams::FindAllParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);
    m_subSeq = popFirstWord(parameters);
}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}



#endif //ANALYZE_FINDALL_PARAMS_H
