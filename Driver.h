#pragma once
#include "Person.h"
#include "Helpers.h"
#include <sstream>
#include "DriverCollection.h"
#include "Order.h"
#include "Address.h"


class DriverCollection;

class Driver :public Person
{

protected:

	MyString username;
	MyString password;
	MyString firstName;
	MyString lastName;
	MyString carNumber;
	MyString phoneNumber;

	double rating=0;
	int ratingCount=0;
	double money=0;

	Address driverAddress;

public:

	const MyString& getUsername() const;
	const MyString& getPassword() const;
	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getCarNumber() const;
	const MyString& getPhoneNumber() const;
	const double getRating() const;
	const double getMoney() const;
	const Address& getAdddress() const;


	void setUsername(const MyString s);
	void setPassword(const MyString s);
	void setFirstName(const MyString s);
	void setLastName(const MyString s);
	void setCarNumber(const MyString s);
	void setPhoneNumber(const MyString s);
	void setRating(short num);
	void setAddress(const Address& add);

	void changeAddress(const Address& add);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Driver();
	Driver(MyString _username, MyString _password, MyString _firstName, MyString _lastName, MyString _carNumber, MyString _phoneNumber);
	~Driver() = default;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	void registerDriver(DriverCollection& d);
	Driver& login(DriverCollection& d) const;
	Person* clone() const override;
};