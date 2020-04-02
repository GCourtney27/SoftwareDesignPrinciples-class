#include "File_System.h"

#include "Time.h"

// Constructor, decide wether to clear the file when creating a new 
// FileSystem object or to preserve the files data. Can be decided 
// via an optional parameter in the constructor (Note: default value is true)
FileSystem::FileSystem(bool flushFileOnConstruct)
{
	if(flushFileOnConstruct)
		//FlushFile("Signatures.txt");

	m_Date = Time::Get().GetDate(Time::DAY | Time::MONTH | Time::YEAR);
}

FileSystem::~FileSystem()
{
}

// Read a file and return its contents as a string
std::string FileSystem::ReadFile(const std::string& file)
{
	std::string fileResult;
	std::string line;

	std::ifstream fileStream("output/" + file);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			if(m_ShiftCharacters)
				ShiftCharacters(line);
			fileResult += line + (m_ConveretLineEndings ? "\n" : "\r");
		}
		fileStream.close();
	}
	else {
		throw std::exception("Fialed to read from file. The file may not exist.");
	}
	
	return fileResult;
}

// Write to a file by providing file name you wish to write to and content you want
// to write to the file itself
bool FileSystem::WriteFile(const std::string& file, const std::string& content)
{
	std::ofstream fileStream;
	
	if (m_ShiftCharacters) {
		ShiftCharacters(const_cast<std::string&>(content));
		ShiftCharacters(m_Signature);
		ShiftCharacters(m_Date);
	}
	if (m_ConveretLineEndings)
		ConvertLineEndings(const_cast<std::string&>(content));

	fileStream.open("output/" + file, std::fstream::app);
	if (!(fileStream << content)) {
		throw std::exception("Fialed to write to file. The file may not exist.");
		fileStream.flush();
	}
	if (!(fileStream << (m_ConveretLineEndings ? "\n" : "\r") + m_Signature)) {
		throw std::exception("Fialed to write signature to file. The file may not exist.");
		fileStream.flush();
	}
	if (!(fileStream << m_Date)) {
		throw std::exception("Fialed to write date to file. The file may not exist.");
		fileStream.flush();
	}
	fileStream.close();

	return true;
}

// Clear a specified file making it blank
void FileSystem::FlushFile(std::string file)
{
	std::ofstream rawFile;
	rawFile.open("output/" + file, std::ofstream::out | std::ofstream::trunc);
	rawFile.close();
}

// Shift all character in a string in by either incrementing
// or decrementing. Uses member variabled to decide shifting 
// pattern or, to shift at all
void FileSystem::ShiftCharacters(std::string& str)
{
	for (unsigned int i = 0; i < str.length(); i++)	{
		if (str[i] == '\n' || str[i] == '\r')
			continue;
		if (m_ShiftPattern == ShiftPattern::INCREMENT) {
			str[i] = ++str[i];
		}
		else if(m_ShiftPattern == ShiftPattern::DECREMENT) {
			str[i] = --str[i];
		}
	}
}

void FileSystem::ConvertLineEndings(std::string& str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\r')
			str[i] = '\n';
	}
}

