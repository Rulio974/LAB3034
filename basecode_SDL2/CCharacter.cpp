#pragma once
#include "utils.h"

CCharacter::CCharacter()
{
	std::string m_name;
	int			m_health;
	CWeapon   	m_weapon;
	float		m_dodge;
	int			m_speed;
	int			m_attack;
	int			m_defense;
	int			m_agility;
	int			m_damage;
	int			m_intelligence;

}

CCharacter::CCharacter(std::string name, int health,
	CWeapon weapon, float dodge,
	int speed, int attack, int defense,
	int agility, int damage,  int intelligence){

	m_name			= name;
	m_health		= health;
	m_weapon		= weapon;
	m_dodge			= dodge;
	m_speed			= speed;
	m_attack		= attack;
	m_defense		= defense;
	m_agility		= agility;
	m_damage		= damage;
	m_intelligence	= intelligence;



}

CCharacter::~CCharacter() {}