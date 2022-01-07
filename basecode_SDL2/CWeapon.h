#pragma once

#include <string>
#include <iostream>

class CWeapon {

public:
	std::string m_name;
	float m_critical;
	float m_bonus;
	int m_damage;
	int m_durability;
	
	CWeapon();
	CWeapon(std::string name, int damage, float critical, float bonus, int durability);
	virtual ~CWeapon();

	virtual void Print();

};