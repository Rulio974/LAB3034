#pragma once

#include <string>
#include <iostream>

class CWeapon {
protected:
	std::string m_name;
	float m_critical;
	float m_bonus;

	

public:
	int m_damage;
	CWeapon();
	CWeapon(std::string name, int damage, float critical, float bonus);
	virtual ~CWeapon();

	virtual void Print();

};