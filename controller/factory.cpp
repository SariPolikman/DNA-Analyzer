#include "factory.h"

#include "creation/new/command.h"
#include "creation/load/command.h"
#include "creation/dup/dup.h"
#include "manipulation/replace/replace.h"
#include "manipulation/slice/slice.h"
#include "manipulation/pair/pair.h"
#include "management/rename/rename.h"
#include "management/save/save.h"
#include "analysis/len/len.h"
#include "analysis/count/count.h"
#include "analysis/find/find.h"
#include "analysis/findall/find_all.h"
#include "management/reenum/reenum.h"
#include "control/list/list.h"
#include "control/show/show.h"



void register_prototypes()
{
	Factory::instance().add_proto("dup"    ,new Dup);
	Factory::instance().add_proto("new"    ,new New);
	Factory::instance().add_proto("load"   ,new Load);
	Factory::instance().add_proto("slice"  ,new Slice);
	Factory::instance().add_proto("replace",new Replace);
	Factory::instance().add_proto("pair"   ,new Pair);
	Factory::instance().add_proto("rename" ,new Rename);
	Factory::instance().add_proto("save"   ,new Save);
	Factory::instance().add_proto("len"    ,new Len);
	Factory::instance().add_proto("count"  ,new Count);
	Factory::instance().add_proto("find"   ,new Find);
	Factory::instance().add_proto("findall",new FindAll);
	Factory::instance().add_proto("reenum" ,new Reenum);
	Factory::instance().add_proto("list"	,new List);
	Factory::instance().add_proto("show"	,new Show);
}

Factory& Factory::instance()   // singleton access method
{
	static Factory factory;
	return factory;
}





