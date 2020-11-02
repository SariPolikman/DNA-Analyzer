#ifndef ANALYZE_REPLACE_PARAMS_H
#define ANALYZE_REPLACE_PARAMS_H


#include "../../Iparams.h"

class ReplaceParams : public IParams {
public:
    explicit ReplaceParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/

    std::string m_seq;
    std::string m_index;
    char m_newLetter;


};

inline ReplaceParams::ReplaceParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);
    m_index = popFirstWord(parameters);
    m_newLetter = popFirstWord(parameters)[0];

}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}


#endif //ANALYZE_REPLACE_PARAMS_H
