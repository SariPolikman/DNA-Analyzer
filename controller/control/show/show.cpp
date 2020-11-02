#include "show.h"
#include "show_params.h"

void Show::set(std::string parameters)
{
	m_params = new ShowParams(parameters);
}

std::string Show::execute(Data* data)
{
	ShowParams *showParams = dynamic_cast<ShowParams *>(m_params);
	//DnaMetaData* seq = data -> getSeq(showParams -> m_seq);
	return data -> getSeq(showParams -> m_seq) -> stringFormat();
}

