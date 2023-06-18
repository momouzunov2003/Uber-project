#pragma once
#include "Collection.h"
#include "Client.h"
#include "SharedPtr.hpp"
#include "Vector.hpp"
#include <fstream>

class Client;
class ClientCollection:public Collection
{
public:

	Vector<SharedPtr<Client>> collection;

	void readCollectionFromFile(const char* fileName) override;
	void writeCollectionToFile(const char* fileName) override;
};
