#pragma once
#include <fstream>
#include "MyString.h"
#include "Collection.h"
#include <cmath>
enum class Type
{
	Client,
	Driver
};

class Person
{
protected:

	Type type;

public:

	Person(Type t) :type(t) {};

	const Type getType() const;
	void setType(Type _type);
	virtual Person* clone() const=0;

	bool logout();

	virtual ~Person() = default;

};


