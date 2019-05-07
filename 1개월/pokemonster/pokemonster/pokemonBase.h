#pragma once
#include "skill.h"
#include "monsterBall.h"
#include <map>
#include <time.h>

class pokemonBase
{
private:
	char *_name; //���ϸ� �̸�
	int _curHp; //���ϸ� ���� ü��
	int _maxHp; //���ϸ� �� ü��
	int _curexp; //���� ����ġ
	int _maxexp; //����ġ(����ġ�� �ִ밡 �Ǹ� ��ȭ�� �Ҽ��ִ�.)
	int _money; // ���� ���ϸ��� ������ �ִ� ��
	bool _isCatchPokemon; //���ϸ��� ������ �ִ� ��������
	bool _isRevolution; //���ϸ��� ��ȭ�� ���ϸ�����
	bool _isFighting; //�ο���� �Ƚο����
	
public:
	map<int, skill*> _skillMap; //��ų�� ���� ��
	map<int, skill*>::iterator mapIter; //���ͷ�����
	char* getName() { return _name; }
	int getCurHealthPoint() { return _curHp; }
	int getMaxHealthPoint() { return _maxHp; }
	int getCurExperiencePoint() { return _curexp; }
	int getMaxExperiencePoint() { return _maxexp; }
	int getMoney() { return _money; }
	bool getIsCatchPokemon() { return _isCatchPokemon; }
	bool getIsRevolution() { return _isRevolution; }
	bool getIsFighting() { return _isFighting; }
	
	void setName(char* name) { _name = name; }
	void setCurHealthPoint(int curHp) { _curHp = curHp; }
	void setMaxHealthPoint(int maxHp) { _maxHp = maxHp; }
	void setCurExperiencePoint(int curexp) { _curexp = curexp; }
	void setMaxExperiencePoint(int maxexp) { _maxexp= maxexp; }
	void setMoney(int money) { _money = money; }
	void setIsCatchPokemon(bool isCatchPokemon) { _isCatchPokemon = isCatchPokemon; }
	void setIsRevolution(bool isRevolution) { _isRevolution = isRevolution; }
	void setIsFighting(bool isFighting) { _isFighting = isFighting; }

	map<int, skill*> getSkillMap() { return _skillMap; }

	virtual void showImage(){}
	
	pokemonBase();
	~pokemonBase();
};

