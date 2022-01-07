#include "CRogue.h"
#include "team.h"

CRogue::CRogue()
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
	int m_damage;
	
}

CRogue::CRogue(std::string type, std::string name, int health,
	CWeapon weapon, float dodge,
	int speed, int attack, int defense,
	int agility, int intelligence, int damage, float poison) {

	m_type = type;
	m_name = name;
	m_health = health;
	m_weapon = m_weapon;
	m_dodge = dodge;
	m_speed = speed;
	m_attack = attack;
	m_defense = defense;
	m_agility = agility;
	m_intelligence = intelligence;
	m_damage = damage;
	m_poison = poison;

}

CRogue::~CRogue()
{

}

void CRogue::CalculAttack(int Adefense)
{
	srand(time(NULL));
	float coeff = float((rand() % (100 - 85) + 85)) / 100;
	printf("Coef : %f", coeff);
	m_damage = 7 * ((m_attack + m_weapon.m_damage) / Adefense) * coeff;

}

void CRogue::Action(int team, std::vector<CTeam>Teams)
{
	int action;
	std::cout << "Que voulez vous faire ?\n" << "[1]\tAttaquer\n" << "[2]\tHurler\n" << "[3]\tReparer\n";

	std::cin >> action;

	switch (action)
	{
	case 1:
		std::cout << "Pas encore disponible";

	case 2:
		std::cout << "Pas encore disponible";

	case 3:
		std::cout << "Pas encore disponible";

	}


}

void CRogue::ChooseWeapon(int team, std::vector <CWeapon> TabWeapons)
{

	int choose;
	std::cout << "\n\nQuelle arme voulez-vous ?\n";
	std::cout << "[1]\tGandiva\n[2]\tPerce-bourse\n[3]\tThori'dal\n[4]\tSorcelame\n";
	std::cin >> choose;

	switch (choose)
	{
	case 1:
		m_weapon = TabWeapons[2];
		break;
	case 2:
		m_weapon = TabWeapons[3];
		break;
	case 3:
		m_weapon = TabWeapons[5];
		break;
	case 4:
		m_weapon = TabWeapons[7];
		break;
	default:
		std::cout << "Cette arme n'existe pas ! Vous aurez Sorcelame\n";
		m_weapon = TabWeapons[7];
		break;

	}
}