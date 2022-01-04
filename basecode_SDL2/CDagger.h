#pragma once
#include "CMelee.h"

class CDagger : public CMelee
{
protected:
	CDagger();

public:
	CDagger(std::string name, int damage, int critical, int bonus, int durability);
	virtual ~CDagger();


};