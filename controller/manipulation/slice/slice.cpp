#include "slice.h"

void Slice::set(std::string parameters)
{
	m_params = new SliceParams(parameters);
}


std::string Slice::execute(Data *data)
{
	DnaMetaData* DNA = const_cast<DnaMetaData *>(data -> getSeq(dynamic_cast<SliceParams *>(m_params) -> m_identSeq));
	DnaSequence d(DNA -> getDNA() -> slice(dynamic_cast<SliceParams *>(m_params) -> m_fromInd, dynamic_cast<SliceParams *>(m_params) -> m_toInd));
	(*(DNA -> getDNA())) = d;
	return DNA->stringFormat();
}
