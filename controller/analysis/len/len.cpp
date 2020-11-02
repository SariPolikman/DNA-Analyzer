#include "len.h"



void Len::set(std::string parameters)
{
    m_params = new LenParams(parameters);
}

std::string Len::execute(Data* data)
{
	return std::to_string(((data -> getSeq(dynamic_cast<LenParams *>(m_params)-> m_seq)) -> getDNA()) -> getLen());
}

