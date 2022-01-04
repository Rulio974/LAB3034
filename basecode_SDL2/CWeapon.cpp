#include "CWeapon.h"

CWeapon::CWeapon()
{
	std::string m_name;
	int m_damage;
	float m_critical;
	float m_bonus;

}

CWeapon::CWeapon(std::string name, int damage, float critical, float bonus)
{
	m_name		=	name;
	m_damage	=	damage;
	m_critical	=	critical;
	m_bonus		=	bonus;

}

CWeapon::~CWeapon()
{

}

void CWeapon::Print()
{
	std::cout << " Nom " << m_name << " \n\tdegats" << m_damage << "\n\tcritique " << m_critical << "\n\tbonus " << m_bonus << "\n\n";

}

