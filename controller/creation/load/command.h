#ifndef __LOAD_H__
#define __LOAD_H__

#include "../../Icomand.h"
#include "load_params.h"

class Load : public Exec
{
public:

	void set(std::string);
	/*virtual*/ std::string execute(Data* data);
	Exec* clone() const { return new Load(*this); }
	std::string get_type() const { return "load";}

};

inline void Load::set(std::string parameters)
{
    m_params = new LoadParams(parameters);
}

inline std::string Load::execute(Data* data)
{
	DnaSequence* newSeq = new DnaSequence(readFromFile(dynamic_cast<LoadParams *>(m_params)->m_fileName + std::string(".rawdna")));
	DnaMetaData newDna = DnaMetaData(dynamic_cast<LoadParams *>(m_params) -> m_seqName, newSeq);
	data->insert(newDna);
	return newDna.stringFormat();
}

#endif
