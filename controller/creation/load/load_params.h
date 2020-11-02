#ifndef ANALYZE_LOAD_PARAMS_H
#define ANALYZE_LOAD_PARAMS_H



#include "../../Iparams.h"

class LoadParams : public IParams {
public:
    explicit LoadParams(std::string parameters);


//    LoadParams(LoadParams *pParams);

/*private: public or get func?*/
    std::string m_fileName;
    std::string m_seqName;


};

inline LoadParams::LoadParams(std::string parameters)
{
    m_fileName = popFirstWord(parameters);

    if(parameters.empty())
    {
        m_seqName = m_fileName;
    }
    else m_seqName = popFirstWord(parameters);

}

//inline LoadParams::LoadParams(LoadParams *pParams) {
//    m_fileName = pParams -> m_fileName;
//    m_seqName  = pParams -> m_seqName;
//
//}


#endif //ANALYZE_LOAD_PARAMS_H
