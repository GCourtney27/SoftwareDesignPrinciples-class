
#include "Core/File_System.h"

#define LOG(x) std::cout << x << "\n"

/*
	Written response
	--------------
	When wrapping decorator 1 in decorator 2, all characters in the string
	will be shifted up or down depending on the specified flags. It does this 
	by shifting their ASCII character values up or down.

*/

int main()
{
	FileSystem fs;
	
	fs.SetShiftCharactersEnabled(true);
	fs.SetShiftPattern(FileSystem::ShiftPattern::DECREMENT);
	fs.SetLineEndingConversionEnabled(true);

	fs.WriteFile("Signatures.txt", "Hello\rWorld");
	std::string fileText = fs.ReadFile("Signatures.txt");
	LOG(fileText);
}