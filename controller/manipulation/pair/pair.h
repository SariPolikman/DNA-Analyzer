#ifndef __PAIR_H__
#define __PAIR_H__

#include "../../Icomand.h"
#include "pair_params.h"


class Pair : public Exec
{
public:

    void set(std::string parameters);
    /*virtual*/std::string execute(Data*);
    Exec* clone() const { return new Pair(*this); }
    std::string get_type() const { return "pair";}
};

inline void Pair::set(std::string parameters)
{
    m_params = new PairParams(parameters);
}

inline std::string Pair::execute(Data* data)
{
    DnaMetaData* DNA = const_cast<DnaMetaData *>(data -> getSeq(dynamic_cast<PairParams *>(m_params) -> m_seq));
    DnaSequence d(DNA -> getDNA() -> pairing());
    (*(DNA -> getDNA())) = d;
    return DNA->stringFormat();
}
#endif
