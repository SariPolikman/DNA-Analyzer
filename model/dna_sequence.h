#ifndef __DNA_SEQUENC_H__
#define __DNA_SEQUENC_H__

#include <cstring> /*for strlen, strcpy and strcmp*/
#include <string> /*for string*/
#include <iostream> /*for operator ostream*/
#include <fstream> /*for ofstream*/
#include <vector> /*for vector in findAll*/


class invalid_nucleotide : public std::invalid_argument
{
public:
	explicit invalid_nucleotide(const char* message) : invalid_argument(message) {}
	explicit invalid_nucleotide(const std::string& message) : invalid_argument(message) {}
	virtual ~invalid_nucleotide() throw () {}
	virtual const char* what() const throw () {
		return msg_.c_str();
	}
protected:
	std::string msg_;
};


class DnaSequence
{
private:
	class Nucleotide
	{
	public:
		Nucleotide();
		Nucleotide(char nuc);
		Nucleotide operator=(char nuc);
		char get() const {return m_nuc;}
		bool operator!=(Nucleotide nuc) const;
		bool operator==(Nucleotide nuc) const;
		operator char() {return m_nuc;}
		Nucleotide find_pair();
		friend std::ostream& operator<<(std::ostream& print_obj, const DnaSequence::Nucleotide& nuc);
	private:
		bool isValidNucleotide(char nuc);
		char m_nuc;
	};
	Nucleotide* m_sequence;
public:
	DnaSequence();
	DnaSequence(const char* sequence);
	DnaSequence(std::string& sequence);
	DnaSequence(const DnaSequence& dna);
	~DnaSequence();
	DnaSequence operator=(const DnaSequence& dna);
	DnaSequence operator=(const char* sequence);
	DnaSequence operator=(const std::string& sequence);
	Nucleotide& operator[](std::size_t index);
	Nucleotide const& operator[](std::size_t index) const;
	std::string get() const;
	bool operator==(const DnaSequence& dna) const;
	bool operator!=(const DnaSequence& dna) const;
	std::size_t getLen() const;
	void writeToFile(const char *path) const;
	DnaSequence slice(std::size_t start, std::size_t end) const;
	DnaSequence pairing() const ;
	size_t find(DnaSequence const& sub);
	size_t count(DnaSequence const& sub);
	std::vector<size_t> findAll(DnaSequence const& sub);
	std::vector<DnaSequence> findConsSeq();
	friend std::ostream& operator<<(std::ostream& print_obj, const DnaSequence& dna);
	friend std::ostream& operator<<(std::ostream& print_obj, const DnaSequence::Nucleotide& nuc);

};


inline DnaSequence::Nucleotide::Nucleotide() {}

inline DnaSequence::Nucleotide::Nucleotide(char nuc) : m_nuc(nuc)
{
	if(isValidNucleotide(nuc) == 0)
	{
		throw invalid_nucleotide("it is not a nucleotide");
	}
}

inline DnaSequence::Nucleotide DnaSequence::Nucleotide::operator=(char nuc)
{
	if(isValidNucleotide(nuc) == 0)
	{
		throw invalid_nucleotide("it is not a nucleotide");
	}
	if(nuc != '\0')
	{
		m_nuc = nuc;
	}
	return *this;
}

inline bool DnaSequence::Nucleotide::operator!=(DnaSequence::Nucleotide nuc) const
{
	return !(m_nuc == nuc.m_nuc);
}

inline bool DnaSequence::Nucleotide::operator==(DnaSequence::Nucleotide nuc) const
{
	return m_nuc == nuc.m_nuc;
}

inline bool DnaSequence::Nucleotide::isValidNucleotide(char nuc)
{
	return nuc == 'A' || nuc == 'T' || nuc == 'C' || nuc == 'G' || nuc == '\0';
}

inline std::ostream& operator<<(std::ostream& print_obj, const DnaSequence::Nucleotide& nuc)
{
	print_obj << nuc.m_nuc;
	return print_obj;
}


inline DnaSequence::DnaSequence() : m_sequence(NULL) {}

inline DnaSequence::DnaSequence(const char* sequence) : m_sequence(NULL)
{
	try {
		m_sequence = new DnaSequence::Nucleotide[strlen(sequence) + 1];
		for (std::size_t i = 0; i <= strlen(sequence); i++)
		{
			m_sequence[i] = sequence[i];
		}
		m_sequence[strlen(sequence)] = '\0';
	}

	catch(invalid_nucleotide& ex)
	{
		delete[] m_sequence;
		throw;
	}
}

inline DnaSequence::DnaSequence(std::string& sequence) : m_sequence(NULL)
{
	try {
		const char *seq = sequence.c_str();
		m_sequence = new DnaSequence::Nucleotide[strlen(seq) + 1];
		for (std::size_t i = 0; i <= strlen(seq); i++)
		{
			m_sequence[i] = seq[i];
		}
		m_sequence[strlen(seq)] = '\0';
	}

	catch(invalid_nucleotide& ex)
	{
		delete[] m_sequence;
		throw;
	}
}

inline DnaSequence::DnaSequence(const DnaSequence& dna) : m_sequence(NULL)
{
	m_sequence = new DnaSequence::Nucleotide[dna.getLen() + 1];
	for (std::size_t i = 0; i <= dna.getLen(); i++)
	{
		m_sequence[i] = dna.m_sequence[i];
	}
	m_sequence[dna.getLen()] = '\0';
}

inline DnaSequence DnaSequence::operator=(const DnaSequence& dna)
{
	DnaSequence::Nucleotide* sequence = new DnaSequence::Nucleotide[dna.getLen() + 1];
	for (std::size_t i = 0; i <= dna.getLen(); i++)
	{
		sequence[i] = dna.m_sequence[i];
	}
	delete[] m_sequence;
	m_sequence = sequence;
	return *this;
}

inline DnaSequence DnaSequence::operator=(const char* sequence)
{
	try {
		DnaSequence::Nucleotide* sequence_pointer = new DnaSequence::Nucleotide[strlen(sequence) + 1];
		delete[] m_sequence;
		for (std::size_t i = 0; i <= strlen(sequence); i++)
		{
			sequence_pointer[i] = sequence[i];
		}
		m_sequence = sequence_pointer;
	}
	catch(invalid_nucleotide& ex)
	{
		delete[] m_sequence;
		throw;
	}
	return *this;
}

inline DnaSequence DnaSequence::operator=(const std::string& sequence)
{
	try {
		DnaSequence::Nucleotide* sequence_pointer = new DnaSequence::Nucleotide[strlen(sequence.c_str()) + 1];
		delete[] m_sequence;
		for (std::size_t i = 0; i <= strlen(sequence.c_str()); i++)
		{
			sequence_pointer[i] = sequence.c_str()[i];
		}
		m_sequence = sequence_pointer;
	}
	catch(invalid_nucleotide& ex)
	{
		delete[] m_sequence;
		throw;
	}
	return *this;
}

inline DnaSequence::Nucleotide& DnaSequence::operator[](std::size_t index)
{
	return m_sequence[index];
}


inline DnaSequence::Nucleotide const& DnaSequence::operator[](std::size_t index) const
{
	return m_sequence[index];
}

inline std::string DnaSequence::get() const
{
	std::string seq = "";
	for(size_t i = 0; i < getLen(); i++)
		seq += m_sequence[i].get();
	return seq;
}

inline std::size_t DnaSequence::getLen() const
{
	size_t ret_len;
	for(ret_len = 0; m_sequence[ret_len]; ret_len++); 
	return ret_len;
}

inline bool DnaSequence::operator==(const DnaSequence& dna) const
{
	if(getLen() != dna.getLen())
		return false;
	for(size_t i = 0; i < getLen(); i++)
	{
		if(m_sequence[i] != dna[i])
			return false;
	}
	return true;
}

inline void DnaSequence::writeToFile(const char *path) const
{
	std::ofstream file;
	file.open(path);
	file << *this;
	file.close();
}

inline DnaSequence readFromFile(std::string path)
{
	std::size_t file_size;
	std::ifstream in(path, std::ifstream::ate | std::ifstream::binary);
	file_size = in.tellg();
	file_size -=3;
	std::ifstream file;
	file.open(path);
	char* input = new char[file_size];

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> input;
		}
	}

	file.close();
	input[file_size] = '\0';
	DnaSequence d(input);
	delete[] input;

	return d;
}

inline DnaSequence DnaSequence::slice(std::size_t start, std::size_t end) const
{
	char* seq_pointer = new char[end - start];
	for(std::size_t i = start + 1; i < end; i++)
	{
		seq_pointer[i - start - 1] = m_sequence[i];
	}
	seq_pointer[end - start - 1] = '\0';
	DnaSequence dna(seq_pointer);
	delete[] seq_pointer;
	return dna;
}

inline DnaSequence::Nucleotide DnaSequence::Nucleotide::find_pair()
{
	switch(m_nuc)
	{
		case 'A':
			return 'T';
		case 'T':
			return 'A';
		case 'C':
			return 'G';
		case 'G':
			return 'C';
		default:
			return '\0';
	}
}

inline DnaSequence DnaSequence::pairing() const
{
	char *seq = new char[getLen() + 1];
	for(size_t i = 0; i < getLen(); i++)
	{
		seq[getLen() - i - 1] = m_sequence[i].find_pair();
	}
	seq[getLen()] = '\0';
	DnaSequence dna(seq);
	delete[] seq;
	
	return dna;
}
//TACCTAG
inline size_t DnaSequence::find(DnaSequence const& sub)
{
	size_t j;
	for(size_t i = 0; i < getLen(); i++)
		if(m_sequence[i] == sub[0])
		{
			for(j = 0; j < sub.getLen(); j++)
				if(m_sequence[i+j] != sub[j])
					break;
			if(sub.getLen() == j)
				return i;
		}
	return 5322338;
}

inline size_t DnaSequence::count(DnaSequence const& sub)
{
	return findAll(sub).size();
}

inline std::vector<size_t> DnaSequence::findAll(DnaSequence const& sub)
{
	std::vector<size_t> found_indexes;
	size_t j;
	for(size_t index = 0; index < getLen(); index++)
		if(m_sequence[index] == sub[0])
		{
			for(j = 0; j < sub.getLen(); j++)
				if(m_sequence[index+j] != sub[j])
					break;
			if(sub.getLen() == j)
				found_indexes.push_back(index);
		}
	return found_indexes;
}

inline std::vector<DnaSequence> DnaSequence::findConsSeq()
{
	std::vector<DnaSequence> ret_vect;
	DnaSequence start_codon("ATG"), end_codon1("TAG"), end_codon2("TAA"), end_codon3("TGA");
	std::vector<size_t> all_start_codon = findAll(start_codon);
	
	for(size_t i = 0; i < all_start_codon.size(); i++)
	{
		for(size_t j = all_start_codon[i] - 1; j < getLen(); j += 3)
		{
			DnaSequence temp_codon = slice(j, j + 4);
			if(temp_codon == end_codon1 || temp_codon == end_codon1 || temp_codon == end_codon1)
				ret_vect.push_back(slice(all_start_codon[i] - 1, j + 4));
		}
	}
	return ret_vect;
}

inline DnaSequence::~DnaSequence()
{
	delete[] m_sequence;
}


inline std::ostream& operator<<(std::ostream& print_obj, const DnaSequence& dna)
{
	for (std::size_t i = 0; i < dna.getLen(); i++)
	{
		print_obj << dna.m_sequence[i];
	}
	return print_obj;
}

inline bool DnaSequence::operator!=(const DnaSequence& dna) const
{
	return !(*this == dna);
}

#endif
