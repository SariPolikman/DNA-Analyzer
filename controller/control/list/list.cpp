#include "list.h"
#include "list_params.h"
#include "../../../model/dna_sequence.h"
#include "../../../model/dna_data.h"


std::string List::execute(Data* data)
{
	std::string listAsStr = "";
	for(size_t i = 0; i < data -> size(); i++)
	{
		listAsStr += (*data)[i].stringFormat();
		if(i != data -> size() - 1)
			listAsStr += "\n";
	}
	return listAsStr;
}

