#pragma once
#include "CRanged.h"

CRanged::CRanged()
{

	std::string m_name;
	int m_damage;
	int m_critical;
	int m_bonus;
	int m_consumable;
	int m_distance;

}

CRanged::CRanged(std::string name, int damage, int critical, int bonus, int consumable, int distance)
{

	std::string m_name = name;
	int m_damage = damage;
	int m_critical = critical;
	int m_bonus = bonus;
	int m_consumable = consumable;
	int m_distance = distance;

}

CRanged::~CRanged()
{

}