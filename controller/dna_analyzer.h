#ifndef __DNA_ANALYZER_PROJECT_H__
#define __DNA_ANALYZER_PROJECT_H__


#include <cstddef>
#include <string>
#include <sstream>

#include "Icomand.h"
#include "../view/IIO.h"
#include "factory.h"
#include "../pop_first_word.h"

class DnaAnalyzerProject
{

public:
	DnaAnalyzerProject(IIO* io);
	void run();
	void commandHandler();
private:
	IIO*  m_io;
	Data* m_dnaSequences;
};

inline DnaAnalyzerProject::DnaAnalyzerProject(IIO* io)
:	m_io(io),
	m_dnaSequences(new Data()) {}

inline void DnaAnalyzerProject::run()
{
	while(true)
        try {
            commandHandler();
        }

        catch (Factory::InvalidFactory &e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::invalid_argument &e) {std::cout <<"popp";}
}

inline void DnaAnalyzerProject::commandHandler()
{

	std::string input = m_io -> getInput();

    std::string command = popFirstWord(input);
    if (command.empty())
        throw std::invalid_argument("double enter");

	Exec* action = Factory::instance().create_object(command);

	action->set(input);

    std::string stringFormat = action -> execute(m_dnaSequences);

	m_io -> printOutput(stringFormat);
}

#endif
