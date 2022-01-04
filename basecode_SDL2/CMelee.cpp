#pragma once
#include "CMelee.h"

CMelee::CMelee()
{
	std::string m_name;
	int m_damage;
	float m_critical;
	float m_bonus;
	int m_durability;
}

CMelee::CMelee(std::string name, int damage, int critical, int bonus, int durability)
{
	m_name			= name;
	m_damage		= damage;
	m_critical		= critical;
	m_bonus			= bonus;
	m_durability	= durability;
	

}

CMelee::~CMelee()
{

}

void CMelee::Print()
{
	std::cout << " Nom " << m_name << " \n\tdegats" << m_damage << "\n\tcritique " << m_critical << "\n\tbonus " << m_bonus << "\n\tdurability" << m_durability << "\n\n";

}
