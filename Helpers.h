#pragma once
#include "MyString.h"
#include "Person.h"
#include <fstream>

const char allowedSymbols[]{ '!','@','#','$','%','&','*' };

bool isLetter(char s);

bool isBigLetter(char s);
	

bool isSmallLetter(char s);


bool isDigit(char s);


bool isValidChar(char s);


bool isValidUsername(const MyString s);


bool isValidPassword(const MyString s);


bool isValidName(const MyString s);

bool isValidCarOrPhoneNumber(const MyString s);

unsigned getCharCountFromFile(std::ifstream& ifs, char ch);



