#include "File_System.h"

#include "Time.h"

FileSystem::FileSystem(bool flushFileOnConstruct)
{
	if(flushFileOnConstruct)
		FlushFile("Signatures.txt");
}

FileSystem::~FileSystem()
{
}

std::string FileSystem::ReadFile(const std::string& file)
{
	std::string fileResult;
	std::string line;
	
	std::ifstream fileStream("output/" + file);
	if (fileStream.is_open()) {
		while (std::getline(fileStream, line)) {
			fileResult += line + "\n";
		}
		fileStream.close();
	}
	else {
		throw std::exception("Fialed to read from file. The file may not exist.");
	}
	
	return fileResult;
}

bool FileSystem::WriteFile(const std::string& file, const std::string& content)
{
	std::ofstream fileStream;

	fileStream.open("output/" + file, std::fstream::app);
	if (!(fileStream << content)) {
		throw std::exception("Fialed to write to file. The file may not exist.");
		fileStream.flush();
	}
	if (!(fileStream << "\n-Garrett Courtney, ")) {
		throw std::exception("Fialed to write signature to file. The file may not exist.");
		fileStream.flush();
	}
	if (!(fileStream << Time::Get().GetDate(Time::DAY | Time::MONTH | Time::YEAR))) {
		throw std::exception("Fialed to write date to file. The file may not exist.");
		fileStream.flush();
	}
	fileStream.close();

	return true;
}

void FileSystem::FlushFile(std::string file)
{
	std::ofstream rawFile;
	rawFile.open("output/" + file, std::ofstream::out | std::ofstream::trunc);
	rawFile.close();
}
