#pragma once
#include "utils.h"

class CParser
{
protected :
	std::string m_file;

	CParser();

public :
	CParser(std::string file);
	~CParser();

	std::ifstream	OpenFile();
	void			CloseFile(std::ifstream);
	void			ReadFile(std::ifstream);

};