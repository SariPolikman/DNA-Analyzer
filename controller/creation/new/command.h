#ifndef __NEW_H__
#define __NEW_H__

#include "../../Icomand.h"
#include "params.h"


class New : public Exec
{
public:

    void set(std::string parameters);//
    /*virtual*/ std::string execute(Data*);
    Exec* clone() const { return new New(*this); }
    std::string get_type() const { return "new";}

};

inline void New::set(std::string parameters)
{
//    dynamic_cast<NewParams *>(m_params)->valid(parameters);
    m_params = new NewParams(parameters);
}

inline std::string New::execute(Data* data)
{
	DnaSequence* newSeq = new DnaSequence(dynamic_cast<NewParams *>(m_params)->m_seq);
	DnaMetaData newDna = DnaMetaData(dynamic_cast<NewParams *>(m_params)->m_name, newSeq);
	data->insert(newDna);
	return newDna.stringFormat();
}

#endif
