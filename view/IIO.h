#ifndef __IIO_H__
#define __IIO_H__
#include <string.h>
#include <sstream>
#include <iostream>


class IIO
{
public:
	virtual std::string getInput() = 0;
	virtual void printOutput(std::string) = 0;
};

class CLI : public IIO
{
public:
	std::string getInput();
	void printOutput(std::string output);
};
/*
class Files : IIO
{
	std::string getInput();
	void printOutput(std::string output);
};
*/
inline std::string CLI::getInput()
{
	std::cout << "> cmd >>> " ;
	std::string command;
	getline(std::cin, command);
	return command;
}

inline void CLI::printOutput(std::string output)
{
	std::cout << output << std::endl;
}
#endif
