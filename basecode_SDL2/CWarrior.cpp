#pragma once
#include "CWarrior.h"
#include "team.h"


CWarrior::CWarrior() 
{
	std::string m_type;
	std::string m_name;
	int m_health;
	CWeapon m_weapon;
	int m_dodge;
	int m_speed;
	int m_attack;
	int m_defense;
	int m_agility;
	int m_intelligence;
	int m_parade;
	

}

CWarrior::CWarrior(std::string type, std::string name, int health,
	CWeapon weapon, float dodge,
	int speed, int attack, int defense,
	int agility, int intelligence, int damage, int parade){

	m_type = type;
	m_name = name;
	m_health = health;
	m_weapon = weapon;
	m_dodge = dodge;
	m_speed = speed;
	m_attack = attack;
	m_defense = defense;
	m_agility = agility;
	m_intelligence = intelligence;
	m_damage = damage;
	m_parade = parade;
	

}

CWarrior::~CWarrior() {}

void CWarrior::CalculAttack(int Adefense)
{
	srand(time(NULL));
	float coeff = float(( rand() %( 100 - 85 ) + 85 ))/100 ;
	m_damage = float(7 * ((m_attack + m_weapon.m_damage) / Adefense) * coeff);

}

void CWarrior::Attack(int team, std::vector<CTeam>Teams)
{
	srand(time(NULL));
	int choose;
	float esquive = float((rand() % 100))/100;
	std::cout << "Qui voulez vous attaquer ?";

		std::cout << "\n[1]\t" << Teams[(team + 1) % 1].m_perso1->m_name;
		std::cout << "\n[2]\t" << Teams[(team + 1) % 1].m_perso2->m_name;
		std::cout << "\n[3]\t" << Teams[(team + 1) % 1].m_perso3->m_name << "\n";
	
		std::cin >> choose;


		switch (choose)
		{
		case 1 :

			if (esquive > Teams[(team + 1) % 1].m_perso1->m_dodge)
				std::cout << Teams[(team + 1) % 1].m_perso1->m_name << " a esquive !\n";
				
			else
			{
				CalculAttack(Teams[(team + 1) % 1].m_perso1->m_defense);
				Teams[(team + 1) % 1].m_perso1->m_health -= m_attack * m_damage;
				m_weapon.m_durability -= 1;
				std::cout << "J'ai attaque chef !";
			}
			break;

		case 2:

			if (esquive > Teams[(team + 1) % 1].m_perso2->m_dodge)
				std::cout << Teams[(team + 1) % 1].m_perso2->m_name << " a esquive !\n";

			else
			{
				CalculAttack(Teams[(team + 1) % 1].m_perso2->m_defense);
				Teams[(team + 1) % 1].m_perso2->m_health -= m_attack * m_damage;
				m_weapon.m_durability -= 1;
				std::cout << "J'ai attaque chef !";
			}
			break;

		case 3:

			if (esquive > Teams[(team + 1) % 1].m_perso2->m_dodge)
				std::cout << Teams[(team + 1) % 1].m_perso2->m_name << " a esquive !\n";

			else
			{
				CalculAttack(Teams[(team + 1) % 1].m_perso2->m_defense);
				Teams[(team + 1) % 1].m_perso2->m_health -= m_attack * m_damage;
				m_weapon.m_durability -= 1;
				std::cout << "J'ai attaque chef !";
			}
			break;

		default:
			std::cout << "Oups, j'ai trop bu, j'ai fais tomber mon arme...";
		}




}

void CWarrior::Action(int team, std::vector<CTeam>Teams)
{

	int action;
	std::cout << "\nQue voulez vous faire ?\n" << "[1]\tAttaquer\n" << "[2]\tHurler\n" << "[3]\tReparer\n";
	
	std::cin >> action;

	switch (action)
	{
	case 1:
		Attack(team, Teams);
		break;

	case 2:
		std::cout << "Pas encore disponible";
		break;

	case 3:
		Reparer(team, Teams);
		break;
	default:
		break;
		

	}


}

void CWarrior::Reparer(int team, std::vector<CTeam>Teams)
{
	srand(time(NULL));

	int wea;
	std::cout << "Quelle arme souhaitez vous reparer ?";
	Teams[team].Print();
	
	std::cin >> wea;
	switch (wea) {

	case 1 : 
		if (Teams[team].m_perso1->m_weapon.m_durability < 0)
			Teams[team].m_perso1->m_weapon.m_durability = 1;
		else {
			Teams[team].m_perso1->m_weapon.m_durability = (rand() % (15 + 1 - 3)) + 3;
		}
		std::cout << "Arme reparee : " << Teams[team].m_perso1->m_weapon.m_durability;
		break;

	case 2:
		if (Teams[team].m_perso2->m_weapon.m_durability < 0)
			Teams[team].m_perso2->m_weapon.m_durability = 1;
		else
			Teams[team].m_perso2->m_weapon.m_durability = (rand() % (3 - 15 + 1)) + 3;

		std::cout << "Arme reparee : " << Teams[team].m_perso1->m_weapon.m_durability;
		break;

	case 3:
		if (Teams[team].m_perso3->m_weapon.m_durability < 0)
			Teams[team].m_perso3->m_weapon.m_durability = 1;
		else
			Teams[team].m_perso3->m_weapon.m_durability = (rand() % (3 - 15 + 1)) + 3;

		std::cout << "Arme reparee : " << Teams[team].m_perso1->m_weapon.m_durability;
		break;
	}




}

void CWarrior::ChooseWeapon(int team, std::vector <CWeapon> TabWeapons)
{

	int choose;
	std::cout << "\n\nQuelle arme voulez-vous ?\n";
	std::cout << "[1]\tExcalibur\n[2]\tPerce-bourse\n[3]\tPorte-cendre\n[4]\tSorcelame\n";
	std::cin >> choose;

	switch (choose)
	{
	case 1:
		m_weapon = TabWeapons[1];
		break;
	case 2:
		m_weapon = TabWeapons[3];
		break;
	case 3:
		m_weapon = TabWeapons[4];
		break;
	case 4:
		m_weapon = TabWeapons[7];
		break;
	default:
		std::cout << "Cette arme n'existe pas ! Vous aurez Excalibur\n";
		m_weapon = TabWeapons[1];
		break;

	}

}
