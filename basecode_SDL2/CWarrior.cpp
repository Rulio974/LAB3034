#pragma once
#include "CWarrior.h"


CWarrior::CWarrior() 
{

	std::string m_name;
	int m_health;
	CWeapon m_weapon;
	int m_dodge;
	int m_speed;
	int m_attack;
	int m_defense;
	int m_agility;
	int m_intelligence;
	int m_parade;

}

CWarrior::CWarrior(std::string name, int health,
	CWeapon weapon, float dodge,
	int speed, int attack, int defense,
	int agility, int intelligence, int damage, int parade){

	m_name = name;
	m_health = health;
	m_weapon = m_weapon;
	m_dodge = dodge;
	m_speed = speed;
	m_attack = attack;
	m_defense = defense;
	m_agility = agility;
	m_intelligence = intelligence;
	m_damage = damage;
	m_parade = parade;

}

CWarrior::~CWarrior() {}

void CWarrior::CalculAttack(int Adefense)
{
	srand(time(NULL));
	float coeff = float(( rand() %( 100 - 85 ) + 85 ))/100 ;
	printf("Coef : %f", coeff);
	m_damage = 7 * ((m_attack + m_weapon.m_damage) / Adefense) * coeff;

}

