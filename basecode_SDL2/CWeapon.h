#pragma once

#include <string>
#include <iostream>

class CWeapon {

public:
	std::string m_name;
	float m_critical;
	float m_bonus;
	int m_damage;
	
	CWeapon();
	CWeapon(std::string name, int damage, float critical, float bonus);
	virtual ~CWeapon();

	virtual void Print();

};