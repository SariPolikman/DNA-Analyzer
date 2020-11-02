#ifndef ANALYZE_FIND_PARAMS_H
#define ANALYZE_FIND_PARAMS_H




#include "../../Iparams.h"

class FindParams : public IParams {
public:
    explicit FindParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/


    std::string m_seq;
    std::string m_subSeq;

};

inline FindParams::FindParams(std::string parameters)
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
