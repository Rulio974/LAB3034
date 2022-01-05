#pragma once
#include "CRanged.h"

class CStaff : public CRanged
{
protected:
	CStaff();

public:
	CStaff(std::string name, int damage, int critical, int bonus, int consumable, int distance);
	virtual ~CStaff();

};
