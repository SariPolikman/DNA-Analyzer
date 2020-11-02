#ifndef ANALYZE_SLICE_PARAMS_H
#define ANALYZE_SLICE_PARAMS_H


#include "../../Iparams.h"

class SliceParams : public IParams {
public:
    explicit SliceParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/
    std::string m_identSeq;
    int m_fromInd;
    int m_toInd;


};

inline SliceParams::SliceParams(std::string parameters)
{
    //TODO validation len parameters
    m_identSeq = popFirstWord(parameters);
    m_fromInd = std::stoi(popFirstWord(parameters));
    m_toInd = std::stoi(popFirstWord(parameters));

}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}


#endif //ANALYZE_SLICE_PARAMS_H
