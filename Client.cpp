#include "Client.h"

const MyString& Client::getUsername() const
{
	return username;
}

const MyString& Client::getPassword() const
{
	return password;
}

const MyString& Client::getFirstName() const
{
	return firstName;
}

const MyString& Client::getLastName() const
{
	return lastName;
}

unsigned Client::getBallance()
{
	return ballance;
}

void Client::setUsername(const MyString s)
{
	// decided that usernames can contain only letters and digits

	try
	{
		isValidUsername(s);

	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Username can contain only letters and digits!" << std::endl;
		throw;
	}
	username = s;
}

void Client::setPassword(const MyString s)
{
	try
	{
		isValidPassword(s);

	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Password can contain only letters, digits and the symbols !,@,#,$,%,& !" << std::endl;
		throw;
	}
	password = s;
}

void Client::setFirstName(const MyString s)
{
	try
	{
		isValidName(s);

	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Password can contain only letters, digits and the symbols !,@,#,$,%,& !" << std::endl;
		throw;
	}
	firstName = s;
}

void Client::setLastName(const MyString s)
{
	try
	{
		isValidName(s);

	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Password can contain only letters, digits and the symbols !,@,#,$,%,& !" << std::endl;
		throw;
	}
	lastName = s;
}

void Client::addBallance(unsigned num)
{
	ballance += num;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Client::Client() :Client("", "", "S", "S") {}

Client::Client(MyString _username, MyString _password, MyString _firstName, MyString _lastName) :Person(Type::Client)
{
	setUsername(_username);
	setPassword(_password);
	setFirstName(_firstName);
	setLastName(_lastName);
	ballance = 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Client::registerClient(ClientCollection& cc)
{
	Client c;

	std::cout << "Enter username: " << std::endl;
	MyString _username;
	std::cin >> _username;

	try
	{
		c.setUsername(_username);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Invalid username!" << std::endl;
		throw;
	}

	std::cout << "Enter password: " << std::endl;
	MyString _password;
	std::cin >> _password;

	try
	{
		c.setPassword(_password);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Invalid password!" << std::endl;
		throw;
	}

	std::cout << "Enter first name: " << std::endl;
	MyString _firstName;
	std::cin >> _firstName;

	try
	{
		c.setFirstName(_firstName);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Invalid first name!" << std::endl;
		throw;
	}

	std::cout << "Enter last name: " << std::endl;
	MyString _lastName;
	std::cin >> _lastName;

	try
	{
		c.setLastName(_lastName);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Invalid last name!" << std::endl;
		throw;
	}

	cc.collection.pushBack(SharedPtr<Client>(new Client(c)));

}

Client& Client::login(ClientCollection& cc) const
{
	std::cout << "Please, enter a username: " << std::endl;

	MyString _username;

	std::cin >> _username;

	for (int i = 0; i < cc.collection.getSize(); i++)
	{
		if (_username == cc.collection[i]->getUsername())
		{
			std::cout << "Please, enter a password: " << std::endl;

			MyString _password;

			std::cin >> _password;

			if (_password == cc.collection[i]->getPassword())
			{
				return *cc.collection[i];
			}
			else
			{
				throw std::invalid_argument("Invalid password!");
			}
		}		
	}

	throw std::invalid_argument("Couldn't find a client with that username in the database!");
}

Person* Client::clone() const
{
	return new Client(*this);
}


