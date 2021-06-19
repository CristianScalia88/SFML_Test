#pragma once
namespace poke 
{
	class File
	{
	public:
		static const string ReadAllText(const string& path);
		static const void WriteAllText(const string& path, const string& allText);
	};
}