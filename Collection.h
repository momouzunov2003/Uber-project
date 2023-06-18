#pragma once
#include<fstream>

class Collection
{
public:

	virtual void readCollectionFromFile(const char* fileName)=0;
	virtual void writeCollectionToFile(const char* fileName)=0;

	virtual ~Collection() = default;
};
