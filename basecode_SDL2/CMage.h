#pragma once
#include "utils.h"

class CMage : public CCharacter
{
protected :

	int		m_mana;
	CMage();

public :
	
	CMage(std::string name, int health,
		CWeapon weapon, float dodge,
		int speed, int attack, int defense,
		int agility, int intelligence, int damage, int mana);

	~CMage();
	void CalculAttack(int Adefense);

	//TODO
	/*
	* Fonction régénération Mana
	* Fonction Soigne
	* Fonction Enchanter
	*/


};
