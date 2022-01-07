#pragma once
#include "utils.h"
#include "CBow.h"

CBow::CBow()
{

	std::string m_name;
	int m_damage;
	int m_critical;
	int m_bonus;
	int m_consumable;
	int m_distance;

}

CBow::CBow(std::string name, int damage, int critical, int bonus, int consumable, int distance)
{

	m_name = name;
	m_damage = damage;
	m_critical = critical;
	m_bonus = bonus;
	m_consumable = consumable;
	m_distance = distance;

}

CBow::~CBow()
{

}