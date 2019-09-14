#pragma once
#include <stdlib.h>

class player
{
private:
	char *_name; //�̸�
	int _level; //����
	float _atk; //���ݷ�
	float _def; //����
	float _curHp; //���� ü��
	float _maxHp; //�� ü��
	int _curMp; //���� ����
	int _maxMp; // �� ����
public:
	char *getName() { return _name; }
	//���� ���� ����
	int getLevel() { return _level; }
	void setLevel(int level) { _level = level; }
	//���ݷ� ���� ����
	float getAtk() { return _atk; }
	void setAtk(float atk) { _atk = atk; }
	//���� ���� ����
	float getDef() { return _def; }
	void setDef(float def) { _def = def; }
	//����ü�� ���� ����
	float getCurHp() { return _curHp; }
	void setCurHp(float curHp) { _curHp = curHp; }
	//��ü�� ���� ����
	float getMaxHp() { return _maxHp; }
	void setMaxHp(float maxHp) { _maxHp = maxHp; }
	//���縶�� ���� ����
	int getCurMp() { return _curMp; }
	void setCurMp(int curMp) { _curMp = curMp; }
	//�� ���� ���� ����
	int getMaxMp() { return _maxMp; }
	void setMaxMp(int maxMp) { _maxMp = maxMp; }
	player();
	~player();
};

