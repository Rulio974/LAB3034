#pragma once 
#include "CSword.h"

CSword::CSword()
{
	std::string m_name;
	int m_damage;
	float m_critical;
	float m_bonus;
	int m_durability;

}

CSword::CSword(std::string name, int damage, int critical, int bonus, int durability)
{
	std::string m_name = name;
	int m_damage = damage;
	float m_critical = critical;
	float m_bonus = bonus;
	int m_durability = durability;

}

CSword::~CSword()
{


}