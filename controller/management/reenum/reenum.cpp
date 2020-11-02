#include "reenum.h"
#include "reenum_params.h"
#include "../../../model/dna_sequence.h"


std::string Reenum::execute(Data* data)
{
	for(size_t i = 0; i < data -> size(); i++)
	{
		data -> setIdOfSeq(i, i);
	}
	return "reenumed.";
}

