#pragma once
#include "CDagger.h"

CDagger::CDagger()
{
	std::string m_name;
	int m_damage;
	float m_critical;
	float m_bonus;
	int m_durability;

}

CDagger::CDagger(std::string name, int damage, int critical, int bonus, int durability)
{

	m_name	= name;
	m_damage		= damage;
	m_critical	= critical;
	m_bonus		= bonus;
	m_durability	= durability;


}

CDagger::~CDagger()
{

}

