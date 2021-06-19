#include "pch.h"
#include "File.h"

const string poke::File::ReadAllText(const string& path)
{
	std::ifstream inFile;
	inFile.open(path); //open the input file
	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file
	inFile.close();
	return str;
}

const void poke::File::WriteAllText(const string & path, const string& allText)
{
	std::ofstream ouFile;
	ouFile.open(path, ios::trunc);
	if (ouFile.is_open()) 
	{
		ouFile << allText;
	}
	ouFile.close();
}
//const string* poke::File::ReadAllLines(const string& path)
//{
//	string * s = new string[];
//	std::ifstream file(path);
//	int lineIndex = 0;
//	if (file.is_open()) {
//		std::string line;
//		while (std::getline(file, line)) {
//			s[lineIndex] = line;
//			lineIndex++;
//		}
//		file.close();
//	}
//	return s;
//}
