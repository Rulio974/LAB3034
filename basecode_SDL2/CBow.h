#pragma once
#include "CRanged.h"

class CBow : public CRanged
{
protected:
	CBow();

public:
	CBow(std::string name, int damage, int critical, int bonus, int consumable, int distance);
	virtual ~CBow();

};
