#include "find.h"

#include "find_params.h"

void Find::set(std::string parameters)
{
    m_params = new FindParams(parameters);
}

std::string Find::execute(Data* data)
{
    FindParams *findParams = dynamic_cast<FindParams *> (m_params);
	DnaSequence d;
	if(findParams -> m_subSeq[0] == '@' || findParams -> m_subSeq[0] == '#')
	{
		d = *(data -> getSeq(findParams -> m_subSeq)) -> getDNA();
	}
	else d = DnaSequence(findParams -> m_subSeq);
	return std::to_string(((data -> getSeq(findParams -> m_seq)) -> getDNA()) -> find(d));
}

