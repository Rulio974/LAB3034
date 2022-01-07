#pragma once
#include "CCharacter.h"
#include "utils.h"


class CRogue : public CCharacter
{
protected:
	float m_poison;
	
	CRogue();

public:

	CRogue(std::string type , std::string name, int health,
		CWeapon weapon, float dodge,
		int speed, int attack, int defense,
		int agility, int intelligence, int damage, float poison);

	virtual ~CRogue();
	void	CalculAttack(int Adefense);
	void	Action(int team, std::vector<CTeam> Teams);
	void ChooseWeapon(int team, std::vector <CWeapon> TabWeapons);

};