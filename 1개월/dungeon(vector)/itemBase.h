#pragma once
class itemBase
{
private:
	char* _name;
public:
	char* getName() { return _name; }
	void setName(char* name) { _name = name; }
	itemBase();
	~itemBase();
};

