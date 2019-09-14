#pragma once

class skillBase
{
private:
	char* _name;
	int _damage;
public:
	char* getName() { return _name; }
	int getDamage() { return _damage; }

	void setName(char* name) { _name = name; }
	void setDamage(int damage) { _damage = damage; }

	skillBase();
	~skillBase();
};

