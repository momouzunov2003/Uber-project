#pragma once
#include "Client.h"
#include "Driver.h"
#include "Address.h"
#include "OrdersCollection.h"

class OrdersCollection;
class Client;
class Driver;
namespace
{
	const char* ID_FILE_NAME = "ID.txt";
}


enum class OrderState
{
	Accepted,
	Canceled,
	Waiting
};


class Order
{
	unsigned id;
	Address start;
	Address dest;
	Client* client;
	Driver* driver;
	size_t minutes;
	OrderState state;
	size_t cost;
	short passengers;
	MyString description;

	double calculateDistance() const;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

public:
	Order() = default;
	Order(const Address& _start, const Address& _dest, const short _passengers);
	Order(const Address& _start, const Address& _dest, const MyString description, const short _passengers);
	Order(OrderState state, const Address& _start, const Address& _dest, short _passengers, size_t _minutes, size_t _cost);

	~Order();

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	void setId();
	void setStart(const MyString name, int x, int y, const MyString note);
	void setStart(const Address& address);
	void setDest(const MyString name, int x, int y, const MyString note);
	void setDest(const Address& address);
	void setClient(Client* client);
	void setDriver(Driver* driver);
	void setMinutes(unsigned _minutes);
	void setOrderState(OrderState _state);
	void setCost(size_t _cost);
	void setPassengers(short _passengers);
	void setDescription(const MyString _desc);
	void setIdFromFile(unsigned n);

	unsigned getId();
	const Address& getStart();
	const Address& getDest();
	Client* getClient();
	Driver* getDriver();
	unsigned getMinutes();
	OrderState getOrderState();
	size_t getCost();
	short getPassengers();
	const MyString getDescription();

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	void rateDriver(short num);
	//void addOrderToCollection(OrdersCollection& cc);

};
