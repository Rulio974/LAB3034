#pragma once
#include "CWeapon.h"

class CRanged : public CWeapon
{
protected :
	int m_consumable;
	int m_distance;

	CRanged();

public :

	CRanged(std::string name, int damage, int critical, int bonus, int consumable, int distance);
	virtual ~CRanged();


};