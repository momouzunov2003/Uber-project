//WORKING FUNCTIONS:
//register client
//register driver
//login client
//login driver

#include <iostream>
#include <sstream>
#include "Address.h"
#include "Client.h"
#include "ClientCollection.h"
#include "Driver.h"
#include "DriverCollection.h"
#include "Helpers.h"
#include "MyString.h"
#include "Order.h"
#include "Person.h"

const char* CLIENT_FILE = "Clients.txt";
const char* DRIVER_FILE = "Drivers.txt";
const char* ORDERS_FILE = "Orders.txt";
const int DEFAULT_STRING_LENGTH = 1024;

int main()
{
	ClientCollection clientCollection;
	DriverCollection driverCollection;
	OrdersCollection ordersCollection;

	try
	{
		clientCollection.readCollectionFromFile(CLIENT_FILE);
	}
	catch (std::runtime_error& exc)
	{
		std::cout << "Client file empty!" << std::endl;
	}

	try
	{
		driverCollection.readCollectionFromFile(DRIVER_FILE);
	}
	catch (std::runtime_error& exc)
	{
		std::cout << "Driver file empty!" << std::endl;
	}

	try
	{
		ordersCollection.readCollectionFromFile(ORDERS_FILE);
	}
	catch (std::bad_alloc& exc)
	{
		std::cout << "Orders file empty!" << std::endl;
	}
	

	while (true)
	{
		std::cout << "\033[2J\033[1;1H";
		
		
		std::cout << "Enter a command: " << std::endl;
		char line[DEFAULT_STRING_LENGTH];
		std::cin.getline(line, 1024);
		std::stringstream ss(line);
		char command[1024];
		ss >> command;

		if (strcmp(command,"register")==0)
		{
			char person[1024];
			ss >> person;
			if (strcmp(person,"client")==0)
			{
				std::cout << "\033[2J\033[1;1H"; //clear console
				
				Client client;
				try
				{
					client.registerClient(clientCollection);
					
				}
				catch (std::invalid_argument& exc)
				{
					std::cout << exc.what()<<std::endl;
				}
				
			}
			else if (strcmp(person, "driver") == 0)
			{
				Driver driver;
				try
				{
					driver.registerDriver(driverCollection);

				}
				catch (std::invalid_argument& exc)
				{
					std::cout << exc.what() << std::endl;
				}
			}
			else
			{
				std::cout << "Wrong type of user! Please try again!"<<std::endl;
				continue;
			}
		}
		else if (strcmp(command, "login") == 0)
		{
			char person[1024];
			ss >> person;
			if (strcmp(person, "client") == 0)
			{
				Client client;
				try
				{
					client.login(clientCollection);
				}
				catch (std::invalid_argument& exc)
				{
					std::cout << "Error while logging in client!" << std::endl;
				}

				std::cout << "\033[2J\033[1;1H";

				std::cout << "Enter client commands: " << std::endl;
				char line[DEFAULT_STRING_LENGTH];
				std::cin.ignore();
				std::cin.getline(line, 1024);
				std::stringstream ss(line);
				char command[1024];

			}
			else if (strcmp(person, "driver") == 0)
			{
				Driver driver;
				try
				{
					driver.login(driverCollection);
				}
				catch (std::invalid_argument& exc)
				{
					std::cout << "Error while logging in driver!" << std::endl;
				}

				std::cout << "\033[2J\033[1;1H";

				std::cout << "Enter driver commands: " << std::endl;

				char line[DEFAULT_STRING_LENGTH];
				std::cin.ignore();
				std::cin.getline(line, 1024);
				std::stringstream ss(line);
				char command[1024];
			}

		}
		else if (strcmp(command, "logout") == 0)
		{
			Client s;
			if (!s.logout())
			{
				continue;
			}
		}
		clientCollection.writeCollectionToFile(CLIENT_FILE);
		driverCollection.writeCollectionToFile(DRIVER_FILE);
		ordersCollection.writeCollectionToFile(ORDERS_FILE);
	}
}
	