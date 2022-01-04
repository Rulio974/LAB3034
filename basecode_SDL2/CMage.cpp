#pragma once
#include "utils.h"

CMage::CMage()
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
	int m_damage;
	int m_mana;
}

CMage::CMage(std::string name, int health,
	CWeapon weapon, int dodge,
	int speed, int attack, int defense,
	int agility, int intelligence, int damage, int mana){

	std::string m_name = name;
	int m_health = health;
	CWeapon m_weapon = m_weapon;
	int m_dodge = dodge;
	int m_speed = speed;
	int m_attack = attack;
	int m_defense = defense;
	int m_agility = agility;
	int m_intelligence = intelligence;
	float m_damage = damage;
	int m_mana = mana;


}

CMage::~CMage()
{

}

void CMage::CalculAttack(int Adefense)
{
	srand(time(NULL));
	float coeff = float((rand() % (100 - 85) + 85)) / 100;
	printf("Coef : %f", coeff);
	m_damage = 7 * ((m_attack + m_weapon.m_damage) / Adefense) * coeff;

}