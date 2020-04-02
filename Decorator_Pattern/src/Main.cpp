
#include "Core/File_System.h"

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
	
	fs.SetShiftCharactersEnabled(false);
	fs.SetShiftPattern(FileSystem::ShiftPattern::INCREMENT);
	fs.SetLineEndingConversionEnabled(true);

	fs.WriteFile("Signatures.txt", "Hello\rWorld");
	std::string fileText = fs.ReadFile("Signatures.txt");
}