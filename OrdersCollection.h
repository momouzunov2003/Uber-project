#pragma once
#include "Collection.h"
#include "Order.h"
#include "SharedPtr.hpp"
#include "Vector.hpp"
#include <fstream>

class Order;
class OrdersCollection :public Collection
{
public:

	Vector<SharedPtr<Order>> collection;

	void readCollectionFromFile(const char* fileName) override;
	void writeCollectionToFile(const char* fileName) override;
};
