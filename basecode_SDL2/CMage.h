#pragma once
#include "CCharacter.h"
#include "utils.h"

class CMage : public CCharacter
{
protected :

	int		m_mana;
	CMage();

public :
	
	CMage(std::string type, std::string name, int health,
		CWeapon weapon, float dodge,
		int speed, int attack, int defense,
		int agility, int intelligence, int damage, int mana);

	virtual ~CMage();
	void CalculAttack(int Adefense);
	void Action(int team,  std::vector<CTeam> Teams);
	void ChooseWeapon(int team, std::vector <CWeapon> TabWeapons);

	

	//TODO
	/*
	* Fonction régénération Mana
	* Fonction Soigne
	* Fonction Enchanter
	*/


};
