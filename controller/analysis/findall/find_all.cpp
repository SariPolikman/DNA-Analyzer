#include "find_all.h"

#include "findall_params.h"

void FindAll::set(std::string parameters)
{
	m_params = new FindAllParams(parameters);
}

std::string FindAll::execute(Data* data)
{
    FindAllParams *findAllParams = dynamic_cast<FindAllParams *>(m_params);
	DnaSequence d;
	if(findAllParams -> m_subSeq[0] == '@' || findAllParams -> m_subSeq[0] == '#')
	{
		d = *(data -> getSeq(findAllParams -> m_subSeq)) -> getDNA();
	}
	else d = DnaSequence(findAllParams -> m_subSeq);
	
	std::vector<size_t> allFound = ((data -> getSeq(findAllParams -> m_seq)) -> getDNA()) -> findAll(d);
	std::string res;
	for(size_t i = 0; i < allFound.size(); i++)
	{
		res += std::to_string(allFound[i]) + " ";
	}
	return res;
}

