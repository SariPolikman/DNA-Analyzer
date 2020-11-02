#ifndef ANALYZE_SHOW_PARAMS_H
#define ANALYZE_SHOW_PARAMS_H



#include "../../Iparams.h"

class ShowParams : public IParams {
public:
    explicit ShowParams(std::string parameters);

    std::string m_seq;


};

inline ShowParams::ShowParams(std::string parameters)
{
    m_seq = popFirstWord(parameters);

}

#endif //ANALYZE_SHOW_PARAMS_H
