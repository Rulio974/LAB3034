#pragma once
#include "utils.h"

class CWarrior : public CCharacter
{
protected :

	float	m_damage;
	float	m_parade;
			CWarrior();

public :

			CWarrior(std::string name, int health,
				CWeapon weapon, int dodge,
				int speed, int attack, int defense,
				int agility, int intelligence, int damage, int parade);

			~CWarrior();
	
	//void	Hurler();
	//void	Reparer();
	void	CalculAttack(int Adefense);


};