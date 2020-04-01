#include "Time.h"

#include <ctime>

Time* Time::s_Instance = nullptr;

Time::Time()
{
	s_Instance = this;
}

Time::~Time()
{
}

std::string Time::GetDate(int category)
{
	std::string date;
	time_t now = std::time(0);
	tm* pLocalTime = localtime(&now);

	uint32_t day = pLocalTime->tm_mday;
	uint32_t month = pLocalTime->tm_mon;
	uint32_t year = 1900 + pLocalTime->tm_year;

	if (category & eDate::DAY)
	{
		if (date == "")
			date += std::to_string(day);
		else
			date += "-" + std::to_string(day);
	}

	if (category & eDate::MONTH)
	{
		if(date == "")
			date += std::to_string(month);
		else
			date += "-" + std::to_string(month);
	}

	if (category & eDate::YEAR)
	{
		if (date == "")
			date += std::to_string(year);
		else
			date += "-" + std::to_string(year);
	}

	return date;
}
