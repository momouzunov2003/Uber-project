#pragma once
#include "Person.h"
#include "MyString.h"
#include "Helpers.h"
#include "ClientCollection.h"
#include <sstream>

class ClientCollection;
class Client :public Person
{

protected:

	MyString username;
	MyString password;
	MyString firstName;
	MyString lastName;

	unsigned ballance;

public:

	const MyString& getUsername() const;
	const MyString& getPassword() const;
	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	unsigned getBallance();

	void setUsername(const MyString s);
	void setPassword(const MyString s);
	void setFirstName(const MyString s);
	void setLastName(const MyString s);
	void addBallance(unsigned num);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Client();
	Client(MyString _username, MyString _password, MyString _firstName, MyString _lastName);
	~Client() = default;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	void registerClient(ClientCollection& cc);
	Client& login(ClientCollection& cc) const;
	Person* clone() const override;

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




};