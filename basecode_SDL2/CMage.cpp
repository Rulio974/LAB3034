#pragma once
#include "CMage.h"
#include "team.h"

CMage::CMage()
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
	int m_mana;
}

CMage::CMage(std::string type, std::string name, int health,
	CWeapon weapon, float dodge,
	int speed, int attack, int defense,
	int agility, int intelligence, int damage, int mana){

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
	m_mana = mana;


}

CMage::~CMage()
{

}

void CMage::CalculAttack(int Adefense)
{
	srand(time(NULL));
	float coeff = float((rand() % (100 - 85) + 85)) / 100;
	printf("Coef : %f", coeff);
	m_damage = 7 * ((m_attack + m_weapon.m_damage) / Adefense) * coeff;

}

void CMage::Action(int team, std::vector<CTeam>Teams)
{

	int action;
	std::cout << "Que voulez vous faire ?\n" << "[1]\tAttaquer\n" << "[2]\tRegenerer mana\n" << "[3]\tSoigner\n" << "[4]\tEnchanter\n";

	std::cin >> action;

	switch (action)
	{
	case 1:
		std::cout << "Pas encore disponible";
		break;

	case 2:
		std::cout << "Pas encore disponible";
		break;

	case 3:
		std::cout << "Pas encore disponible";
		break;
	case 4:
		std::cout << "Pas encore disponible";
		break;

	default:
		break;

	}
	return;

}

void CMage::ChooseWeapon(int team, std::vector <CWeapon> TabWeapons)
{
	
	int choose;
	std::cout << "\n\nQuelle arme voulez-vous ?\n";
	std::cout << "[1]\tBaguette de Sureau\n[2]\tExcalibur\n[3]\tPorte-cendre\n[4]\tAtiesh\n";
	std::cin >> choose;

	switch (choose)
	{
	case 1:
		m_weapon = TabWeapons[0];
		break;
	case 2:
		m_weapon = TabWeapons[1];
		break;
	case 3:
		m_weapon = TabWeapons[4];
		break;
	case 4:
		m_weapon = TabWeapons[6];
		break;
	default:
		std::cout << "Cette arme n'existe pas ! Vous aurez Atiesh\n";
		m_weapon = TabWeapons[6];
		break;

	}

}