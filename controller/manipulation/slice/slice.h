#ifndef ANALYZE_SLICE_H
#define ANALYZE_SLICE_H


#include <string>
#include "../../Icomand.h"
#include "slice_params.h"

class Slice : public Exec{
public:
	Slice() {}
	void set(std::string parameters);
	/*virtual*/ std::string execute(Data *data);
	Exec* clone() const { return new Slice(*this); }
	std::string get_type() const { return "Slice";}

};






#endif //ANALYZE_SLICE_H
