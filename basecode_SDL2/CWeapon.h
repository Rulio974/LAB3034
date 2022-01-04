#include <string>
#include <iostream>

class CWeapon {
protected:
	std::string name;
	int damage;
	int critical;
	float bonus;

public:
	CWeapon(std::string name, int damage, int critical, int bonus);
	virtual ~CWeapon();

	virtual void Print();

};