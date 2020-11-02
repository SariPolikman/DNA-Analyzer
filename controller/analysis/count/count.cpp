#include "count.h"

#include "count_params.h"

void Count::set(std::string parameters)
{
	m_params = new CountParams(parameters);
}

std::string Count::execute(Data* data)
{
    CountParams * countParams = dynamic_cast<CountParams *>(m_params);
	DnaSequence d;
	if(countParams -> m_subSeq[0] == '@' || countParams -> m_subSeq[0] == '#')
	{
		d = *(data -> getSeq(countParams -> m_subSeq)) -> getDNA();
	}
	else d = DnaSequence(countParams -> m_subSeq);
	return std::to_string(((data -> getSeq(countParams -> m_seq)) -> getDNA()) -> count(d));
}

