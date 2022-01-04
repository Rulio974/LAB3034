#pragma once
#include "CWeapon.h"

class CRanged : public CWeapon
{
protected :
	int consumable;
	int distance;

	CRanged();

public :

	CRanged(std::string name, int damage, int critical, int bonus, int consumable, int distance);
	virtual ~CRanged();


};