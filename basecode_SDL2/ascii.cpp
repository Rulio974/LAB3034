#include "ascii.h"

void StartPrint()
{

	std::ifstream file("data/startprint.txt");
	std::string line;
	if (!file.is_open())
	{
		std::cout << "ERREUR";
		system("exit");
	}

	while (std::getline(file, line))
		std::cout << line << "\n";
	file.close();

	std::cout << "\t\t\tJules & Florian\n";

}