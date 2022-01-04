#pragma once
#include "CMelee.h"

class CSword : public CMelee
{
protected:
	CSword();

public:
	CSword(std::string name, int damage, int critical, int bonus, int durability);
	virtual ~CSword();


};