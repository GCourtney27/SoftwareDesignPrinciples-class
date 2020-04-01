#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileSystem
{
public:
	FileSystem(bool flushFileOnConstruct = true);
	~FileSystem();

	std::string ReadFile(const std::string& file);
	bool WriteFile(const std::string& file, const std::string& content);
private:
	void FlushFile(std::string file);
private:

};
