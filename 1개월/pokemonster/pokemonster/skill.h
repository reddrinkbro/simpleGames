#pragma once
#include <iostream>
using namespace std;

class skill
{
	char* _name;
	int _damage;
	int _usingSkillPoint; // ��ų�� ����ϱ� ���� ��ų����Ʈ
	int _curSkillPoint; //���� ������ �ִ� ��ų����Ʈ
	int _maxSkillPoint; //�� ������ �ִ� ��ų����Ʈ

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
	void usingSkill(); //��ų ��� ����Ȯ��
	skill();
	~skill();
};

