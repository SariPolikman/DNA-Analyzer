#ifndef __MAP_H__
#define __MAP_H__


#include <string>
#include <map>

#include "Icomand.h"


void register_prototypes();

class Factory /*singleton*/
{
public:
//    void add(const Exec &e) {m_prototypes[e.get_type()] = e;}
    Exec* create_object(const std::string &type);

    void add_proto(const std::string exe, const Exec *e);
    static Factory& instance() ;

    struct InvalidFactory: public std::runtime_error
    {
    public:
        InvalidFactory(const char* what) : runtime_error(what) {}
    };

protected:
    void valid(const std::string &type);
    Factory() {}
    Factory(const Factory &);
    ~Factory() {
//        for(std::map<const std::string, const Exec &>::iterator i=
//                m_prototypes.begin(); i != m_prototypes.end(); i++)
//            delete i->second;
    }
private:
    std::map<const std::string, const Exec *> m_prototypes;
};

inline void Factory::add_proto(const std::string exe,const Exec *e)
{
    m_prototypes.insert ( std::pair <const std::string , const Exec *> (exe ,e) );
}

inline void Factory::valid(const std::string &type)
{
    if(m_prototypes.count(type)==0)
        throw InvalidFactory("command not found.  see 'help'.");
}

inline Exec* Factory::create_object(const std::string &type)
{
    valid(type);
    return m_prototypes[type]->clone();
}
#endif
