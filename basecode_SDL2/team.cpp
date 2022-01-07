#include "utils.h"
#include "team.h"

CTeam::CTeam()
{
	int m_num;
	std::string m_name;
	CCharacter *m_perso1;
	CCharacter *m_perso2;
	CCharacter *m_perso3;
}

CTeam::~CTeam(){}


CTeam::CTeam(int num, std::string name, CCharacter* perso1, CCharacter* perso2, CCharacter* perso3) 
{
	m_num		= num;
	m_name		= name;
	m_perso1	= perso1;
	m_perso2	= perso2;
	m_perso3	= perso3;


}

CTeam* CTeam::CreateTeam(int num, std::vector<CCharacter*> TabCaracters, std::vector<CWeapon> TabWeapons)
{
	int index;

	sTeam team1;

	m_num = num;
	std::cout << "\nTeam numero " << m_num << "\nVotre nom ? \n";
	std::cin >> m_name;
	std::cout << "Bonjour" << " " << m_name;
	std::cout <<"\n\n" << "Liste des personnages\n\n";
	for (int i = 0; i < TabCaracters.size(); i++)
		std::cout << "[" << i << "]\t" << TabCaracters[i]->m_name << "\n";

	std::cout << "\nQuel est votre premier perso ? (numero)\n";
	std::cin >> index;

	if (index > TabCaracters.size())
	{
		while (index > TabCaracters.size())
		{
			std::cout << "\nCe perso n'existe pas !\n";
			std::cout << "\nQuel est votre premier perso ? (numero)\n";
			std::cin >> index;
		}
	}

	std::cout << "\nPerso 1 : " << TabCaracters[index]->m_name;
	team1.s_perso1 = TabCaracters[index];
	team1.s_perso1->ChooseWeapon(num, TabWeapons);

	std::cout << "\nLe deuxieme ? (numero)\n";
	std::cin >> index;
	if (index > TabCaracters.size())
	{
		while (index > TabCaracters.size())
		{
			std::cout << "\nLe deuxieme ? (numero)\n";
			std::cin >> index;
		}
	}
	std::cout << "\nPerso 2 : " << TabCaracters[index]->m_name;
	team1.s_perso2 = TabCaracters[index];
	team1.s_perso2->ChooseWeapon(num, TabWeapons);


	std::cout << "\nLe dernier ? (numero)\n";
	std::cin >> index;
	if (index > TabCaracters.size())
	{
		while (index > TabCaracters.size())
		{
			std::cout << "\nLe dernier ? (numero)\n";
			std::cin >> index;
		}
	}

	std::cout << "\nPerso 3 : " << TabCaracters[index]->m_name;
	team1.s_perso3 = TabCaracters[index];
	team1.s_perso3->ChooseWeapon(num, TabWeapons);


	m_perso1 = team1.s_perso1;
	m_perso2 = team1.s_perso2;
	m_perso3 = team1.s_perso3;

	std::cout << "Votre Team " << m_name <<" a ete cree avec les persos suivants : \n" << m_perso1->m_name << "\n" << m_perso2->m_name << "\n" << m_perso3->m_name;

	return 0;

}



void CTeam::Print() {

	std::cout << "\n[1]" << m_perso1->m_name << "\n[2]" << m_perso2->m_name << "\n[3]" << m_perso3->m_name;
	

}