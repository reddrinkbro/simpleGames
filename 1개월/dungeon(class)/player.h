#pragma once
#include <stdlib.h>

class player
{
private:
	char *_name; //이름
	int _level; //레벨
	float _atk; //공격력
	float _def; //방어력
	float _curHp; //현재 체력
	float _maxHp; //총 체력
	int _curMp; //현재 마나
	int _maxMp; // 총 마나
public:
	char *getName() { return _name; }
	//레벨 게터 세터
	int getLevel() { return _level; }
	void setLevel(int level) { _level = level; }
	//공격력 게터 세터
	float getAtk() { return _atk; }
	void setAtk(float atk) { _atk = atk; }
	//방어력 게터 세터
	float getDef() { return _def; }
	void setDef(float def) { _def = def; }
	//현재체력 게터 세터
	float getCurHp() { return _curHp; }
	void setCurHp(float curHp) { _curHp = curHp; }
	//총체력 게터 세터
	float getMaxHp() { return _maxHp; }
	void setMaxHp(float maxHp) { _maxHp = maxHp; }
	//현재마나 게터 세터
	int getCurMp() { return _curMp; }
	void setCurMp(int curMp) { _curMp = curMp; }
	//총 마나 게터 세터
	int getMaxMp() { return _maxMp; }
	void setMaxMp(int maxMp) { _maxMp = maxMp; }
	player();
	~player();
};

