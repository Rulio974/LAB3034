#include "CWeapon.h"

CWeapon::CWeapon()
{

	std::string m_name;
	int m_damage;
	float m_critical;
	float m_bonus;
	int m_durability;

}

CWeapon::CWeapon(std::string name, int damage, float critical, float bonus, int durability)
{
	m_name		=	name;
	m_damage	=	damage;
	m_critical	=	critical;
	m_bonus		=	bonus;
	m_durability = 0;

}

CWeapon::~CWeapon()
{

}

void CWeapon::Print()
{
	std::cout << " Nom " << m_name << " \n\tdegats" << m_damage << "\n\tcritique " << m_critical << "\n\tbonus " << m_bonus << "\n\n";

}

