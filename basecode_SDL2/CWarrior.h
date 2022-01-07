#pragma once
#include "CCharacter.h"
#include "utils.h"

class CWarrior : public CCharacter
{
public :
	float	m_damage;
	float	m_parade;
	CWarrior();

			CWarrior(std::string type, std::string name, int health,
				CWeapon weapon, float dodge,
				int speed, int attack, int defense,
				int agility, int intelligence, int damage, int parade);

	virtual	~CWarrior();
	
	//void	Hurler();
	void	Action(int team, std::vector<CTeam>Teams);
	void    Reparer(int team, std::vector<CTeam>Teams);
	void	CalculAttack(int Adefense);
	void ChooseWeapon(int team, std::vector <CWeapon> TabWeapons);
	void Attack(int team, std::vector<CTeam>Teams);


};