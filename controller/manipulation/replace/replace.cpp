#include "replace.h"
#include "replace_params.h"

void Replace::set(std::string parameters)
{
	m_params = new ReplaceParams(parameters);
}

std::string Replace::execute(Data* data)
{
	DnaMetaData* DNA = const_cast<DnaMetaData *>(data -> getSeq(dynamic_cast<ReplaceParams *>(m_params) ->m_seq));
	DnaSequence d(*(DNA -> getDNA()));
	d[stoi(dynamic_cast<ReplaceParams *>(m_params) ->m_index)] = dynamic_cast<ReplaceParams *>(m_params) ->m_newLetter;
	(*(DNA -> getDNA())) = d;
	return DNA->stringFormat();
}
