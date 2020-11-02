#include <iostream>
#include "pop_first_word.h"

//std::string removeMultipleSpaces(std::string str)
//{
//	for(size_t i = str.size()-1; i >= 0; i-- )
//	{
//		if(str[i] == ' ' && str[i] == str[i-1])
//		{
//			str.erase(str.begin() + i);
//		}
//	}
//	return str;
//}

std::string popFirstWord(std::string& s)
{
//	s = removeMultipleSpaces(s);
	size_t spacePos = s.find(" ");
	std::string firstWord = s.substr(0, spacePos);
	if (spacePos != std::string::npos)
		s = s.substr(spacePos + 1);
	else s = "";
	return firstWord;
}
