#pragma once

#include <string>
#include <iostream>

class CWeapon {
protected:
	std::string m_name;
	int m_damage;
	float m_critical;
	float m_bonus;

	CWeapon();

public:
	CWeapon(std::string name, int damage, float critical, float bonus);
	virtual ~CWeapon();

	virtual void Print();

};