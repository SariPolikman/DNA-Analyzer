//
// Created by sari on 9/22/20.
//

#ifndef ANALYZE_RENAME_PARAMS_H
#define ANALYZE_RENAME_PARAMS_H



#include "../../Iparams.h"

class RenameParams : public IParams {
public:
    explicit RenameParams(std::string parameters);


//    NewParams(NewParams *pParams);

/*private: public or get func?*/

    std::string m_seq;
    std::string m_newName;


};

inline RenameParams::RenameParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);
    m_newName = popFirstWord(parameters).substr(1);
}

//inline NewParams::NewParams(NewParams *pParams) {
//    m_seq = pParams->m_seq;
//    m_name = pParams->m_name;
//
//}


#endif //ANALYZE_RENAME_PARAMS_H
