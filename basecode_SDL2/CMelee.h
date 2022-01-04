#pragma once
#include "CWeapon.h"

class CMelee : public CWeapon
{
protected:
	int m_durability;
	CMelee();
	
public:
	CMelee(std::string name, int damage, int critical, int bonus, int durability);
	virtual ~CMelee();

	virtual void Print();
	//virtual int Broken();



};
