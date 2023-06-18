#pragma once
#include "Vector.hpp"
#include "SharedPtr.hpp"
#include "Driver.h"

class Driver;
class DriverCollection :public Collection
{
public:

	Vector<SharedPtr<Driver>> collection;

	void readCollectionFromFile(const char* fileName) override;
	void writeCollectionToFile(const char* fileName) override;
};

