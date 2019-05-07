#include "skill.h"



skill::skill()
{
}


skill::~skill()
{
}

void skill::showSkillPoint()
{
	cout << getName() << "\t " << _curSkillPoint << " / " << _maxSkillPoint << endl;
}
void skill::usingSkill()
{
	if (_curSkillPoint < _usingSkillPoint)
	{
		cout << "사용할 스킬포인트가 부족합니다. " << endl;
	}
	else
	{
		_curSkillPoint -= _usingSkillPoint;
	}
}
