#include "Driver.h"

const MyString& Driver::getUsername() const
{
	return username;
}
const MyString& Driver::getPassword() const
{
	return password;
}

const MyString& Driver::getFirstName() const
{
	return firstName;
}

const MyString& Driver::getLastName() const
{
	return lastName;
}

const MyString& Driver::getCarNumber() const
{
	return carNumber;
}

const MyString& Driver::getPhoneNumber() const
{
	return phoneNumber;
}

const double Driver::getRating() const
{
	return rating/ratingCount;
}

const double Driver::getMoney() const
{
	return money;
}

const Address& Driver::getAdddress() const
{
	return driverAddress;
}

void Driver::setUsername(const MyString s)
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

void Driver::setPassword(const MyString s)
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

void Driver::setFirstName(const MyString s)
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

void Driver::setLastName(const MyString s)
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

void Driver::setCarNumber(const MyString s)
{
	try
	{
		isValidCarOrPhoneNumber(s);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Car or phone numbers must conatin only digits!" << std::endl;
		throw;
	}

	carNumber = s;
}

void Driver::setPhoneNumber(const MyString s)
{
	try
	{
		isValidCarOrPhoneNumber(s);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Car or phone numbers must conatin only digits!" << std::endl;
		throw;
	}

	phoneNumber = s;
}

void Driver::setRating(short num)
{
	if (num >= 1 && num <= 5)
	{
		ratingCount++;
		rating += num;
	}
	else
		throw std::invalid_argument("Rating cannot be less than 1 or more than 5!");
}

void Driver::setAddress(const Address& add)
{
	driverAddress = add;
}

void Driver::changeAddress(const Address& add)
{
	setAddress(add);
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Driver::Driver() :Driver("", "", "S", "S", "", "") {}

Driver::Driver(MyString _username, MyString _password, MyString _firstName, MyString _lastName, MyString _carNumber, MyString _phoneNumber) :Person(Type::Driver)
{
	setUsername(_username);
	setPassword(_password);
	setFirstName(_firstName);
	setLastName(_lastName);
	setCarNumber(_carNumber);
	setPhoneNumber(_phoneNumber);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Driver::registerDriver(DriverCollection& d)
{
	Driver c;

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

	std::cout << "Enter car number: " << std::endl;
	MyString _carNumber;
	std::cin >> _carNumber;

	try
	{
		c.setCarNumber(_carNumber);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Invalid car number!" << std::endl;
		throw;
	}

	std::cout << "Enter phone number: " << std::endl;
	MyString _phoneNumber;
	std::cin >> _phoneNumber;

	try
	{
		c.setPhoneNumber(_phoneNumber);
	}
	catch (const std::invalid_argument& exc)
	{
		std::cout << "Invalid phone number!" << std::endl;
		throw;
	}

	d.collection.pushBack(SharedPtr<Driver>(new Driver(c)));
}


Driver& Driver::login(DriverCollection& d) const
{
	std::cout << "Please, enter a username: " << std::endl;

	MyString _username;

	std::cin >> _username;

	for (int i = 0; i < d.collection.getSize(); i++)
	{
		if (_username == d.collection[i]->getUsername())
		{
			std::cout << "Please, enter a password: " << std::endl;

			MyString _password;

			std::cin >> _password;

			if (_password == d.collection[i]->getPassword())
			{
				return *d.collection[i];
			}
			else
			{
				throw std::invalid_argument("Invalid password!");
			}
		}
	}

	throw std::invalid_argument("Couldn't find a driver with that username in the database!");
}

Person* Driver::clone() const
{
	return new Driver(*this);
}


