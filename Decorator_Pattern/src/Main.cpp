
#include "Core/File_System.h"

int main()
{
	FileSystem fs;
	fs.WriteFile("Signatures.txt", "Hello\nWorld");
	//std::string s = fs.ReadFile("Signatures.txt");
}