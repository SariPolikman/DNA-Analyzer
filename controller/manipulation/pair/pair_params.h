#ifndef ANALYZE_PAIR_PARAMS_H
#define ANALYZE_PAIR_PARAMS_H


#include "../../Iparams.h"

class PairParams : public IParams {
public:
    explicit PairParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/
    std::string m_seq;


};

inline PairParams::PairParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);

}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}

#endif //ANALYZE_PAIR_PARAMS_H
