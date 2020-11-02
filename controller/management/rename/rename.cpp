#include "rename.h"

void Rename::set(std::string parameters)
{
    m_params = new RenameParams(parameters);
}

std::string Rename::execute(Data* data)
{
	DnaMetaData* DNA = const_cast<DnaMetaData *>(data -> getSeq(dynamic_cast<RenameParams *>(m_params) -> m_seq));
	DNA -> setName(dynamic_cast<RenameParams *>(m_params) -> m_newName);
	return DNA->stringFormat();
}

