#pragma once
#include "CCharacter.h"
#include "utils.h"


class CArcher : public CCharacter
{
protected :
	CArcher();

public :
	CArcher(std::string type, std::string name, int health,
		CWeapon weapon, float dodge,
		int speed, int attack, int defense,
		int agility, int m_damage, int intelligence);

	virtual ~CArcher();
	void CalculAttack(int Adefense);
	void Action(int team, std::vector<CTeam>Teams);
	void ChooseWeapon(int team, std::vector <CWeapon> TabWeapons);

};