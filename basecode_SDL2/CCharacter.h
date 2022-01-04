#pragma once
#include "utils.h"


class CCharacter
{
protected:

	std::string m_name;
	int			m_health;
	CWeapon		m_weapon;
	int			m_dodge;
	int			m_speed;
	int			m_attack;
	int			m_defense;
	int			m_agility;
	int			m_damage;
	int			m_intelligence;

	CCharacter();

public:

	CCharacter(std::string name, int health,
		CWeapon weapon, int dodge,
		int speed, int attack, int defense,
		int agility, int m_damage, int intelligence);

	virtual		~CCharacter();
	//virtual void attack();

	//TODO
	//Faire les actions

};