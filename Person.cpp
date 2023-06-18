#include "Person.h"

const Type Person::getType() const
{
	return type;
}

void Person::setType(Type _type)
{
	type = _type;
}

bool Person::logout()
{
	return false;
}

//TODO: class Order