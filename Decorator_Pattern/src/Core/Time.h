#pragma once

#include <string>

class Time
{
public:
	enum eDate
	{
		DAY		= 1 << 1,
		MONTH	= 1 << 2,
		YEAR	= 1 << 3
	};

	Time();
	~Time();
	static Time& Get() { return *s_Instance; }

	std::string GetDate(int category);

private:
	static Time* s_Instance;
};

