#pragma once
#include "CRanged.h"

class CBow : public CRanged
{
protected:
	CBow();

private:
	CBow(std::string name, int damage, int critical, int bonus, int durability);
	virtual ~CBow();

};