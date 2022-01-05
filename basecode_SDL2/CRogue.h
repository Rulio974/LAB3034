#pragma once
#include "utils.h"

class CRogue : public CCharacter
{
protected:
	float m_poison;
	
	CRogue();

public:

	CRogue(std::string name, int health,
		CWeapon weapon, float dodge,
		int speed, int attack, int defense,
		int agility, int intelligence, int damage, float poison);

	~CRogue();
	void CalculAttack(int Adefense);

};