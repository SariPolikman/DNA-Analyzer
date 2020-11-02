#ifndef __DNA_DATA_H__
#define __DNA_DATA_H__

#include <sstream>
#include "dna_sequence.h"
#include <string>

class DnaMetaData
{
public:
	DnaMetaData(std::string name, DnaSequence* dna);
	const size_t getID() const {return m_id;}
	const std::string getName() const {return m_name;}
	DnaSequence* getDNA() const {return m_dna;}
	void setName(std::string name) {m_name = name;}
	void setId(size_t id) {m_id = id;}
	std::string stringFormat() const;
private:
	size_t getNextId();
	size_t m_id;
	std::string m_name;
	DnaSequence* m_dna;
};

inline DnaMetaData::DnaMetaData(std::string name, DnaSequence* dna)
:	m_id(getNextId()),
	m_name(name),
	m_dna(dna) {}

inline std::string DnaMetaData::stringFormat() const
{
	return "[" + std::to_string(m_id) + "] " + m_name + ": " + m_dna -> get();
}

inline size_t DnaMetaData::getNextId()
{
	static size_t nextId = 1;
	return nextId++;
}

class Data
{
public:
	const DnaMetaData* getSeq(std::string);
	std::size_t size() {return m_DNAs.size();}
	void setIdOfSeq(size_t index, size_t id);
	void insert(DnaMetaData);
	DnaMetaData& operator[](size_t index){return m_DNAs[index];}
private:
	const DnaMetaData* getDnaSequence(std::string name);
	const DnaMetaData* getDnaSequence(size_t id);
   	std::vector<DnaMetaData> m_DNAs;
};

inline const DnaMetaData* Data::getSeq(std::string seq)
{
	if(seq[0] == '@')
		return getDnaSequence(seq.substr(1));
	else return getDnaSequence(std::stoi(seq.substr(1)));
}

inline void Data::setIdOfSeq(size_t index, size_t id)
{
	m_DNAs[index].setId(id);
}

inline void Data::insert(DnaMetaData newDna)
{
	m_DNAs.push_back(newDna);
}

inline const DnaMetaData* Data::getDnaSequence(std::string name)
{
	for(size_t i = 0; i < m_DNAs.size(); i++)
		if(m_DNAs[i].getName() == name)
			return &m_DNAs[i];
	return NULL;
}

inline const DnaMetaData* Data::getDnaSequence(size_t id)
{
	for(size_t i = 0; i < m_DNAs.size(); i++)
		if(m_DNAs[i].getID() == id)
			return &m_DNAs[i];
	return NULL;
}

#endif
