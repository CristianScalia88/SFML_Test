#include "pch.h"
#include "File.h"

const char* File::ReadAllText(string path)
{
	std::ifstream inFile;
	inFile.open(path); //open the input file
	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file
	inFile.close();
	return str.c_str();
}
