#pragma once

#include "CWeapon.h"
#include "utils.h"

class CTeam;

class CCharacter
{

public:
	std::string m_type;
	std::string m_name;
	int			m_health;
	CWeapon		m_weapon;
	float		m_dodge;
	int			m_speed;
	int			m_attack;
	int			m_defense;
	int			m_agility;
	int			m_damage;
	int			m_intelligence;


	CCharacter();



	CCharacter(std::string type, std::string name, int health,
		CWeapon weapon, float dodge,
		int speed, int attack, int defense,
		int agility, int m_damage, int intelligence);

	virtual		~CCharacter();
	virtual void Action(int team, std::vector<CTeam> Teams) = 0;
	virtual void ChooseWeapon(int team, std::vector <CWeapon> TabWeapons) = 0;
	
	//virtual void CalculAttack() = 0;

	//TODO
	//Faire les actions

};