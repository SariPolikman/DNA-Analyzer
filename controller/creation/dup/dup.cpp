#include "dup.h"
#include "dup_params.h"

void Dup::set(std::string parameters)
{
    m_params = new DupParams(parameters);
}

std::string Dup::execute(Data* data)
{
    DupParams *dupParams = dynamic_cast<DupParams *>(m_params);
    DnaSequence* newSeq = new DnaSequence(*(data -> getSeq(dupParams -> m_oldSeq) -> getDNA()));
    DnaMetaData newDna = DnaMetaData(dupParams -> m_newSeqName, newSeq);
    data->insert(newDna);
    return newDna.stringFormat();
}

