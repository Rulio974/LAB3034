#pragma once
#include "CCharacter.h"
#include "utils.h"
#include <vector>
#include <string>

struct sTeam {

	int m_num;
	std::string s_name;
	CCharacter* s_perso1;
	CCharacter* s_perso2;
	CCharacter* s_perso3;

};

class CTeam {

public :

	int m_num;
	std::string m_name;
	CCharacter *m_perso1;
	CCharacter *m_perso2;
	CCharacter *m_perso3;

	CTeam();
	virtual ~CTeam();

	CTeam(int num, std::string name,
		CCharacter *perso1,
		CCharacter *perso2,
		CCharacter *perso3);

	CTeam* CreateTeam(int num, std::vector<CCharacter*> TabCaracters, std::vector<CWeapon> TabWeapons);
	void Print();
};