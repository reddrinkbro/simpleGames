#pragma once
#include <iostream>
using namespace std;

class skill
{
	char* _name;
	int _damage;
	int _usingSkillPoint; // 스킬을 사용하기 위한 스킬포인트
	int _curSkillPoint; //현재 가지고 있는 스킬포인트
	int _maxSkillPoint; //총 가지고 있는 스킬포인트

public:
	char* getName() { return _name; }
	int getDamage() { return _damage; }
	int getUsingSkillPoint() { return _usingSkillPoint; }
	int getCurSkillPoint() { return _curSkillPoint; }
	int getMaxSkillPoint() { return _maxSkillPoint; }

	void setName(char* name) { _name = name; }
	void setDamage(int damage) { _damage = damage; }
	void setUsingSkillPoint(int usingSkillPoint) { _usingSkillPoint = usingSkillPoint; }
	void setCurSkillPoint(int curSkillPoint) { _curSkillPoint = curSkillPoint; }
	void setMaxSkillPoint(int maxSkillPoint) { _maxSkillPoint = maxSkillPoint; }

	void showSkillPoint();
	void usingSkill(); //스킬 사용 여부확인
	skill();
	~skill();
};

