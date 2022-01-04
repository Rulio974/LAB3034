#pragma once
#include "CRanged.h"

CRanged::CRanged()
{

	std::string name;
	int damage; 
	int critical; 
	int bonus; 
	int consumable; 
	int distance;

}

CRanged::CRanged(std::string name, int damage, int critical, int bonus, int consumable, int distance)
{

	std::string name	= name;
	int damage			= damage;
	int critical		= critical;
	int bonus			= bonus;
	int consumable		= consumable;
	int distance		= distance;

}

CRanged::~CRanged()
{

}