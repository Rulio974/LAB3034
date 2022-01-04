#pragma once
#include "utils.h"

class CArcher : public CCharacter
{
protected :
	CArcher();

public :
	CArcher(std::string name, int health,
		CWeapon weapon, int dodge,
		int speed, int attack, int defense,
		int agility, int m_damage, int intelligence);

	~CArcher();
	void CalculAttack(int Adefense);

};