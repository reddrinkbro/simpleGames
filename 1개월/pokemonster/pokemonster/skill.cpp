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
		cout << "����� ��ų����Ʈ�� �����մϴ�. " << endl;
	}
	else
	{
		_curSkillPoint -= _usingSkillPoint;
	}
}
