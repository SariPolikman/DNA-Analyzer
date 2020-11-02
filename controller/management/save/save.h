#ifndef __SAVE_H__
#define __SAVE_H__


#include "../../Icomand.h"
#include "save_params.h"

class Save : public Exec
{
public:

    void set(std::string parameters);
    /*virtual*/std::string execute(Data*);
    Exec* clone() const { return new Save(*this); }
    std::string get_type() const { return "save";}


};

inline void Save::set(std::string parameters)
{
    m_params = new SaveParams(parameters);
}

inline std::string Save::execute(Data* data)
{
    SaveParams * saveParams = dynamic_cast<SaveParams *>(m_params);
	const DnaMetaData* d = data -> getSeq(saveParams -> m_seq);
	if (saveParams -> m_fileName.empty())
    {
	    std::string name = d -> getName();
        saveParams -> m_fileName = name.substr(1);
    }
	char dna_file [saveParams -> m_fileName.length() + 1];

	std::string s = saveParams -> m_fileName + std::string(".rawdna");

	strcpy(dna_file, (s).c_str());
	d-> getDNA() -> writeToFile(const_cast<const char*>(dna_file));
	return "";
}
#endif
