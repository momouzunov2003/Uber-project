#include "Helpers.h"

bool isLetter(char s)
{
	return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}

bool isBigLetter(char s)
{
	return  (s >= 'A' && s <= 'Z');
}

bool isSmallLetter(char s)
{
	return (s >= 'a' && s <= 'z');
}

bool isDigit(char s)
{
	return (s >= '0' && s <= '9');
}

bool isValidChar(char s)
{
	for (int i = 0; i < sizeof(allowedSymbols) / sizeof(char); i++)
	{
		if (s != allowedSymbols[i])
		{
			return false;
		}
	}
	return true;
}

bool isValidUsername(const MyString s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isLetter(s[i]) && !isDigit(s[i]))
		{
			throw std::invalid_argument("Username can contain only letters and digits!");
		}
	}
	return true;
}

bool isValidPassword(const MyString s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isValidChar(s[i]) && !isLetter(s[i]) && !isDigit(s[i]))
		{
			throw std::invalid_argument("Password can contain only letters, digits and the symbols !,@,#,$,%,& !");
		}
	}
	return true;
}

bool isValidName(const MyString s)
{
	if (!isBigLetter(s[0]))
	{
		throw std::invalid_argument("Name must start with a big letter!");
	}

	for (int i = 1; i < s.length(); i++)
	{
		if (!isSmallLetter(s[i]))
		{
			throw std::invalid_argument("Name must contain a big letter only in the beggining!");
		}
	}
	return true;
}

bool isValidCarOrPhoneNumber(const MyString s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isDigit(s[i]))
		{
			throw std::invalid_argument("Car and phone numbers must conatin only digits!");
		}
	}
	return true;
}

unsigned getCharCountFromFile(std::ifstream& ifs, char ch)
{
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open())
		return 0;

	unsigned int count = 0;

	while (true)
	{
		char current = ifs.get();
		if (ifs.eof())
			break;

		if (current == ch)
			count++;
	}

	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}
