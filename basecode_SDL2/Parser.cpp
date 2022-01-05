#include "utils.h"

CParser::CParser()
{
	std::string m_file;

}

CParser::CParser(std::string file)
{
	m_file = file;
	
}

CParser::~CParser(){}

std::ifstream CParser::OpenFile()
{
	std::ifstream FILE(m_file);

	if (!FILE.is_open())
	{
		printf("ERREUR OUVERTURE FICHIER");
		system("exit");
	}

	return FILE;

}

void CParser::ReadFile(std::ifstream FILE)
{
	std::string line;
	getline(FILE, line);

}

void CParser::CloseFile(std::ifstream FILE)
{
	FILE.close();

}