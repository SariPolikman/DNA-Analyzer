#ifndef ANALYZE_SAVE_PARAMS_H
#define ANALYZE_SAVE_PARAMS_H


#include "../../Iparams.h"

class SaveParams : public IParams {
public:
    explicit SaveParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/

    std::string m_fileName;
    std::string m_seq;


};

inline SaveParams::SaveParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);

    if(not parameters.empty())
    {
        m_fileName = popFirstWord(parameters);
    }


}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}

#endif //ANALYZE_SAVE_PARAMS_H
