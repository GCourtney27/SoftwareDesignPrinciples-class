#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileSystem
{
public:
	enum class ShiftPattern
	{
		INCREMENT = 1 << 1,
		DECREMENT = 1 << 2
	};

public:
	FileSystem(bool flushFileOnConstruct = true);
	~FileSystem();

	std::string ReadFile(const std::string& file);
	bool WriteFile(const std::string& file, const std::string& content);
	void ShiftCharacters(std::string& str);
	void ConvertLineEndings(std::string& str);
	
	void SetShiftCharactersEnabled(const bool& enabled) { m_ShiftCharacters = enabled; }
	void SetShiftPattern(const FileSystem::ShiftPattern& pattern) { m_ShiftPattern = pattern; }
	void SetLineEndingConversionEnabled(const bool& enabled) { m_ConveretLineEndings = enabled; }

private:
	void FlushFile(std::string file);
private:
	ShiftPattern m_ShiftPattern = ShiftPattern::INCREMENT;
	bool m_ShiftCharacters = false;
	bool m_ConveretLineEndings = false;
	std::string m_Signature = "-Garrett Courtney, ";
	std::string m_Date = "";
};
