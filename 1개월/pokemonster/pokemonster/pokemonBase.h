#pragma once
#include "skill.h"
#include "monsterBall.h"
#include <map>
#include <time.h>

class pokemonBase
{
private:
	char *_name; //포켓몬 이름
	int _curHp; //포켓몬 현재 체력
	int _maxHp; //포켓몬 총 체력
	int _curexp; //현재 경험치
	int _maxexp; //경험치(경험치가 최대가 되면 진화를 할수있다.)
	int _money; // 현재 포켓몬이 가지고 있는 돈
	bool _isCatchPokemon; //포켓몬을 잡을수 있는 상태인지
	bool _isRevolution; //포켓몬이 진화한 포켓몬인지
	bool _isFighting; //싸우는지 안싸우는지
	
public:
	map<int, skill*> _skillMap; //스킬에 대한 맵
	map<int, skill*>::iterator mapIter; //이터레이터
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

