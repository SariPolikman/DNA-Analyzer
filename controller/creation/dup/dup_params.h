#ifndef ANALYZE_DUP_PARAMS_H
#define ANALYZE_DUP_PARAMS_H



#include "../../Iparams.h"

class DupParams : public IParams {
public:
    explicit DupParams(std::string parameters);


//    LoadParams(LoadParams *pParams);

/*private: public or get func?*/
    std::string m_oldSeq;
    std::string m_newSeqName;


};

inline DupParams::DupParams(std::string parameters)
{
    m_oldSeq = popFirstWord(parameters);
    static size_t nextDefaultName = 1;

    if(parameters == "")
    {
        m_newSeqName = (m_oldSeq.substr(1) + "_" + std::to_string(nextDefaultName++));
    }
    else m_newSeqName = popFirstWord(parameters);

}

//inline LoadParams::LoadParams(LoadParams *pParams) {
//    m_fileName = pParams -> m_fileName;
//    m_seqName  = pParams -> m_seqName;
//
//}

#endif //ANALYZE_DUP_PARAMS_H
