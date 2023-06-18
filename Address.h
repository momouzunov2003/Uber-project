#pragma once
#include "MyString.h"

struct Address
{
	MyString name;
	int x;
	int y;
	MyString note;

	Address() :Address("", 0, 0, "") {};
	Address(const MyString _name, int _x, int _y, const MyString _note);
};